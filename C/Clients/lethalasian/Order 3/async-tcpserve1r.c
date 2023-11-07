#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_PENDING 100
#define DEFAULT_IP_ADDRESS "127.0.0.1"

typedef enum CLIENT_STATE_  {NOT_CONNECTED, RECEIVED_FIRST_HELLO} CLIENT_STATE;

typedef struct client_state_{
    int socket;
    int seq_number;
    CLIENT_STATE current_state;
} client_state;


void handle_client(client_state * client_socket_state) {
    // Receive the client's initial HELLO x message
    char client_hello[100];
    int client_socket = client_socket_state->socket;
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
    fflush(stdout);

    // Send the response HELLO y message to the client
    int server_seq_number = client_seq_number + 1;
    char server_hello[100];
    client_socket_state->seq_number = server_seq_number;
    snprintf(server_hello, sizeof(server_hello), "HELLO %d", server_seq_number);
    send(client_socket, server_hello, strlen(server_hello), 0);


}

void handle_second_handshake(client_state * client_socket_state){
    // Check if the socket is connected
    if (client_socket_state->socket <= 0) {
        fprintf(stderr, "ERROR: Socket is not connected\n");
        return;
    }
    // Receive the client's response HELLO z message
    char client_response[100];
    int client_socket = client_socket_state->socket;
    int bytes_received = recv(client_socket, client_response, sizeof(client_response), 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the server\n");
        close(client_socket);
        return;
    }

    client_response[bytes_received] = '\0';

    int client_response_seq_number;
    sscanf(client_response, "HELLO %d", &client_response_seq_number);
    printf("%s\n", client_response);
    fflush(stdout);

    int server_seq_number = client_socket_state->seq_number;

    // Check if the received sequence number is as expected
    if (client_response_seq_number != server_seq_number + 1) {
        fprintf(stderr, "ERROR: Unexpected sequence number from client\n");
        close(client_socket);
        return;
    }

    client_socket_state->socket = 0;
    client_socket_state->seq_number = -1;
    // Close the connection with the client
    close(client_socket);
}

int main(int argc, char *argv[]) {
    fd_set master_fds, read_fds;
    client_state * client_state_array[MAX_PENDING];

    int max_fd;

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
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

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

    FD_ZERO(&master_fds);
    FD_SET(server_socket, &master_fds);
    max_fd = server_socket;
    read_fds = master_fds;

    for (int i = 0; i < MAX_PENDING; ++i) {
        client_state_array[i] = (client_state*) malloc(sizeof(client_state));
        client_state_array[i]->socket = 0;
        client_state_array[i]->seq_number = -1;
        client_state_array[i]->current_state = NOT_CONNECTED;
    }

    fcntl(server_socket, F_SETFL, O_NONBLOCK);

    // Enter the loop to accept new connections

    while (1) {
        read_fds = master_fds;
        int activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Select error");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(server_socket, &read_fds)){
            int new_socket  = accept(server_socket, (struct sockaddr *)&client_addr,&client_addr_len);

            if (new_socket < 0) {
                perror("Accept error");
            }
            else{
                int i;
                for (i = 0; i < MAX_PENDING; ++i) {
                    if (client_state_array[i]->socket == 0){
                        client_state_array[i]->socket = new_socket;
                        FD_SET(new_socket, &master_fds);
                        fcntl(new_socket, F_SETFL, O_NONBLOCK);

                        if (new_socket > max_fd)
                            max_fd = new_socket; // Update the max_fd value if needed
                        break;
                    }

                }
                if (i <MAX_PENDING){
                    handle_client(client_state_array[i]);
                }
            }
        }
        for (int i = 0; i < MAX_PENDING; i++) {
            int client_socket = client_state_array[i]->socket;
            client_state * client_socket_state = client_state_array[i];
            client_socket_state->socket = client_socket;

            if (client_socket > 0 && FD_ISSET(client_socket, &read_fds)) {
                // Handle data from the connected client socket
                handle_second_handshake(client_socket_state);
                FD_CLR(client_socket,&master_fds);
            }
        }
    }

    // Close the server socket
    close(server_socket);
    printf("Server closed.\n");

    return 0;
}
