#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>

#define TABLE_SIZE 101      // Ukuran hash table (jumlah bucket)
#define MAX_KEY_LEN 100     // Panjang maksimal untuk key string

/**
 * Node dari linked list dalam bucket hash table.
 * Menyimpan pasangan key (string) dan value (int).
 */
typedef struct HashNode {
    char key[MAX_KEY_LEN];       // Key unik (string)
    int value;                   // Value yang terasosiasi
    struct HashNode* next;       // Pointer ke node berikutnya (chaining)
} HashNode;

/**
 * Struktur utama untuk Hash Table.
 * Berisi array bucket berisi linked list dari HashNode.
 */
typedef struct {
    HashNode* buckets[TABLE_SIZE];  // Array bucket
} HashTable;

/**
 * Inisialisasi hash table dengan semua bucket bernilai NULL.
 * 
 * @param ht Pointer ke hash table yang akan dibuat.
 */
void createHashTable(HashTable* ht);

/**
 * Fungsi hash untuk menghasilkan indeks dari key string.
 * 
 * @param key Key berupa string.
 * @return Indeks dalam rentang 0 hingga TABLE_SIZE - 1.
 */
unsigned int hashFunction(const char* key);

/**
 * Menambahkan pasangan key-value ke dalam hash table.
 * Jika key sudah ada, maka nilainya diperbarui.
 * 
 * @param ht Pointer ke hash table.
 * @param key Key unik (string).
 * @param value Nilai (int) yang terkait dengan key.
 */
void insertHash(HashTable* ht, const char* key, int value);

/**
 * Mengambil value berdasarkan key.
 * 
 * @param ht Pointer ke hash table.
 * @param key Key yang dicari.
 * @param outValue Output nilai yang ditemukan, jika ada.
 * @return true jika key ditemukan, false jika tidak ada.
 */
bool getHash(HashTable* ht, const char* key, int* outValue);

/**
 * Menghapus pasangan key-value dari hash table.
 * 
 * @param ht Pointer ke hash table.
 * @param key Key yang ingin dihapus.
 * @return true jika penghapusan berhasil, false jika key tidak ditemukan.
 */
bool removeHash(HashTable* ht, const char* key);

/**
 * Mengecek apakah suatu key ada di dalam hash table.
 * 
 * @param ht Pointer ke hash table.
 * @param key Key yang ingin dicek keberadaannya.
 * @return true jika key ditemukan, false jika tidak.
 */
bool existsHash(HashTable* ht, const char* key);

/**
 * Menampilkan seluruh isi hash table.
 * Format: indeks → (key → value)
 * 
 * @param ht Pointer ke hash table.
 */
void displayHashTable(HashTable* ht);

/**
 * Menghapus semua node dari hash table dan membebaskan memori.
 * 
 * @param ht Pointer ke hash table.
 */
void clearHashTable(HashTable* ht);

#endif
