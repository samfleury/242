#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib.h"

#define ARRAY_MAX 30000


static void array_print(int *a, int n){
    int i;

    for (i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
}

void merge(int *a, int *w, int n){
    int i = 0; /* index for first half of array */
    int j = n / 2; /* index for second half of array */
    int k = 0; /* index for workspace */

    while (i < n / 2 && j < n){
        if (a[i] < a[j]){
            w[k++] = a[i++];
        } else{
            w[k++] = a[j++];
        }
    }
    while (i < n / 2){
        w[k++] = a[i++];
    }
    while (j < n){
        w[k++] = a[j++];
    }
}

void merge_sort(int *a, int *w, int n){
    int i = 0;
    /* take care of stopping condition */
    if (n < 2){
        return;
    }

    merge_sort(a, w, n / 2);
    merge_sort((a + (n / 2)), (w + (n / 2)), (n - (n / 2)));

    merge(a, w, n);
    
    for (i = 0; i < n; i++){
        a[i] = w[i];
    }
}


int main(void){
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = emalloc(capacity * sizeof my_array[0]);
    int *workspace = emalloc(capacity * sizeof my_array[0]);

    
    while (1 == scanf("%d", &item)){
        if (itemcount == capacity){
            capacity += capacity;
            my_array = erealloc(my_array, capacity * sizeof my_array[0]);
            workspace = erealloc(workspace, capacity * sizeof workspace[0]);
        }
        my_array[itemcount++] = item;
    }

    
    merge_sort(my_array, workspace, itemcount);

    array_print(my_array, itemcount);
    free(my_array);
    free(workspace);
    
    return EXIT_SUCCESS;
}
