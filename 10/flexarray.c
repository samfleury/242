#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "flexarray.h"

static void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

static void quicksort(int arr[], int length){
    int partition; /* value of partition item */
    int i, j; /* iterators */
    int r_len, l_len; /* lengths of the subarrays */
    int *r_array, *l_array; /* pointers to subarrays */

    /* stopping condition */
    if (length < 2){
        return;
    }

    partition = *arr; /* take first element as partition */
    i = 1; /* 1 because array[0] is the partition */

    /* puts partition into the right place */
    for (j = 1; j <= length; j++){
        if (*(arr + j) < partition){
            swap((arr + i), (arr + j));
            i++;
        }
    }

    swap(arr, (arr + i - 1));

    /* recursive calls */
    
    l_len = i - 1;
    l_array = arr;
    r_len = length - i;
    r_array = (arr + i);

    quicksort(l_array, l_len);
    quicksort(r_array, r_len);
    
}

struct flexarrayrec{
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new(){
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

void flexarray_append(flexarray f, int num){
    if (f->itemcount == f->capacity){
        f->capacity *= 2;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f){
    int i;

    for (i = 0; i < f->itemcount; i++){
        printf("%d\n", f->items[i]);
    }
}

void flexarray_sort(flexarray f){
    quicksort(f->items, f->itemcount);
}

void flexarray_free(flexarray f){
    free(f->items);
    free(f);
}

