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

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->val);
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->val);
    inOrder(root->right);
}

void printTree(Node *root) {
    printf("preorder\n");
    preOrder(root);
    printf("\n\n");

    printf("inorder\n");
    inOrder(root);
    printf("\n\n");

    printf("postorder\n");
    postOrder(root);
    printf("\n\n");
}

int getHeight(Node *root) {
    if (root == NULL) return -1;
    int a = getHeight(root->left);
    int b = getHeight(root->right);
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
Node* findNode(Node *root, int val) {
    if (root == NULL) return NULL;
    Node *cur = root;
    while (cur != NULL) {
        if (cur->val == val) return cur;
        else if (cur->val < val) cur = cur->right;
        else cur = cur->left;
    }
    return NULL;
}
bool isLeaf(Node *node) {
    return (node->left == NULL && node->right == NULL);
}
void deleteTree(Node *root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
Node* getMinNode(Node *root) {
    if (root == NULL) return NULL;
    Node *current = root;
    while (current->left != NULL) current = current->left;
    return current;
}
Node* deleteValue(Node *root, int val) {
    if (isInTree(root, val) != true) return root;
    Node* current = findNode(root, val);
    if (current == NULL) return root;
    if (current->left == NULL && current->right == NULL) {
        free(current);
        current = NULL;
        return root;
    }
    else if (current->right == NULL) {
        Node *tmp = current;
        current = current->left;
        free(tmp);
        tmp = NULL;
        return root;
    } else if (current->left == NULL) {
        Node *tmp = current;
        current = current->right;
        free(tmp);
        tmp = NULL;
        return root;
    } else {
        Node *successor = getMinNode(current->right);
        current->val = successor->val;
        return deleteValue(successor, successor->val);
    }
}

Node* getSuccessor(Node *root, int val) {
    if (root == NULL) return NULL;
    Node *current = findNode(root, val);
    if (current == NULL) return NULL;
    if (current->right != NULL) return getMinNode(current->right);
    Node *ancestor = root;
    Node *successor = NULL;
    while (ancestor != current) {
        if (ancestor->val < val) {
            ancestor = ancestor->right;
        } else {
            successor = ancestor;
            ancestor = ancestor->left;
        }
    }
    return successor;
}
