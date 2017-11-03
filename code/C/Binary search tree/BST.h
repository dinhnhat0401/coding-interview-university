#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int val;
    struct Node *p;
    struct Node *left;
    struct Node *right;
} Node;

Node* insert(Node *root, int val);
int getNodeCount(Node *root);
void printTree(Node *root);
void deleteTree(Node *root);
bool isInTree(Node *root, int val);
int getHeight(Node *root);
int getMin(Node *root);
int getMax(Node *root);
bool isBinarySearchTree(Node *root);
Node* deleteValue(Node *root, int val);
Node* getSuccessor(Node *root, int val);
