#ifndef STACKSTRING_H
#define STACKSTRING_H

#define MAX_STACK 100

// Definisi Stack
typedef struct {
    char data[MAX_STACK];
    int top;
} Stack;

// Fungsi-fungsi
void createStackString(Stack *stack);
int isStackStringEmpty(Stack *stack);
int isStackStringFull(Stack *stack);
int pushStackString(Stack *stack, char value);      
int popStackString(Stack *stack, char *value);       
int peekStackString(Stack *stack, char *value);
int stackSizeString(Stack* s);
void clearStackString(Stack* s);      
void displayStackString(Stack *stack);

#endif
