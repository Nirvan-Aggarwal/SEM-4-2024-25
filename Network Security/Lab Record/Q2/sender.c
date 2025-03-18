#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_queue.h"

int main() 
{
    int msgid;
    struct message msg;
    FILE *file;

    // Create message queue
    msgid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    if (msgid == -1)
 {
        perror("msgget failed");
        exit(1);
    }

    // Open file for reading
    file = fopen("input.txt", "rb");
    if (!file)
 {
        perror("File open failed");
        exit(1);
    }

    msg.msg_type = 1; // Message type must be > 0

    // Read and send file content in chunks
    while (fgets(msg.data, MSG_SIZE, file) != NULL) 
{
        if (msgsnd(msgid, &msg, strlen(msg.data) + 1, 0) == -1) 
     {
            perror("msgsnd failed");
            exit(1);
        }
    }

    // Send termination message
    strcpy(msg.data, "EOF");
    msgsnd(msgid, &msg, strlen(msg.data) + 1, 0);

    fclose(file);
    printf("File sent successfully.\n");

    return 0;
}
