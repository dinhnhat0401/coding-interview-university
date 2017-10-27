//
//  main.c
//  algorithm
//
//  Created by Đinh Văn Nhật on 2017/10/23.
//  Copyright © 2017 Đinh Văn Nhật. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

JArray *jarray_new(int capacity) {
    int trueCapacity = jarray_determine_capacity(capacity);
    JArray *newArrPtr = (JArray*)malloc(sizeof(JArray));
    newArrPtr->size = 0;
    newArrPtr->capacity = trueCapacity;
    newArrPtr->data = (int*)malloc(sizeof(int) * trueCapacity);
    return newArrPtr;
}

int jarray_determine_capacity(int capacity) {
    int trueCapacity = kMinCapacity;
    while (trueCapacity * kGrowthFactor <= capacity) {
        trueCapacity *= kGrowthFactor;
    }
    return trueCapacity;
}

// Appends the given item to the end of the array.
void jarray_push(JArray *arrptr, int item) {
    jarray_resize_for_size(arrptr, ++arrptr->size);
    *(arrptr->data + arrptr->size - 1) = item;
}

// Removes the last item from the array and returns its value.
int jarray_pop(JArray *arrptr) {
    if (arrptr->size == 0) {
        exit(EXIT_FAILURE);
    }
    int lastItem = *(arrptr->data + arrptr->size - 1);
    jarray_resize_for_size(arrptr, arrptr->size--);

    return lastItem;
}

// Checks to see if resizing is needed to support the candidate_size
// and resizes to accommodate.
void jarray_resize_for_size(JArray *arrptr, int candidate_size) {
    if (candidate_size < arrptr->capacity) { // shrink down
        if (candidate_size < arrptr->capacity/kShrinkFactor) {
            jarray_downsize(arrptr);
        }
    } else if (candidate_size > arrptr->capacity) { // growth up
        jarray_upsize(arrptr);
    }
}

// Inserts the given value at the given index, shifting
// current and trailing elements to the right.
void jarray_insert(JArray *arrptr, int index, int value) {
    jarray_resize_for_size(arrptr, ++arrptr->size);
    for (int i = arrptr->size - 1; i > index; i--) {
        *(arrptr->data + i) = *(arrptr->data + i - 1);
    }
    *(arrptr->data + index) = value;
}

// Prepends the given value to the array, shifting trailing
// elements to the right.
void jarray_prepend(JArray *arrptr, int value) {
    jarray_insert(arrptr, 0, value);
}

// Returns the number of elements managed in the array.
int jarray_size(JArray *arrptr) {
    return arrptr->size;
}

// Returns the actual capacity the array can accommodate.
int jarray_capacity(JArray *arrptr) {
    return arrptr->capacity;
}

// Increases the array capacity determined by growth factor
void jarray_upsize(JArray *arrptr) {
    int newCap = arrptr->capacity * kGrowthFactor;
    int *newData = (int*)malloc(sizeof(int) * newCap);
    for (int i = 0; i < arrptr->size; i++) {
        *(newData + i) = *(arrptr->data + i);
    }
    free(arrptr->data);
    arrptr->data = newData;
    arrptr->capacity = newCap;
}
// Decreases the array capacity determined by growth factor
void jarray_downsize(JArray *arrptr) {
    if (arrptr->capacity == kMinCapacity) {
        return;
    }
    int newCap = arrptr->capacity / kGrowthFactor;
    int *newData = (int*)malloc(sizeof(int) * newCap);
    for (int i = 0; i < arrptr->size; i++) {
        *(newData + i) = *(arrptr->data + i);
    }
    free(arrptr->data);
    arrptr->data = newData;
    arrptr->capacity = newCap;
}

// Returns true if array is empty.
bool jarray_is_empty(JArray *arrptr) {
    return arrptr->size == 0;
}

// Prints public information about the array for debug purposes.
void jarray_print(JArray *arrptr) {
    printf("[");
    for(int i = 0; i < arrptr->size; i++) {
        printf("%u->%d, ", (unsigned int)arrptr+i, *(arrptr->data+i));
    }
    printf("]\n");
    printf("Size: %d\n", arrptr->size);
    printf("Capacity: %d\n", arrptr->capacity);
}

// Checks to see if given value is valid for memory, and exits if so
void check_address(void *p) {
    if (p == NULL) {
        printf("Can not allocate memory.\n");
        exit(EXIT_FAILURE);
    }
}

// int main(int argc, const char * argv[]) {
//     JArray *arr = jarray_new(32);
//     for (int i = 0; i < 4; i++) {
//         jarray_push(arr, i);
//         jarray_print(arr);
//     }
//     jarray_pop(arr);
//     jarray_print(arr);
//     jarray_insert(arr, 2, 2222);
//     jarray_print(arr);
//     return 0;
// }
