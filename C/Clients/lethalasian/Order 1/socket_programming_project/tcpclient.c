#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

void handle_error(const char* error_msg) {
    fprintf(stderr, "ERROR: %s\n", error_msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port> <initial_seq_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);
    int initial_seq_number = atoi(argv[3]);

    // Create the socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid server IP address");
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Send the initial HELLO x message to the server
    char client_hello[100];
    snprintf(client_hello, sizeof(client_hello), "HELLO %d", initial_seq_number);
    send(client_socket, client_hello, strlen(client_hello), 0);

    // Receive the response HELLO y message from the server
    char server_hello[100];
    int bytes_received = recv(client_socket, server_hello, sizeof(server_hello), 0);
    if (bytes_received == -1) {
        handle_error("Error in receiving data from the server");
    }

    server_hello[bytes_received] = '\0';

    int server_seq_number;
    sscanf(server_hello, "HELLO %d", &server_seq_number);
    printf("%s\n", server_hello);

    // Check if the received sequence number is as expected
    if (server_seq_number != initial_seq_number + 1) {
        handle_error("Unexpected sequence number from server");
    }

    // Send the response HELLO z message to the server
    int client_response_seq_number = server_seq_number + 1;
    char client_response[100];
    snprintf(client_response, sizeof(client_response), "HELLO %d", client_response_seq_number);
    send(client_socket, client_response, strlen(client_response), 0);
    // Close the connection with the server
    close(client_socket);

    return 0;
}
