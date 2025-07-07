#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedliststring.h"

void createListString(LinkedListString* list) {
    list->head = NULL;
}

bool isListStringEmpty(LinkedListString* list) {
    return list->head == NULL;
}

void insertFrontString(LinkedListString* list, const char* value) {
    StringNode* newNode = (StringNode*)malloc(sizeof(StringNode));
    if (newNode == NULL) {
        printf("Memori gagal dialokasikan!\n");
        return;
    }
    strncpy(newNode->data, value, MAX_STR_LEN);
    newNode->data[MAX_STR_LEN - 1] = '\0'; // pastikan null-terminated
    newNode->next = list->head;
    list->head = newNode;
}

void insertBackString(LinkedListString* list, const char* value) {
    StringNode* newNode = (StringNode*)malloc(sizeof(StringNode));
    if (newNode == NULL) {
        printf("Memori gagal dialokasikan!\n");
        return;
    }
    strncpy(newNode->data, value, MAX_STR_LEN);
    newNode->data[MAX_STR_LEN - 1] = '\0';
    newNode->next = NULL;

    if (isListStringEmpty(list)) {
        list->head = newNode;
    } else {
        StringNode* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool removeFrontString(LinkedListString* list, char* out) {
    if (isListStringEmpty(list)) {
        return false;
    }
    StringNode* temp = list->head;
    strncpy(out, temp->data, MAX_STR_LEN);
    list->head = temp->next;
    free(temp);
    return true;
}

bool removeBackString(LinkedListString* list, char* out) {
    if (isListStringEmpty(list)) {
        return false;
    }

    StringNode* current = list->head;
    StringNode* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    strncpy(out, current->data, MAX_STR_LEN);
    if (prev == NULL) {
        list->head = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
    return true;
}

int listStringSize(LinkedListString* list) {
    int count = 0;
    StringNode* temp = list->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void clearListString(LinkedListString* list) {
    StringNode* temp = list->head;
    while (temp != NULL) {
        StringNode* next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}

void displayListString(LinkedListString* list) {
    StringNode* temp = list->head;
    printf("Isi Linked List (String):\n");
    while (temp != NULL) {
        printf("- %s\n", temp->data);
        temp = temp->next;
    }
}
