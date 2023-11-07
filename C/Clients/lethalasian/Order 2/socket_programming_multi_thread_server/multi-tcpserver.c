#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_PENDING 100
#define MAX_CLIENT_NUMBER 100
#define DEFAULT_IP_ADDRESS "127.0.0.1"

#define THREAD_RUNNING 1

typedef struct socket_attr_{
    int socket;
    int tid;
} socket_attr;

pthread_t tids[MAX_CLIENT_NUMBER];
int thread_status[MAX_CLIENT_NUMBER] = {!THREAD_RUNNING};


void *handle_client(void * client_socket_attr_ptr) {
    socket_attr client_socket_attr = *(socket_attr*)client_socket_attr_ptr;
    int client_socket_t  = client_socket_attr.socket;

    // Receive the client's initial HELLO x message
    char client_hello[100];
    int bytes_received = recv(client_socket_t, client_hello, sizeof(client_hello), 0);

    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the server\n");
        close(client_socket_t);
        pthread_exit(NULL);
    }

    client_hello[bytes_received] = '\0';
    int client_seq_number;
    sscanf(client_hello, "HELLO %d", &client_seq_number);
    printf("%s\n", client_hello);
    fflush(stdout);

    // Send the response HELLO y message to the client
    int server_seq_number = client_seq_number + 1;
    char server_hello[100];
    snprintf(server_hello, sizeof(server_hello), "HELLO %d", server_seq_number);
    send(client_socket_t, server_hello, strlen(server_hello), 0);

    // Receive the client's response HELLO z message
    char client_response[100];
    bytes_received =  recv(client_socket_t, client_response, sizeof(client_response), 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error in receiving data from the server\n");
        close(client_socket_t);
        pthread_exit(NULL);
    }

    client_response[bytes_received] = '\0';

    int client_response_seq_number;
    sscanf(client_response, "HELLO %d", &client_response_seq_number);
    printf("%s\n", client_response);
    fflush(stdout);

    // Check if the received sequence number is as expected
    if (client_response_seq_number != server_seq_number + 1) {
        fprintf(stderr, "ERROR: Unexpected sequence number from client\n");
        close(client_socket_t);
        pthread_exit(NULL);
    }

    // Close the connection with the client
    free(client_socket_attr_ptr);
    close(client_socket_t);
    thread_status[client_socket_attr.tid] = ~THREAD_RUNNING;
    return NULL;
}
int main(int argc, char *argv[]) {
    pthread_attr_t detachedThread;
    pthread_attr_init(&detachedThread);
    pthread_attr_setdetachstate(&detachedThread, PTHREAD_CREATE_DETACHED);

    int tid_index = 0;

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

        // Check the free thread slot available
        for (int i = 0; i < MAX_CLIENT_NUMBER; ++i) {
            if (thread_status[i] != THREAD_RUNNING){
                tid_index = i;
                thread_status[tid_index] = THREAD_RUNNING;
                break;
            }
        }


        socket_attr * client_socket_attr_ptr = (socket_attr*) malloc(sizeof(socket_attr));

        client_socket_attr_ptr->socket = client_socket;
        client_socket_attr_ptr->tid = tid_index;

        if (pthread_create(&tids[tid_index], &detachedThread, &handle_client, client_socket_attr_ptr) != 0) {
            perror("pthread_create failed");
            thread_status[tid_index] = !THREAD_RUNNING;
            close(client_socket);
            continue;
        }





    }

    pthread_attr_destroy(&detachedThread);
    // Close the server socket
    close(server_socket);
    printf("Server closed.\n");
    return 0;
}
