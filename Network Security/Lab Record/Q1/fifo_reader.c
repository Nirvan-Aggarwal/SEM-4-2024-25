#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "/tmp/myfifo"

int main() {
    int fd;
    char read_msg[100];

    // Open FIFO for reading
    fd = open(FIFO_FILE, O_RDONLY);
    read(fd, read_msg, sizeof(read_msg));
    printf("Reader received: %s\n", read_msg);
    close(fd);

    return 0;
}
