#include "Queue.h"

// initialize
Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->size = 0;
    q->start = -1;
    q->end = -1;
    for (int i = 0; i < kCapacity; i++) {
        q->data[i] = 0;
    }
    return q;
}

// adds item at end of available storage
void enqueue(Queue *q, int val) {
    if (q->start == -1) {
        q->start = 0;
        q->end = 0;
        q->size = 1;
        q->data[0] = val;
        return;
    }
    q->end++;
    q->end %= kCapacity;

    if(q->end == q->start) q->start++;
    q->start %= kCapacity;

    q->data[q->end] = val;

    if (q->size < kCapacity) {
        q->size++;
    }
}

// returns value and removes least recently added element
int dequeue(Queue *q) {
    if (empty(q)) {
        printf("Queue is empty please enqueue.\n");
        exit(EXIT_FAILURE);
    }
    int val = q->data[q->start];
    q->data[q->start] = 0;
    q->start++;
    q->start %= kCapacity;
    q->size--;
    return val;
}

bool empty(Queue *q) {
    return (q->size == 0);
}

bool full(Queue *q) {
    return (q->size == kCapacity);
}

void printQueue(Queue *q) {
    printf("HEAD>");
    for (int i = 0; i < q->size; i++) {
        int idx = (i + q->start)%kCapacity;
        printf("%d>", q->data[idx]);
    }
    printf("TAIL\n");
}
