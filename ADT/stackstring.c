#include <stdio.h>
#include "stackstring.h"

void createStackString(Stack *stack) {
    stack->top = -1;
}

int isStackStringEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackStringFull(Stack *stack) {
    return stack->top == MAX_STACK - 1;
}

int pushStackString(Stack *stack, char value) {
    if (isStackStringFull(stack)) {
        return 0;  // gagal
    }
    stack->data[++(stack->top)] = value;
    return 1;      // sukses
}

int popStackString(Stack *stack, char *value) {
    if (isStackStringEmpty(stack)) {
        return 0;  // gagal
    }
    *value = stack->data[(stack->top)--];
    return 1;      // sukses
}

int peekStackString(Stack *stack, char *value) {
    if (isStackStringEmpty(stack)) {
        return 0;
    }
    *value = stack->data[stack->top];
    return 1;
}

int stackStringSize(Stack *stack) {
    return stack->top + 1;
}

void clearStackString(Stack *stack) {
    stack->top = -1;
}

void displayStackString(Stack *stack) {
    printf("Isi Stack: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%c", stack->data[i]);
    }
    printf("\n");
}


