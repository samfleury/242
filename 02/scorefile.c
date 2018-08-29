#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    double s1, s2, s3;
    double result;
    int high_n = 0;
    double high_score = 0.0;
        
    while (4 == scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3)){   
        if (s1 < s2 && s1 < s3){
            result = (s2 + s3) / 2;
        } else if (s2 < s1 && s2 < s3){
            result = (s1 + s3) / 2;
        } else{
            result = (s1 + s2) / 2;
        }

        if (result > high_score){
            high_n = n;
            high_score = result;
        }
    }

    printf("Winner is: %d with %f points\n", high_n, high_score);

    return EXIT_SUCCESS;
}
