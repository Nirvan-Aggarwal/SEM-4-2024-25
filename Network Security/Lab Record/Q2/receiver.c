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

    // Get the message queue
    msgid = msgget(MSG_KEY, 0666);
    if (msgid == -1) 
{
        perror("msgget failed");
        exit(1);
    }

    // Open file for writing
    file = fopen("output.txt", "wb");
    if (!file) 
{
        perror("File open failed");
        exit(1);
    }

    // Receive messages and write to file
    while (1) 
{
        if (msgrcv(msgid, &msg, MSG_SIZE, 1, 0) == -1)
 {
            perror("msgrcv failed");
            exit(1);
        }

        if (strcmp(msg.data, "EOF") == 0)
            break;  // End of file transmission

        fputs(msg.data, file);
    }

    fclose(file);
    printf("File received successfully.\n");

    // Remove the message queue
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}

