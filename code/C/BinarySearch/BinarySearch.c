#include "BinarySearch.h"

int getIndexOfValue(int *arr, int val, int lo, int hi) {
    if (lo > hi) {
        return -1;
    }

    int mi = (lo + hi)/2;
    if (arr[mi] == val) return mi;
    else if (arr[mi] > val) {
        return getIndexOfValue(arr, val, lo, mi - 1);
    } else {
        return getIndexOfValue(arr, val, mi + 1, hi);
    }
}

int main(int argc, const char* argv[]) {
    int arr[] = {1, 3, 4, 5, 6, 7, 77, 666, 7777};
    printf("Index of 4 is: %d\n", getIndexOfValue(arr, 4, 0, sizeof(arr)/sizeof(int)));
}