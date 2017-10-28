#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const int kCapacity = 5;

typedef struct Queue {
    int data[kCapacity];
    int size;
    int start;
    int end;
} Queue;

Queue* initialize();

// adds item at end of available storage
void enqueue(Queue *q, int value);

// returns value and removes least recently added element
int dequeue(Queue *q);

bool empty(Queue *q);

bool full(Queue *q);

void printQueue(Queue *q);
