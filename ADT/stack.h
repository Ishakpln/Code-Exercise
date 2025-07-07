#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    int items[MAX];
    int top;
} Stack;

void createStack(Stack* s);
bool isStackEmpty(Stack* s);
bool isStackFull(Stack* s);
void pushStack(Stack* s, int value);
bool popStack(Stack* s, int* value);  
int peekStack(Stack* s);
int stackSize(Stack* s);
void clearStack(Stack* s);
void displayStack(Stack* s);

#endif
