#include "test.h"
#include "quick.c"

void run_all_tests() {
    int arr[] = {10, 19, 20, 34, 11, 23, 222, 111, 290};
    int answer[] = {10, 11, 19, 20, 23, 34, 111, 222, 290};
    // quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0]) - 1);
    // insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        printf("answer[i] = %d, result[i] = %d\n", answer[i], arr[i]);
        assert(answer[i] == arr[i]);
    }
}
