#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

int main() 
{
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_sent, bytes_received;

    // Create socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) 
{
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
{
        perror("Connection failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Get input from the user
    printf("Enter a sentence to reverse: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character

    // Send the sentence to the server
    bytes_sent = send(client_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) 
{
        perror("Send failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Receive the reversed sentence from the server
    bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) 
{
        perror("Receive failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received string

    // Print the reversed sentence
    printf("Reversed sentence from server: %s\n", buffer);

    // Close the connection
    close(client_fd);
    return 0;
}

