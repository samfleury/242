#include <stdlib.h>
#include <stdio.h>

void display_repeats(int *array, int n){
    int *count_arr;
    int i, j;

    count_arr = malloc(n * sizeof count_arr[0]);
    if (count_arr == NULL){
        fprintf(stderr, "mem alloc failed\n");
        return;
    }

    for (i = 0; i < n; i++){
        count_arr[i] = 0;
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if (array[j] == i){
                count_arr[i]++;
            }
        }
    }

    for (i = 0; i < n; i++){
        if (count_arr[i] > 1){
            printf("%d occurs %d times\n", i, count_arr[i]);
        }
    }

    free(count_arr);
}

int main(void) {
    int array_size = 0;
    int *my_array;
    int i = 0;
    printf("Enter the size of the array:\n");
    scanf("%d", &array_size);
    my_array = malloc(array_size * sizeof my_array[0]);
    if (NULL == my_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < array_size; i++) {
        my_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    display_repeats(my_array, array_size);
    free(my_array);
    return EXIT_SUCCESS;

}
