#include <stdbool.h>

typedef struct Node {
    int key;
    struct Node *next;
}Node;

typedef struct SListImplement {
    Node *head;
    Node *tail;
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

// returns the value of the nth item (starting at 0 for first)
int value_at(SList *list, int index);

// returns the value of the node at nth position from the end of the list
int value_n_from_end(int n);

// reverses the list
void reverse();

// print all values in list
void printSList(SList *list);

void check_address(void *p);