#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Queue;

void createQueue(Queue* q);
bool isQueueEmpty(Queue* q);
bool isQueueFull(Queue* q);
void enqueue(Queue* q, int value);
bool dequeue(Queue* q, int* value);
int peekQueue(Queue* q);
int queueSize(Queue* q);
void clearQueue(Queue* q);
void displayQueue(Queue* q);

#endif
