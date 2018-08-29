#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000

void selection_sort(int *a, int n){
    int i;
    int j;
    int temp;
    int smallestPos;

    /* for each position, starting from the first */
    for (i = 0; i < n - 1; i++){
        smallestPos = i;
        /* look for smallest value, starting at the left,
           comparing with every other */
        for (j = i; j < n; j++){
            if (a[j] < a[smallestPos]){
                smallestPos = j;
            }
        }
        /* swap smallest into correct position */
        temp = a[i];
        a[i] = a[smallestPos];
        a[smallestPos] = temp;
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
    selection_sort(my_array, count);
    end = clock();

    for (i = 0; i < count; i++){
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
