#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#define FIFO_FILE "/tmp/myfifo"
int main() 
{
    int fd;
    char write_msg[] = "Hello from FIFO writer!";

    // Create FIFO
    mkfifo(FIFO_FILE, 0666);

    // Open FIFO for writing
    fd = open(FIFO_FILE, O_WRONLY);
    write(fd, write_msg, strlen(write_msg) + 1);
    close(fd);

    return 0;
}
