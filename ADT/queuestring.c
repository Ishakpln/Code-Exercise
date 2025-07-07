#include <stdio.h>
#include "queuestring.h"

void createQueueString(QueueString *queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isQueueStringEmpty(QueueString *queue) {
    return queue->rear < queue->front;
}

int isQueueStringFull(QueueString *queue) {
    return queue->rear == MAX_QUEUE - 1;
}

int enqueueString(QueueString *queue, char value) {
    if (isQueueStringFull(queue)) {
        return 0;  // gagal
    }
    queue->data[++(queue->rear)] = value;
    return 1;      // sukses
}

int dequeueString(QueueString *queue, char *value) {
    if (isQueueStringEmpty(queue)) {
        return 0;  // gagal
    }
    *value = queue->data[(queue->front)++];
    return 1;      // sukses
}

int peekQueueString(QueueString *queue, char *value) {
    if (isQueueStringEmpty(queue)) {
        return 0;
    }
    *value = queue->data[queue->front];
    return 1;
}

int queueStringSize(QueueString *queue) {
    return isQueueStringEmpty(queue) ? 0 : queue->rear - queue->front + 1;
}

void clearQueueString(QueueString *queue) {
    queue->front = 0;
    queue->rear = -1;
}

void displayQueueString(QueueString *queue) {
    printf("Isi Queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%c", queue->data[i]);
    }
    printf("\n");
}
