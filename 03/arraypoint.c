#include <stdio.h>
#include <stdlib.h>


void display_repeats(int *array, int n){
    int i;
    int j;
    int *count_arr;

    /* create count array */
    count_arr = malloc(n * sizeof count_arr[0]);
    if (NULL == count_arr){
        fprintf(stderr, "mem alloc failed\n");
        return;
    }

    /* initialise count array to zeroes */
    for (i = 0; i < n; i++){
        count_arr[i] = 0;
    }

    /* count each poss value */
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (array[j] == i){
                count_arr[i]++;
            }
        }
    }

    /* print repeated values */
    for (i = 0; i < n; i++){
        if (count_arr[i] > 1){
            printf("%d: %d\n", i, count_arr[i]);
        }
    }

    free(count_arr);
    
}


int main(void){
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    /* initialise the array to the appropriate size */
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array){
        fprintf(stderr, "memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < array_size; i++){
        my_dynamic_array[i] = rand() % array_size;
    }

    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++){
        printf("%d\n", my_dynamic_array[i]);
    }
    printf("\n");

    printf("Repeats: \n");
    display_repeats(my_dynamic_array, array_size);

    /* release the memory associated with the array */
    free(my_dynamic_array);

    return EXIT_SUCCESS;
}

