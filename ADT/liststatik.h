#ifndef LISTSTATIK_H
#define LISTSTATIK_H

#include <stdbool.h>

#define CAPACITY 100

typedef struct {
    int contents[CAPACITY];
    int length;
} ListStatik;

// Konstruktor
void createListStatik(ListStatik *l);

// Selektor
int getListElement(ListStatik l, int idx);
void setListElement(ListStatik *l, int idx, int val);

// Informasi List
int listLength(ListStatik l);
bool isFull(ListStatik l);
bool isEmpty(ListStatik l);

// Operasi Dasar
void insertLast(ListStatik *l, int val);
void deleteLast(ListStatik *l, int *val);
void insertFirst(ListStatik *l, int val);
void deleteFirst(ListStatik *l, int *val);
void insertAt(ListStatik *l, int val, int idx);
void deleteAt(ListStatik *l, int idx, int *val);

// Fungsi Bantu
int indexOf(ListStatik l, int val);
void printList(ListStatik l);

#endif
