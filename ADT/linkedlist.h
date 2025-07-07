#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} LinkedList;

void createList(LinkedList* list);
bool isListEmpty(LinkedList* list);
void insertFront(LinkedList* list, int value);
void insertBack(LinkedList* list, int value);
bool removeFront(LinkedList* list, int* value);
bool removeBack(LinkedList* list, int* value);
int listSize(LinkedList* list);
void clearList(LinkedList* list);
void displayList(LinkedList* list);

#endif
