#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

typedef struct Graph {
    int vertice_number;
    int edge_number;
    Node **vertices;
} Graph;

Graph *initialize(int vertice_number);
int getV(Graph *g);
int getE(Graph *g);
void addEdge(Graph *g, int v, int w);
Node* adj(Graph *g, int v);
void printGraph(Graph *g);
void dfs_recursive(Graph *g, int v, bool *visited, bool *exposed);
void preVisit(int v, bool *visited);
void posVisit(int v, bool *exposed);
void destroyGraph(Graph *g);
void destroyLinkedList(Node *s);
void deleteLast(Node *s);
void dfs_stack(Graph *g, int v, bool *visited, bool *exposed);
Node* pop(Node *head);
Node* push(Node *head, int val);
Queue* enqueue(Queue *q, int val);
Queue* dequeue(Queue *q);
void bfs_queue(Graph *g, int v, bool *visited);
