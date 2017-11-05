#include "Test.h"
#include "Heap.c"

void testInsert() {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->size = 0;
    insert(h, 29);
    insert(h, 10);
    insert(h, 2);
    insert(h, 15);
    insert(h, 21);
    insert(h, 7);
    insert(h, 21);
    printHeap(h);
    printf("testInsert completed\n");
}
void testExtractMax() {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->size = 0;
    insert(h, 29);
    insert(h, 10);
    insert(h, 2);
    insert(h, 15);
    insert(h, 21);
    insert(h, 7);
    insert(h, 21);
    assert(getMax(h) == 29);
    assert(extractMax(h) == 29);
    printHeap(h);
    assert(extractMax(h) == 21);
    printHeap(h);
    printf("testExtractMax completed\n");
}
void testRemove() {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    h->size = 0;
    insert(h, 29);
    insert(h, 10);
    insert(h, 2);
    insert(h, 15);
    insert(h, 21);
    insert(h, 7);
    insert(h, 21);
    printHeap(h);
    removeElement(h, 3);
    printHeap(h);
    printf("testRemove completed\n");
}
void testHeapSort() {
    int arr[] = {11, 13, 14, 7, 29, 18, 18, 12, 42};
    int result[] = {7, 11, 12, 13, 14, 18, 18, 29, 42};
    heapSort(arr, sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        assert(arr[i] == result[i]);
    }
    printf("testHeapSort compeleted\n");
}