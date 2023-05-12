//
// Created by avebh on 12.05.2023.
//

#include <stdbool.h>

#ifndef LAB_V_VECTOR_H
#define LAB_V_VECTOR_H

#endif //LAB_V_VECTOR_H

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);
void reserve(vector *v, size_t newCapacity);
void clear(vector *v);
void shrinkToFit(vector *v);
void deleteVector(vector *v);

bool isEmpty(vector *v);
bool isFull(vector *v);
