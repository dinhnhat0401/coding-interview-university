#include <stdbool.h>
const int kTableSize = 10;

typedef struct Location {
    char *key;
    char *val;
    struct Location *next;
} Location;

typedef struct HashTable {
    int size;
    Location **data;
} HashTable;

HashTable* initialize(int m);

// m is size of hash table
int hash(char *k, int m);

// if key already exists, update value
void add(HashTable *t, char *key, char *value);

bool exists(HashTable *t, char *key);

char* get(HashTable *t, char *key);

void removeKey(HashTable *t, char *key);

void printHash(HashTable* t);