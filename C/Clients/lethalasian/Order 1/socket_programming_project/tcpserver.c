#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_PENDING 25
#define DEFAULT_IP_ADDRESS "127.0.0.1"

void handle_client(int client_socket) {
    // Receive the client's initial HELLO x message
    char client_hello[100];
    int bytes_received = recv(client_socket, client_hello, sizeof(client_hello), 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the server\n");
        close(client_socket);
        return;
    }

    client_hello[bytes_received] = '\0';
    int client_seq_number;
    sscanf(client_hello, "HELLO %d", &client_seq_number);
    printf("%s\n", client_hello);

    // Send the response HELLO y message to the client
    int server_seq_number = client_seq_number + 1;
    char server_hello[100];
    snprintf(server_hello, sizeof(server_hello), "HELLO %d", server_seq_number);
    send(client_socket, server_hello, strlen(server_hello), 0);

    // Receive the client's response HELLO z message
    char client_response[100];
    bytes_received =  recv(client_socket, client_response, sizeof(client_response), 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the server\n");
        close(client_socket);
        return;
    }

    client_response[bytes_received] = '\0';

    int client_response_seq_number;
    sscanf(client_response, "HELLO %d", &client_response_seq_number);
    printf("%s\n", client_response);

    // Check if the received sequence number is as expected
    if (client_response_seq_number != server_seq_number + 1) {
        fprintf(stderr, "ERROR: Unexpected sequence number from client\n");
        close(client_socket);
        return;
    }

    // Close the connection with the client
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: [server_file_name]  <port>  \n");
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    // Create the socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("simplex-talk: socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(DEFAULT_IP_ADDRESS);
    server_addr.sin_port = htons(port);

    // Bind the socket to the specified address and port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("simplex-talk: bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, MAX_PENDING) == -1) {
        perror("simplex-talk: listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }


    // Enter the loop to accept new connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        // Accept a new connection (this call will block until a client connects)
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("simplex-talk: accept");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        // Handle the new client connection
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);
    printf("Server closed.\n");

    return 0;
}
