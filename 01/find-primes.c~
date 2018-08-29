#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){

    /* variable declarations */
    int i = 0;
    int f = 0;
    int g = 1;
    int temp;

    for (i = 0; i < 40; i++){
        printf("%10d  ", g);
        temp = g;
        g += f;
        f = temp;

        if ((i + 1) % 5 == 0){
            printf("\n");
        }
    }

    return EXIT_SUCCESS; /* defined in stdlib.h */
}
