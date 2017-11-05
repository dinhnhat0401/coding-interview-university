#include "Heap.h"

int getParentIndex(int idx) {
    return idx/2;
}
int getLeftChild(int idx) {
    return idx * 2;
}
int getRightChild(int idx) {
    return idx * 2 + 1;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void siftUp(Heap *heap, int idx) {
    if (idx > heap->size) {
        printf("Can not siftUp element not in heap.\n");
        return;
    }
    if (idx == 1) return;
    int parent = idx/2;
    if (heap->data[idx] > heap->data[parent]) {
        swap(&heap->data[idx], &heap->data[parent]);
    }
    siftUp(heap, parent);
}
void insert(Heap *heap, int val) {
    if (heap->size == kCapacity - 1) {
        printf("Heap is full can not insert more element.\n");
        return;
    }
    heap->data[++heap->size] = val;
    siftUp(heap, heap->size);
}
int getMax(Heap *heap) {
    if (heap->size < 1) return -1;
    return heap->data[1];
}
int getSize(Heap *heap) {
    return heap->size;
}
bool isEmpty(Heap *heap) {
    return (heap->size < 1);
}
int extractMax(Heap *heap) {
    int maxVal = heap->data[1];
    swap(&heap->data[1], &heap->data[heap->size--]);
    if (heap->size > 0) {
        siftDown(heap, 1);
    }
    return maxVal;
}
void siftDown(Heap *heap, int idx) {
    if (idx > heap->size) {
        printf("Can not siftDown element not in heap.\n");
        return;
    }
    int l = getLeftChild(idx);
    int r = getRightChild(idx);
    if (l > heap->size && r > heap->size) return;

    int tmp = idx;
    if (l <= heap->size && heap->data[idx] < heap->data[l]) {
        tmp = l;
    }
    if (r <= heap->size && heap->data[l] < heap->data[r]) {
        tmp = r;
    }
    if (tmp > idx) {
        swap(&heap->data[idx], &heap->data[tmp]);
        siftDown(heap, tmp);
    }
}
void removeElement(Heap *heap, int idx) {
     heap->data[idx] = INT32_MAX;
     siftUp(heap, idx);
     extractMax(heap);
}
Heap* heapify(int *arr, int arrSize) {
    Heap *h = (Heap*)malloc(sizeof(Heap));
    if (arrSize > kCapacity) {
        printf("Array is too large!");
    }
    for (int i = 0; i < arrSize; i++) {
        h->data[i+1] = arr[i];
    }
    h->size = arrSize;

    for (int i = h->size/2; i >= 1; i--) {
        siftDown(h, i);
    }
    return h;
}
int* heapSort(int *arr, int arrSize) {
    Heap *h = heapify(arr, arrSize);
    for (int i = arrSize; i >= 1; i--) {
        arr[i-1] = extractMax(h);
    }
    return arr;
}
void printHeap(Heap *heap) {
    printf("Heap content:\n");
    for (int i = 1; i <= heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}
