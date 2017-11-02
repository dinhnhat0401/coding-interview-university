#include "Test.h"
#include "BST.c"

void testInsert() {
    Node *root = NULL;
    root = insert(root, 5);
    assert(getNodeCount(root) == 1);
    assert(isInTree(root, 5) == true);
    assert(isInTree(root, 66) == false);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 11);
    root = insert(root, 38);
    root = insert(root, 18);
    root = insert(root, 18);
    assert(getNodeCount(root) == 6);
}

void testTreeSize() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 11);
    root = insert(root, 38);
    root = insert(root, 18);
    assert(getHeight(root) == 3);
    assert(getMax(root) == 38);
    assert(getMin(root) == 5);
}

void testRest() {
    Node *root = NULL;
    root = insert(root, 25);
    root = insert(root, 20);
    root = insert(root, 21);
    root = insert(root, 11);
    root = insert(root, 38);
    root = insert(root, 18);
    assert(isBinarySearchTree(root) == true);
    assert(isInTree(root, 11) == true);
    deleteValue(root, 11);
    assert(isInTree(root, 11) == false);
    assert(getSuccessor(root, 20) == 21);
}
