#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

// initialize a SList
SList* initialize() {
    SList *slist = (SList*)malloc(sizeof(SList));
    check_address(slist);
    slist->head = 0;
    return slist;
}

// push item to head of list
void pushFront(SList *list,int value) {
    Node *node = (Node*)malloc(sizeof(Node));
    check_address(node);
    node->key = value;

    if (list->head == 0) {
        node->next = 0;
    } else {
        node->next = list->head;
    }

    list->head = node;
}

// get first item of list
int topFront(SList *list) {
    if (list->head == 0) {
        return 0;
    } else {
        return list->head->key;
    }
}

// pop first item of list and return that item
int popFront(SList *list) {
    if (list->head == 0) {
        return 0;
    }
    Node *currentHead = list->head;
    int value = currentHead->key;
    list->head = list->head->next;
    free(currentHead);
    return value;
}

// push item to back of list
void pushBack(SList *list, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    check_address(newNode);
    newNode->key = value;
    newNode->next = 0;

    if (list->head == 0) {
        list->head = newNode;
    } else {
        Node *last = list->head;
        while(last->next != 0) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// get value of last item of list
int topBack(SList *list) {
    if (list->head == 0) {
        return 0;
    } else {
        Node *last = list->head;
        while(last->next != 0) {
            last = last->next;
        }
        return last->key;
    }
}

// pop last item of list and return that item
int popBack(SList *list) {
    if (list->head == 0) {
        return 0;
    } else if (list->head->next == 0) {
        int value = list->head->key;
        free(list->head);
        list->head = 0;
        return value;
    } else {
        Node *newLast = list->head;
        while (newLast->next->next != 0) {
            newLast = newLast->next;
        }
        int value = newLast->next->key;
        free(newLast->next);
        newLast->next = 0;
        return value;
    }
}

// check if item with key = value exist in list
bool find(SList *list, int value) {
    Node *current = list->head;
    while(current != 0) {
        if (current->key == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// erase(index) - removes node at given index
void erase(SList *list, int index) {
    if (list->head == 0) {
        printf("Cannot erase item from empty list\n");
        exit(EXIT_FAILURE);
    }
    int counter = 0;
    Node *previous = list->head;
    Node *current = list->head;
    while (current != 0) {
        if (counter == index) {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
        counter++;
    }
    printf("Cannot find item with that index\n");
    exit(EXIT_FAILURE);
}

// check if list is empty
bool empty(SList *list) {
    return list->head == 0;
}

// add a node with value before a node
void addBefore(SList *list, Node *node, int value) {

}

// add a node after a node
void addAfter(SList *list, Node *node, int value) {
    if (list->head == 0) {
        printf();
    }
}

// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p) {
    if (p == NULL) {
        printf("Can not allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

// print all values in list
void printSList(SList *list) {
    Node *node = list->head;
    while (node != 0) {
        printf("%d->", node->key);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    SList *list = initialize();
    pushBack(list, 5);
    pushFront(list, 55);
    pushFront(list, 60);
    pushFront(list, 65);
    printSList(list);
    printf("top front %d\n", topFront(list));
    printSList(list);
    printf("pop front %d\n", popFront(list));
    printSList(list);
    pushBack(list, 129);
    printSList(list);
    popBack(list);
    printSList(list);
    printf("This list contain 55: %d\n", find(list, 55));
    printf("This list contain 56: %d\n", find(list, 56));
    erase(list, 2);
    printSList(list);
    // erase(list, -1);
    // printSList(list);
    erase(list, 2);
    printSList(list);
}
