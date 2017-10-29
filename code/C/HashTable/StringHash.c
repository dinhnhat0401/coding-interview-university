#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "StringHash.h"

HashTable* initialize(int m) {
    HashTable *t = (HashTable*)malloc(sizeof(HashTable));
    t->size = m;
    t->data = (Location**)malloc(sizeof(Location*) * m);
    for (int i = 0; i < m; i++) {
        *(t->data + i) = NULL;
    }
    return t;
}

int hash(char* k, int m) {
    int hash = 0;
    for (int i = strlen(k) - 1; i >= 0; i--) {
        // printf("%c\n", k[i]);
        // printf("%d\n", k[i] - '0');
        hash = hash * 31 + k[i] - '0';
    }
    return abs(hash % m);
}

// if key already exists, update value
void add(HashTable *t, char *key, char *value) {
    Location *l = (Location*)malloc(sizeof(Location));
    l->key = key;
    l->val = value;
    l->next = NULL;
    int idx = hash(key, t->size);
    if (*(t->data + idx) == NULL) {
        *(t->data + idx) = l;
    } else { // collision
        Location *current = *(t->data + idx);
        Location *previous = *(t->data + idx);
        while(current != NULL) {
            // if this key already exist
            if (strcmp(current->key, key) == 0) {
                current->val = value;
                return;
            }
            previous = current;
            current = current->next;
        }
        // add new key to end of list
        previous->next = l;
    }
}

bool exists(HashTable *t, char *key) {
    int idx = hash(key, t->size);
    if (*(t->data + idx) == NULL) {
        return false;
    } else {
        Location *current = *(t->data + idx);
        while(current != NULL) {
            // if this key already exist
            if (strcmp(current->key, key) == 0) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
}

char* get(HashTable *t, char *key) {
    int idx = hash(key, t->size);
    if (*(t->data + idx) == NULL) {
        return NULL;
    } else {
        Location *current = *(t->data + idx);
        while(current != NULL) {
            // if this key already exist
            if (strcmp(current->key, key) == 0) {
                return current->val;
            }
            current = current->next;
        }
        return NULL;
    }
}

void removeKey(HashTable *t, char *key) {
    int idx = hash(key, t->size);
    if (*(t->data + idx) != NULL) {
        Location *current = *(t->data + idx);
        Location *previous = NULL;
        while(current != NULL) {
            // if this key already exist
            if (strcmp(current->key, key) == 0) {
                if (previous == NULL) {
                    *(t->data + idx) = NULL;
                } else {
                    previous->next = current->next;
                }
                free(current);
                return;
            }
            previous = current;
            current = current->next;
        }
    }
}

void printHash(HashTable* t) {
    printf("[\n");
    for (int i = 0; i < t->size; i++) {
        printf("[");
        Location *current = *(t->data + i);
        while(current != NULL) {
            printf("(%s, %s), ", current->key, current->val);
            current = current->next;
        }
        printf("]\n");
    }
    printf("]\n\n\n");
}

int main(int argc, const char* argv[]) {
    HashTable *t = initialize(kTableSize);
    // printHash(t);
    add(t, "Viet Nam", "Ha Noi");
    // printHash(t);
    add(t, "Viet Nam", "Ha Noi 2");
    // printHash(t);
    add(t, "Japan", "Tokyo");
    add(t, "Germany", "Berlin");
    add(t, "Holland", "Amsterdam");
    add(t, "China", "Beijing");
    add(t, "France", "Paris");
    add(t, "Brasil", "Sao Paulo");
    add(t, "HongKong", "HongKong");
    printHash(t);
    add(t, "Cambodia", "Cambodia");
    printHash(t);
    removeKey(t, "Japan");
    printHash(t);
    printf("Japan key is exist ? : %d", exists(t, "Japan"));
    return 0;
}
