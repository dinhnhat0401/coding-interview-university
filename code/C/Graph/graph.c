#include "graph.h"

Graph *initialize(int vertice_number) {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    g->vertice_number = vertice_number;
    g->edge_number = 0;
    g->vertices = (Node**)malloc(sizeof(Node*) * vertice_number);
    for (int i = 0; i < g->vertice_number; i++) {
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->next = NULL;
        tmp->val = -1;
        *(g->vertices + i) = tmp;
    }
    return g;
}
int getV(Graph *g) {
    return g->vertice_number;
}
int getE(Graph *g) {
    return g->edge_number;
}
void addEdge(Graph *g, int v, int w) {
    if (v < 0 || w < 0) {
        printf("Can not add edge!\n");
        return;
    }

    Node *v1 = *(g->vertices + v);
    if (v1->val != v) {
        v1->val = v;
    }
    while (v1->next != NULL) {
        v1 = v1->next;
    }
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->val = w;
    tmp->next = NULL;
    v1->next = tmp;

    Node *v2 = *(g->vertices + w);
    if (v2->val != w) {
        v2->val = w;
    }
    while (v2->next != NULL) {
        v2 = v2->next;
    }
    Node *tmp2 = (Node*)malloc(sizeof(Node));
    tmp2->val = v;
    tmp2->next = NULL;
    v2->next = tmp2;

    g->edge_number++;
}
Node* adj(Graph *g, int v) {
    return *(g->vertices + v);
}
void printGraph(Graph *g) {
    printf("Vertice number = %d\n", g->vertice_number);
    printf("Edge number = %d\n", g->edge_number);
    for (int i = 0; i < g->vertice_number; i++) {
        Node *current_vertice = *(g->vertices + i);
        while(current_vertice != NULL) {
            printf("[%d]->", current_vertice->val);
            current_vertice = current_vertice->next;
        }
        printf("//\n");
    }
    printf("\n\n");
}

void destroyGraph(Graph *g) {
    for (int i = 0; i < g->vertice_number; i++) {
        destroyLinkedList(*(g->vertices + i));
    }
    free(g->vertices);
    g->vertices = NULL;
}

void destroyLinkedList(Node *s) {
    Node *current = s;
    while(current != NULL) {
        s = s->next;
        free(current);
        current = s;
    }
    s = NULL;
}

void dfs_recursive(Graph *g, int v, bool *visited, bool *exposed) {
    if (v < 0 || v > g->vertice_number) {
        printf("Can not dfs from not existed vertice!");
        return;
    }
    preVisit(v, visited);
    printf("[%d]->", v);
    Node *n = *(g->vertices + v);
    while (n != NULL) {
        if (visited[n->val] != true) dfs_recusive(g, n->val, visited, exposed);
        n = n->next;
    }
    posVisit(v, exposed);
}

void preVisit(int v, bool *visited) {
    visited[v] = true;
}

void posVisit(int v, bool *exposed) {
    exposed[v] = true;
}

void dfs_stack(Graph *g, int v, bool *visited, bool *exposed) {
    if (v < 0 || v > g->vertice_number) {
        printf("Can not dfs from not existed vertice!");
        return;
    }
    Node *stack = NULL;
    stack = push(stack, v);
    while (stack != NULL) {
        printf("[%d]->", stack->val);
        visited[stack->val] = true;
        Node *ver = *(g->vertices + stack->val);
        stack = pop(stack);
        while (ver != NULL) {
            if (!visited[ver->val]) {
                visited[ver->val] = true;
                stack = push(stack, ver->val);
            }
            ver = ver->next;
        }
    }
}

Node* pop(Node *head) {
    Node *tmp = head->next;
    free(head);
    head = tmp;
    return head;
}

Node* push(Node *head, int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->val = val;
    n->next = head;
    return n;
}
