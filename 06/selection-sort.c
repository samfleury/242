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


/* something is fakakta here */
int binary_search(int *a, int l, int r, int target){
    if (r >= l){
        int mid = l + (r - l) / 2;

        /* if target is mid */
        if (a[mid] == target){
            return 1;
        }

        /* if target is smaller than mid, must be in left subarray */
        if (a[mid] > target){
            return binary_search(a, l, mid - 1, target);
        }

        /* else could only be present in right subarry */
        return binary_search(a, mid + 1, r, target);
    }

    return 0;
}

int main(int argc, char **argv){
    FILE *infile;
    int my_array[ARRAY_MAX];
    int count = 0;
    int int_to_find;
    
    /* check file stream */
    if (NULL == (infile = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }
    /* take in data */
    while (count < ARRAY_MAX && 1 == fscanf(infile, "%d", &my_array[count])){
        count++;
    }
    /* close file */
    fclose(infile);
    
    /* sort it out */
    selection_sort(my_array, count);

    /* input loop */
    while (1 == scanf("%d", &int_to_find)){
        if(binary_search(my_array, 0, count, int_to_find)){
            printf("+\n");
        } else{
            printf("-\n");
        }
    }
    
    return EXIT_SUCCESS;
}
