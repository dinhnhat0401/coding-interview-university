#include "BST.h"

Node* createNewNode(int val) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->p = NULL;
    n->left = NULL;
    n->right = NULL;
    n->val = val;
    return n;
}

Node* insert(Node *root, int val) {
    Node* newNode = createNewNode(val);
    if (root == NULL) {
        root = newNode;
        return root;
    }
    Node *cur = root;
    Node *prev = root;
    while (cur != NULL) {
        prev = cur;
        if (val > cur->val) {
            cur = cur->right;
        } else if (val < cur->val) {
            cur = cur->left;
        } else {
            return root;
        }
    }
    if (val < prev->val) {
        prev->left = newNode;
        newNode->p = prev;
    } else if (val > prev->val) {
        prev->right = newNode;
        newNode->p = prev;
    }
    return root;
}
int getNodeCount(Node *root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getNodeCount(root->right) + getNodeCount(root->left);
}
bool isInTree(Node *root, int val) {
    if (root == NULL) return false;
    Node *cur = root;
    while (cur != NULL) {
        if (val == cur->val) {
            return true;
        } else if (val > cur->val) {
            cur = cur->right;
        } else {
            cur = cur->left;
        }
    }
    return false;
}
void printTree(Node *root);
void deleteTree(Node *root);
int getHeight(Node *root) {
    if (root == NULL) return -1;
    int a = getHeight(root->left);
    int b = getHeight(root->right);
    // int tmp = a > b : a ? b;
    return 1 + (a > b ? a : b);
}
int getMin(Node *root) {
    if (root == NULL) return 0;
    Node *cur = root;
    Node *prev = root;
    while (cur != NULL) {
        prev = cur;
        cur = cur->left;
    }
    return prev->val;
}
int getMax(Node *root) {
    if (root == NULL) return 0;
    Node *cur = root;
    Node *prev = root;
    while (cur != NULL) {
        prev = cur;
        cur = cur->right;
    }
    return prev->val;
}

bool isBSTUtil(Node *root, int min, int max) {
    if (root == NULL) return true;
    if (root->val > min && root->val < max &&
    isBSTUtil(root->right, root->val, max) &&
    isBSTUtil(root->left, min, root->val)) {
        return true;
    }
    return false;
}
bool isBinarySearchTree(Node *root) {
    return isBSTUtil(root, -2147483647, 2147483647);
}
void deleteValue(Node *root, int val) {
    if (isInTree(root, val) != true) return;
    
}
int getSuccessor(Node *root, int val) {
    
}