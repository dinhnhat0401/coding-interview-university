#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

const int kCapacity = 100;
typedef struct Heap {
    int size;
    int data[kCapacity];
} Heap;

void siftUp(Heap *heap, int idx); // need for insert
void insert(Heap *heap, int val);
int getMax(Heap *heap);
int getSize(Heap *heap); // return number of elements sorted
bool isEmpty(Heap *heap); // return true if heap constains no element
int extractMax(Heap *heap); // get maximum element of max heap, and remove it
void siftDown(Heap *heap, int idx); // need for extract max
void removeElement(Heap *heap, int idx); // remove item at index idx
Heap* heapify(int *arr, int arrSize); // create a heap from an arrays of elements, need for heapsort
int* heapSort(int *arr, int arrSize); // take an unsorted array and turn it to an sorted array, using max-heap
void printHeap(Heap *heap); // print elements in a heap

int getParentIndex(int idx);
int getLeftChild(int idx);
int getRightChild(int idx);
