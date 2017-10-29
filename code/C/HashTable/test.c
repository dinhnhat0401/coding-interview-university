#include "test.h"

void test_all() {
    test_add_get();
    test_exists_remove();
}

void test_add_get() {
    HashTable *t = initialize(kTableSize);
    add(t, "Viet Nam", "Ha Noi");
    add(t, "Viet Nam", "Ha Noi 2");
    add(t, "Japan", "Tokyo");
    add(t, "Germany", "Berlin");
    add(t, "Holland", "Amsterdam");
    add(t, "China", "Beijing");
    add(t, "France", "Paris");
    add(t, "Brasil", "Sao Paulo");
    add(t, "HongKong", "HongKong");
    add(t, "Cambodia", "Cambodia");
    assert(strcmp(get(t, "Viet Nam"), "Ha Noi 2") == 0);
    assert(strcmp(get(t, "China"), "Beijing") == 0);
    assert(strcmp(get(t, "HongKong"), "HongKong") == 0);
    assert(strcmp(get(t, "Cambodia"), "Cambodia") == 0);
    printf("ADD GET test completed!\n");
}

void test_exists_remove() {
    HashTable *t = initialize(kTableSize);
    add(t, "Viet Nam", "Ha Noi");
    add(t, "Viet Nam", "Ha Noi 2");
    add(t, "Japan", "Tokyo");
    add(t, "Germany", "Berlin");
    add(t, "Holland", "Amsterdam");
    add(t, "China", "Beijing");
    add(t, "France", "Paris");
    add(t, "Brasil", "Sao Paulo");
    add(t, "HongKong", "HongKong");
    add(t, "Cambodia", "Cambodia");
    removeKey(t, "Japan");
    assert(exists(t, "Japan") == false);
    printf("REMOVE EXISTS test completed!\n");
}
