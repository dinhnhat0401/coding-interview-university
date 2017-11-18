#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

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
void dfs_recusive(Graph *g, int v, bool *visited, bool *exposed);
void preVisit(int v, bool *visited);
void posVisit(int v, bool *exposed);
void destroyGraph(Graph *g);
void destroyLinkedList(Node *s);
void deleteLast(Node *s);