#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 65432
#define BUFFER_SIZE 1024

// Function to send file to the server
void send_file(int client_fd, const char *filename) 
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // Open the file for reading
    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    // Read the file and send it in chunks to the server
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file)) > 0) 
{
        if (send(client_fd, buffer, bytes_read, 0) < 0) {
            perror("File sending failed");
            break;
        }
    }
    printf("File sent successfully\n");
    // Close the file after sending
    fclose(file);
}
int main() 
{
    int client_fd;
    struct sockaddr_in server_addr;
    const char *filename = "in.txt";  // Modify with the path to the file you want to send

    // Create a TCP socket
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

    // Send the file to the server
    send_file(client_fd, filename);

    // Close the connection
    close(client_fd);
    return 0;
}
