#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

// Function to handle file reception from client
void receive_file(int client_fd) 
{
    char buffer[BUFFER_SIZE];
    FILE *file;
    size_t bytes_received;

    // Open a file to save the received data
    file = fopen("received_file", "wb");
    if (file == NULL) 
{
        perror("File creation failed");
        return;
    }

    // Receive the file data from the client and write it to the file
    while ((bytes_received = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) 
{
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    if (bytes_received < 0) 
{
        perror("File reception failed");
    } else 
{
        printf("File received successfully\n");
    }

    // Close the file after writing
    fclose(file);
}

int main() 
{
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) 
{
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified IP and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
{
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) 
{
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) 
{
        // Accept a client connection
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd < 0) 
{
            perror("Accept failed");
            close(server_fd);
            exit(EXIT_FAILURE);
        }

        printf("Connection established with client\n");

        // Handle the file reception
        receive_file(client_fd);

        // Close the client connection
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
