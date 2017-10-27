#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} node_t;

typedef struct Queue {
    node_t *head;
    node_t *tail;
} Queue;

// initialize queue instance
Queue* initialize();

// destroy queue
void destroyQueue(Queue *q);

// add item to queue
void enqueue(Queue *q, int val);

// remove item from queue
int dequeue(Queue *q);

// print queue item
void printQueue(Queue *q);

// check if memory has been allocated successfull
void checkAddress(void *p);

// check if queue is empty
bool empty(Queue *q);
