#include <stdlib.h>
#include <stdio.h>

int main(void){
    int n;
    double s1, s2, s3;
    double result;
    int hi_n = 0;
    double hi_score = 0.0;

    while (4 == scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3)){
        if (s1 < s2 && s1 < s3){
            result = (s2 + s3) / 2;
        } else if (s2 < s1 && s2 < s3){
            result = (s1 + s3) / 2;
        } else{
            result = (s1 + s2) / 2;
        }

        if (result > hi_score){
            hi_n = n;
            hi_score = result;
        }
    }

    printf("%d\n", hi_n);
    return EXIT_SUCCESS;
}
