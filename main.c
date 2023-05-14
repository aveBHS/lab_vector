#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector source = createVector(0);
    pushBack(&source, 1);

    vector expected_result = (vector) {(int[]) {1}, 1, 1};
    assert(isVectorsEqual(&source, &expected_result));
}

void test_pushBack_fullVector() {
    vector source = createVector(3);

    pushBack(&source, 1);
    pushBack(&source, 2);
    pushBack(&source, 3);
    pushBack(&source, 4);

    vector expected_result = (vector) {(int[]) {1, 2, 3, 4}, 4, 6};
    assert(isVectorsEqual(&source, &expected_result));
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);

    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}


void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();
    return 0;
}
