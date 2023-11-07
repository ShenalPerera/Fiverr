#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_CLIENTS 100
#define DEFAULT_IP_ADDRESS "127.0.0.1"

// Struct to track the state of a single client
struct client_state {
    int client_socket;
    int server_seq_number;
};

// Function to handle the first handshake step
int handle_hello(struct client_state* client) {
    char client_hello[100];
    int bytes_received = recv(client->client_socket, client_hello, sizeof(client_hello), 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the client\n");
        return -1;
    }

    client_hello[bytes_received] = '\0';
    int client_seq_number;
    sscanf(client_hello, "HELLO %d", &client_seq_number);
    printf("%s\n", client_hello);
    fflush(stdout);

    // Send the response HELLO y message to the client
    client->server_seq_number = client_seq_number + 1;
    char server_hello[100];
    snprintf(server_hello, sizeof(server_hello), "HELLO %d", client->server_seq_number);
    send(client->client_socket, server_hello, strlen(server_hello), 0);

    return 0;
}

// Function to handle cleanup and reset after the second handshake
void reset_client_state(struct client_state* client) {

    // Reset the client_state for reusing the slot
    client->client_socket = 0;
    client->server_seq_number = 0;
}

// Function to handle the second handshake step
int handle_response(struct client_state* client) {
    char client_response[100];
    int bytes_received = recv(client->client_socket, client_response, sizeof(client_response), 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the client\n");
        return -1;
    }

    client_response[bytes_received] = '\0';
    int client_response_seq_number;
    sscanf(client_response, "HELLO %d", &client_response_seq_number);
    printf("%s\n", client_response);
    fflush(stdout);

    // Check if the received sequence number is as expected
    if (client_response_seq_number != client->server_seq_number + 1) {
        fprintf(stderr, "ERROR: Unexpected sequence number from client\n");
        reset_client_state(client);
        return -1;
    }


    // Cleanup and reset after the second handshake
    reset_client_state(client);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: [server_file_name] <port>\n");
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
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("simplex-talk: listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Create file descriptor sets
    fd_set all_fds, read_fds;
    int max_fd = server_socket;

    // Clear both sets
    FD_ZERO(&all_fds);
    FD_ZERO(&read_fds);

    // Add the server socket to the all_fds set
    FD_SET(server_socket, &all_fds);

    // Initialize the client_state_array to keep track of multiple clients
    struct client_state client_state_array[MAX_CLIENTS] = {0};

    // Enter the loop to accept new connections and read data
    while (1) {
        // Copy the all_fds set to read_fds before select(), as select() modifies the set.
        read_fds = all_fds;

        // Call select() to monitor the file descriptors for read readiness
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) == -1) {
            perror("select");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        // Check if the server socket is ready for a new connection
        if (FD_ISSET(server_socket, &read_fds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);

            // Accept a new connection (this call will block until a client connects)
            int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
            if (client_socket == -1) {
                perror("simplex-talk: accept");
                close(server_socket);
                exit(EXIT_FAILURE);
            }

            // Find an unused slot in client_state_array to store the new client socket
            int i;
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_state_array[i].client_socket == 0) {
                    // Store the new client socket in the unused slot
                    client_state_array[i].client_socket = client_socket;
                    client_state_array[i].server_seq_number = 0;

                    // Set the new client socket to non-blocking
                    int flags = fcntl(client_socket, F_GETFL, 0);
                    if (flags == -1) {
                        perror("fcntl");
                        close(server_socket);
                        exit(EXIT_FAILURE);
                    }
                    if (fcntl(client_socket, F_SETFL, flags | O_NONBLOCK) == -1) {
                        perror("fcntl");
                        close(server_socket);
                        exit(EXIT_FAILURE);
                    }

                    // Add the new client socket to the all_fds set
                    FD_SET(client_socket, &all_fds);

                    // Update max_fd if needed
                    if (client_socket > max_fd) {
                        max_fd = client_socket;
                    }

                    break;
                }
            }

            if (i == MAX_CLIENTS) {
                fprintf(stderr, "Too many clients. Closing the new connection.\n");
                close(client_socket);
                FD_CLR(client_socket, &all_fds);
            }
        }

        // Check all file descriptors for data to read
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int fd = client_state_array[i].client_socket;
            if (fd > 0 && FD_ISSET(fd, &read_fds)) {
                // Check if it is the listening socket
                if (fd == server_socket) {
                    // Handle new client connection (already handled above)
                } else {
                    // Find the client_state for this socket
                    struct client_state* client = &client_state_array[i];

                    // Check which handshake step to process based on the client's state
                    if (client->server_seq_number == 0) {
                        int result = handle_hello(client);
                        if (result == -1) {
                            // Close the connection with the client
                            close(fd);
                            FD_CLR(fd, &all_fds);

                            // Reset the client_state for reusing the slot
                            reset_client_state(client);
                        }
                    } else {
                        int result = handle_response(client);
                        if (result == -1) {
                            // Close the connection with the client
                            close(fd);
                            FD_CLR(fd, &all_fds);

                            // Reset the client_state for reusing the slot
                            reset_client_state(client);
                        }
                    }
                }
            }
        }
    }

    // Close the server socket
    close(server_socket);
    printf("Server closed.\n");

    return 0;
}
