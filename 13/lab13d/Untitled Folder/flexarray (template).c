#include <stdio.h>
#include <stdlib.h>
#include "flexarray.h"

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
}
    
    flexarray flexarray_new(){
        /* initialise flexarray structure */    
    }

void flexarray_append(flexarray f, int num){
    /* add an item to the flexarray, expanding as necessary */
}

void flexarray_print(flexarray f) {
    /* a "for" loop to print out each cell of f->items */
}
void flexarray_sort(flexarray f) {
    /* sort into ascending order */
}
void flexarray_free(flexarray f) {
    /* free the memory associated with the flexarray */
}
