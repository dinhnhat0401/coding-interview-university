#include "test.h"

void run_all_tests() {
    test_all();
    printf("All test completed successfully");
}

void test_all() {
    Queue *q = initialize();
    assert(empty(q));
    enqueue(q, 12);
    enqueue(q, 2);
    enqueue(q, 20);
    assert(dequeue(q) == 12);
    assert(dequeue(q) == 2);
    assert(dequeue(q) == 20);
    empty(q);
    destroyQueue(q);
}