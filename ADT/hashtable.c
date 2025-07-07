#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

void createHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->buckets[i] = NULL;
    }
}

unsigned int hashFunction(const char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

void insertHash(HashTable* ht, const char* key, int value) {
    unsigned int index = hashFunction(key);
    HashNode* node = ht->buckets[index];

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            node->value = value; // update value jika key sudah ada
            return;
        }
        node = node->next;
    }

    // jika key belum ada, buat node baru
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (!newNode) return;

    strncpy(newNode->key, key, MAX_KEY_LEN);
    newNode->key[MAX_KEY_LEN - 1] = '\0';
    newNode->value = value;
    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;
}

bool getHash(HashTable* ht, const char* key, int* outValue) {
    unsigned int index = hashFunction(key);
    HashNode* node = ht->buckets[index];

    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            *outValue = node->value;
            return true;
        }
        node = node->next;
    }
    return false;
}

bool existsHash(HashTable* ht, const char* key) {
    int dummy;
    return getHash(ht, key, &dummy);
}

bool removeHash(HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    HashNode* current = ht->buckets[index];
    HashNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                ht->buckets[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void displayHashTable(HashTable* ht) {
    printf("Isi Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = ht->buckets[i];
        if (node != NULL) {
            printf("[%d]: ", i);
            while (node != NULL) {
                printf("(%s → %d) ", node->key, node->value);
                node = node->next;
            }
            printf("\n");
        }
    }
}

void clearHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = ht->buckets[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        ht->buckets[i] = NULL;
    }
}
