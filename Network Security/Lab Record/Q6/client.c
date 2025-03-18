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

    // Create a UDP socket
    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd < 0) 
{
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

    // Get input from the user
    printf("Enter a sentence to reverse: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character

    // Send the sentence to the server
    ssize_t bytes_sent = sendto(client_fd, buffer, strlen(buffer), 0, 
                                (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bytes_sent < 0) 
{
        perror("Send failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    // Receive the reversed sentence from the server
    ssize_t bytes_received = recvfrom(client_fd, buffer, sizeof(buffer), 0, NULL, NULL);
    if (bytes_received < 0) 
{
        perror("Receive failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received string
    // Print the reversed sentence
    printf("Reversed sentence from server: %s\n", buffer);
    // Close the socket
    close(client_fd);
    return 0;
}

