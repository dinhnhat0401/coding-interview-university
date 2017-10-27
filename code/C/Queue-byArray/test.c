#include "test.h"

void run_all_tests() {
    test_all();
    printf("All test completed successfully");
}

void test_all() {
    Queue *q = initialize();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 44);
    assert(dequeue(q) == 1);
    enqueue(q, 55);
    enqueue(q, 66);
    assert(dequeue(q) == 2);
    enqueue(q, 100);
    enqueue(q, 200);
    assert(dequeue(q) == 44);
}