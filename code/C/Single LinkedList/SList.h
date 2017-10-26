#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *next;
}Node;

typedef struct SListImplement {
    Node *head;
}SList;

// initialize a SList
SList* initialize();

// push item to head of list
void pushFront(SList *list,int item);

// get first item of list
int topFront(SList *list);

// pop first item of list and return that item
int popFront(SList *list);

// push item to back of list
void pushBack(SList *list, int item);

// get value of last item of list
int topBack(SList *list);

// pop last item of list and return that item
int popBack(SList *list);

// check if item with key = value exist in list
bool find(SList *list, int value);

// erase(index) - removes node at given index
void erase(SList *list, int index);

// check if list is empty
bool empty(SList *list);

// add a node with value before a node
void addBefore(SList *list, Node *node, int value);

// add a node after a node
void addAfter(SList *list, Node *node, int value);

// print all values in list
void printSList(SList *list);

void check_address(void *p);