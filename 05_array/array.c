//
// Created by xuteng on 2021/3/26.
//
#include "stdio.h"
#include "stdlib.h"
#include "array.h"

void dump(struct array *array){
    int idx;
    for(idx = 0 ; idx < array->used; idx++){
        printf("[%02d]: %08d\n", idx, array->arr[idx]);
    }
}

struct array create(int size){
    struct array arrayTemp = {size, 0,  (int*)calloc(size , sizeof(int ))};
    return arrayTemp;
}

int insert(struct array *array, int elem){
    if(array->used >= array->size){
        return -1;
    }
    array->arr[array->used++] = elem;
    return array->used;
}

int search(struct array *array, int idx){
    if(idx > array->used || idx < 0){
        return -1;
    }
    return array->arr[idx];
}

int del(struct array *array, int idx){
    if(idx > array->used || idx < 0){
        return -1;
    }

    for(; idx < array->size; idx ++){
        array->arr[idx] = array->arr[idx + 1];
    }
    array->used--;
    return 1;
}

void arrayMain(){
    struct array arr = create(10);

    insert(&arr, 1);
    insert(&arr, 3);
    insert(&arr, 2);
    printf("=== insert 1, 3, 2\n");
    dump(&arr);

    printf("=== delete [6] element \n");
    del(&arr, 6);
    dump(&arr);
    printf("=== delete [0] element \n");
    del(&arr, 0);
    dump(&arr);
}