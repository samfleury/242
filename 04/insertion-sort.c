#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void insertion_sort(int *a, int n){
    int i;
    int key;
    int j;

    /* for each position starting from the second */
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;

        /* compare to every item to the left, moving them along
           until it finds the correct position.
           Only has to compare til it finds the right spot.*/
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }

        /* put the value into the correct place */
        a[j + 1] = key;
    }
}

int main(void){
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])){
        count++;
    }

    start = clock();
    insertion_sort(my_array, count);
    end = clock();

    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
