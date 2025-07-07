#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void createStack(Stack* s) {
    s->top = -1;
}

bool isStackEmpty(Stack* s) {
    return s->top == -1;
}

bool isStackFull(Stack* s) {
    return s->top == MAX - 1;
}

void pushStack(Stack* s, int value) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

bool popStack(Stack* s, int* value) {
    if (is_empty(s)) {
        return false;  
    }
    *value = s->items[(s->top)--];
    return true;
}


int peekStack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack kosong!\n");
        exit(EXIT_FAILURE);
    }
    return s->items[s->top];
}

int stackSize(Stack* s) {
    return s->top + 1;
}

void clearStack(Stack* s) {
    s->top = -1;
}

void displayStack(Stack* s) {
    if (is_empty(s)) {
        printf("Stack kosong\n");
        return;
    }
    printf("Isi stack (atas ke bawah):\n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}
