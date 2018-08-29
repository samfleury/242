#include <stdlib.h>
#include <stdio.h>

int main(void){
    int n;
    double s1, s2, s3;
    double score;
    int hi_n;
    double hi_score;

    while (4 == scanf("%d%lg%lg%lg", &n, &s1, &s2, &s3)){
        if (s1 < s2 && s1 < s3){
            score = (s2 + s3) / 2;
        } else if (s2 < s1 && s2 < s3){
            score = (s1 + s3) / 2;
        } else{
            score = (s1 + s2) / 2;
        }

        if (score > hi_score){
            hi_n = n;
            hi_score = score;
        }
    }

    printf("%d\n", hi_n);

    return EXIT_SUCCESS;
    
}
