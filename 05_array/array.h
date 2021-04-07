//
// Created by xuteng on 2021/3/26.
//

#ifndef DATA_STRUCTURE_ARRAY_H
#define DATA_STRUCTURE_ARRAY_H

#include "stdio.h"
#include "stdlib.h"

struct array{
    int size;
    int used;
    int *arr;
};

void dump(struct array *array);

struct array create(int size);

int insert(struct array *array, int elem);

int search(struct array *array, int idx);

int del(struct array *array, int idx);

void arrayMain();

#endif //DATA_STRUCTURE_ARRAY_H