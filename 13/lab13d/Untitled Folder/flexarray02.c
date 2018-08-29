#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec{
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
    if (NULL== result){
        fprintf(stderr, "mem alloc fail");
        exit(EXIT_FAILURE);
    }
    return result;
}
    
flexarray flexarray_new(){
    /* initialise flexarray structure */
    flexarray f = emalloc(sizeof *f);
    f->capacity = 2;
    f->itemcount = 0;
    f->items = emalloc(f->capacity * sizeof f->items[0]);
    return f;
}

void flexarray_append(flexarray f, int num){
    /* add an item to the flexarray, expanding as necessary */
    if (f->itemcount == f->capacity){
        f->capacity *=2;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
    
}

void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
    int i;
    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}
void flexarray_sort(flexarray f) {
    /* sort into ascending order */
    int i, j, key;

    for (i = 1; i < f->itemcount; i++){

        if (i == f->itemcount / 2){
            for (j = 0; j < f->itemcount; j++){
                fprintf(stderr, "%d\n", f->items[j]);
            }
        }
        
        key = f->items[i];
        j = i - 1;

        while (j >= 0 && f->items[j] > key){
            f->items[j+1] = f->items[j];
            j--;
        }
        f->items[j+1] = key;
    }
}
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
    free(f->items);
    free(f);
}
