#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

// Function to reverse the string
void reverse_string(char *str) 
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) 
{
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create a UDP socket
    server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Receive data from the client
        ssize_t bytes_received = recvfrom(server_fd, buffer, sizeof(buffer), 0, 
                                          (struct sockaddr *)&client_addr, &client_len);
        if (bytes_received < 0) {
            perror("Receive failed");
            continue;
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received string

        printf("Received sentence: %s\n", buffer);

        // Reverse the sentence
        reverse_string(buffer);
        printf("Reversed sentence: %s\n", buffer);

        // Send the reversed sentence back to the client
        if (sendto(server_fd, buffer, strlen(buffer), 0, 
                   (struct sockaddr *)&client_addr, client_len) < 0) {
            perror("Send failed");
        }
    }

    close(server_fd);
    return 0;
}
