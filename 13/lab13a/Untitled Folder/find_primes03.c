#include <stdlib.h>
#include <stdio.h>

int is_prime(int candidate){
    int n = 2;

    for (n = 2; n < candidate; n++){
        if (candidate % n == 0){
            return 0;
        }
    }
    return 1;
}

int main(void){
    int candidate = 2;
    int num_printed = 0;

    while (num_printed < 200){
        if (is_prime(candidate)){
            printf("%5d", candidate);
            num_printed++;
            if (num_printed % 10 == 0){
                printf("\n");
            }
        }
        candidate++;
    }

    return EXIT_SUCCESS;
}
