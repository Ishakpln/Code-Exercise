#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void createList(LinkedList* list) {
    list->head = NULL;
}

bool isListEmpty(LinkedList* list) {
    return list->head == NULL;
}

void insertFront(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memori gagal dialokasikan!\n");
        return;
    }
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void insertBack(LinkedList* list, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memori gagal dialokasikan!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isListEmpty(list)) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool removeFront(LinkedList* list, int* value) {
    if (isListEmpty(list)) {
        return false;
    }
    Node* temp = list->head;
    *value = temp->data;
    list->head = temp->next;
    free(temp);
    return true;
}

bool removeBack(LinkedList* list, int* value) {
    if (isListEmpty(list)) {
        return false;
    }

    Node* current = list->head;
    Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    *value = current->data;
    if (prev == NULL) {
        list->head = NULL;  // Hanya satu elemen
    } else {
        prev->next = NULL;
    }

    free(current);
    return true;
}

int listSize(LinkedList* list) {
    int count = 0;
    Node* temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearList(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

void displayList(LinkedList* list) {
    Node* temp = list->head;
    printf("Isi Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
