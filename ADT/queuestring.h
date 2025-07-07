#ifndef QUEUESTRING_H
#define QUEUESTRING_H

#define MAX_QUEUE 100

typedef struct {
    char data[MAX_QUEUE];
    int front;
    int rear;
} QueueString;

void createQueueString(QueueString *queue);
int isQueueStringEmpty(QueueString *queue);
int isQueueStringFull(QueueString *queue);
int enqueueString(QueueString *queue, char value);
int dequeueString(QueueString *queue, char *value);
int peekQueueString(QueueString *queue, char *value);
int queueStringSize(QueueString *queue);
void clearQueueString(QueueString *queue);
void displayQueueString(QueueString *queue);

#endif
