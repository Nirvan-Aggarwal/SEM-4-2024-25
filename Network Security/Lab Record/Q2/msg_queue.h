#ifndef MSG_QUEUE_H
#define MSG_QUEUE_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSG_KEY 1234  // Unique message queue key
#define MSG_SIZE 512  // Max size of message data
struct message {
    long msg_type;
    char data[MSG_SIZE];
};
#endif
