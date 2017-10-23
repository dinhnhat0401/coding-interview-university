//
//  main.c
//  algorithm
//
//  Created by Đinh Văn Nhật on 2017/10/23.
//  Copyright © 2017 Đinh Văn Nhật. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int size(int *arr) {
    int length = 0;
    int counter = 0;
    while(*(arr + counter * sizeof(int)) != 0) {
        length += 1;
    }
    return length;
}

int main(int argc, const char * argv[]) {
    int *aPointer = (int*)malloc(sizeof(int));
    *aPointer = 0;
    printf("value = %d\n", *aPointer);
    printf("address = %x\n", aPointer);
    for (int i = 1; i < 16; i++) {
        *(aPointer + sizeof(int) * i) = i;
        printf("i th value = %d\n", *(aPointer + sizeof(int) * i));
        printf("i th address = %x\n", aPointer + sizeof(int) * i);
    }
    printf("array size is %d", size(aPointer));
    return 0;
}
