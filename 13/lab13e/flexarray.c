#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "mem alloc fail");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result){
        fprintf(stderr, "mem alloc fail");
        exit(EXIT_FAILURE);
    }
    return result;
}

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}
void flexarray_append(flexarray f, int num) {
    if (f->itemcount == f->capacity) {
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}
void flexarray_print(flexarray f) {
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    int i, j, temp, smallestPos;

    for (i = 0; i < f->itemcount; i++){

        if (i == f->itemcount /2){
            for (j = 0; j < f->itemcount; j++){
                fprintf(stderr, "%d\n", f->items[j]);
            }
        }
        
        smallestPos = i;
        for (j = i; j < f->itemcount; j++){
            if (f->items[j] < f->items[smallestPos]){
                    smallestPos = j;
                }
        }
        temp = f->items[i];
        f->items[i] = f->items[smallestPos];
        f->items[smallestPos] = temp;
    }
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);
}
