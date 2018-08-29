#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

/* ASK: call by value, "revert to their original values", p. 58 */

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
    int my_array[ARRAY_MAX];
    int workspace[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }

    start = clock();
    merge_sort(my_array, workspace, count);
    end = clock();

    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
