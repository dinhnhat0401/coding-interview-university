#include "quick.h"

void quick_sort(int *arr, int lo, int hi) {
    if (hi <= lo) return;
    int j = partition(arr, lo, hi);
    quick_sort(arr, lo, j - 1);
    quick_sort(arr, j + 1, hi);
}

int partition(int *arr, int lo, int hi) {
    int i = lo;
    int j = hi + 1;
    while (true) {
        while(arr[++i] <= arr[lo]) {
            if (i == hi) break;
        }
        while(arr[--j] >= arr[lo]) {
            if (j == lo) break;
        }
        if (j <= i) break;
        swap(arr, i, j);
    }
    swap(arr, lo, j);
    return j;
}

void swap(int *arr, int x, int y) {
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
