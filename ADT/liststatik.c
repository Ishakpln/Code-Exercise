#include <stdio.h>
#include "liststatik.h"

// Konstruktor
void createListStatik(ListStatik *l) {
    l->length = 0;
}

// Selektor
int getListElement(ListStatik l, int idx) {
    return l.contents[idx];
}

void setListElement(ListStatik *l, int idx, int val) {
    l->contents[idx] = val;
}

// Informasi List
int listLength(ListStatik l) {
    return l.length;
}

bool isFull(ListStatik l) {
    return l.length == CAPACITY;
}

bool isEmpty(ListStatik l) {
    return l.length == 0;
}

// Operasi Dasar
void insertLast(ListStatik *l, int val) {
    if (!isFull(*l)) {
        l->contents[l->length++] = val;
    }
}

void deleteLast(ListStatik *l, int *val) {
    if (!isEmpty(*l)) {
        *val = l->contents[--(l->length)];
    }
}

void insertFirst(ListStatik *l, int val) {
    if (!isFull(*l)) {
        for (int i = l->length; i > 0; i--) {
            l->contents[i] = l->contents[i - 1];
        }
        l->contents[0] = val;
        l->length++;
    }
}

void deleteFirst(ListStatik *l, int *val) {
    if (!isEmpty(*l)) {
        *val = l->contents[0];
        for (int i = 0; i < l->length - 1; i++) {
            l->contents[i] = l->contents[i + 1];
        }
        l->length--;
    }
}

void insertAt(ListStatik *l, int val, int idx) {
    if (!isFull(*l) && idx >= 0 && idx <= l->length) {
        for (int i = l->length; i > idx; i--) {
            l->contents[i] = l->contents[i - 1];
        }
        l->contents[idx] = val;
        l->length++;
    }
}

void deleteAt(ListStatik *l, int idx, int *val) {
    if (!isEmpty(*l) && idx >= 0 && idx < l->length) {
        *val = l->contents[idx];
        for (int i = idx; i < l->length - 1; i++) {
            l->contents[i] = l->contents[i + 1];
        }
        l->length--;
    }
}

// Fungsi Bantu
int indexOf(ListStatik l, int val) {
    for (int i = 0; i < l.length; i++) {
        if (l.contents[i] == val) {
            return i;
        }
    }
    return -1;
}

void printList(ListStatik l) {
    printf("[");
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.contents[i]);
        if (i < l.length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}
