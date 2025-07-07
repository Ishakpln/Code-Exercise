#ifndef LINKEDLISTSTRING_H
#define LINKEDLISTSTRING_H

#include <stdbool.h>

#define MAX_STR_LEN 100

typedef struct StringNode {
    char data[MAX_STR_LEN];
    struct StringNode* next;
} StringNode;

typedef struct {
    StringNode* head;
} LinkedListString;

void createListString(LinkedListString* list);
bool isListStringEmpty(LinkedListString* list);
void insertFrontString(LinkedListString* list, const char* value);
void insertBackString(LinkedListString* list, const char* value);
bool removeFrontString(LinkedListString* list, char* out);
bool removeBackString(LinkedListString* list, char* out);
int listStringSize(LinkedListString* list);
void clearListString(LinkedListString* list);
void displayListString(LinkedListString* list);

#endif
