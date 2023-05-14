#include <stdio.h>
#include <stddef.h>
#include "vector.h"
#include <malloc.h>
#include <assert.h>

vector createVector(size_t n) {
    int *data = malloc(sizeof (int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        v->data = NULL;
        return;
    }

    realloc(v->data, sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    v->capacity = newCapacity;
    if (v->size > newCapacity) {
        v->size = newCapacity;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v);
}

bool isEmpty(vector *v) {
    return !v->size;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if(isFull(v)) {
        reserve(v, v->size > 0 ? v->size * 2 : 1);
    }

    v->data[v->size++] = x;
}

void popBack(vector *v) {
    assert(!isEmpty(v));
    v->size--;
}

bool isVectorsEqual(vector *v1, vector *v2) {
    if (v1->size == v2->size && v1->capacity == v2->capacity) {
        for (int i = 0; i < v1->size; i++) {
            if (getVectorValue(v1, i) != getVectorValue(v2, i)) {
                return false;
            }
        }
    } else {
        return false;
    }

    return true;
}