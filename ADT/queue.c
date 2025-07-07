#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void createQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

bool isQueueEmpty(Queue* q) {
    return q->rear < q->front;
}

bool isQueueFull(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int value) {
    if (isQueueFull(q)) {
        printf("Queue overflow!\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

bool dequeue(Queue* q, int* value) {
    if (isQueueEmpty(q)) {
        return false;
    }
    *value = q->items[(q->front)++];
    return true;
}

int peekQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue kosong!\n");
        exit(EXIT_FAILURE);
    }
    return q->items[q->front];
}

int queueSize(Queue* q) {
    return isQueueEmpty(q) ? 0 : q->rear - q->front + 1;
}

void clearQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

void displayQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue kosong\n");
        return;
    }
    printf("Isi queue (depan ke belakang):\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d\n", q->items[i]);
    }
}
