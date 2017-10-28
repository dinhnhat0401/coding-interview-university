#include "Queue.h"

// initialize queue instance
Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    checkAddress(q);
    q->head = NULL;
    q->tail = NULL;
    return q;
}

// destroy queue
void destroyQueue(Queue *q) {
    node_t *current = q->head;
    node_t *previous = q->head;
    while(current != NULL) {
        previous = current;
        current = current->next;
        q->head = current;
        free(previous);
    }
    free(q);
}

// add item to queue
void enqueue(Queue *q, int val) {
    node_t *node = (node_t*)malloc(sizeof(node_t));
    checkAddress(node);
    node->val = val;
    node->next = NULL;
    if (q->head == NULL) {
        q->head = node;
        q->tail = node;
    } else {
        q->tail->next = node;
        q->tail = node;
    }
}

// remove item from queue
int dequeue(Queue *q) {
    if (q->head == NULL) {
        printf("can not dequeue item from empty queue.\n");
        exit(EXIT_FAILURE);
    } else {
        node_t *old_head = q->head;
        int val = old_head->val;
        q->head = old_head->next;
        free(old_head);
        return val;
    }
}

// print queue item
void printQueue(Queue *q) {
    printf("HEAD<");
    node_t *current = q->head;
    while(current != NULL) {
        printf("%d<", current->val);
        current = current->next;
    }
    printf("TAIL\n\n");
}

// check if memory has been allocated successfull
void checkAddress(void *p) {
    if (p == NULL) {
        printf("Can not allocate memory\n");
        exit(EXIT_FAILURE);
    }
}

// check if queue is empty
bool empty(Queue *q) {
    return (q->head == NULL);
}
