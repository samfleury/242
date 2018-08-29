#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n;
    double s1[10], s2[10], s3[10];
    int i = 0;
    int j;
    double avg = 0;
    double dist = 0.0;
        
    while (4 == scanf("%d%lg%lg%lg", &n, &s1[i], &s2[i], &s3[i])){   
        i++;
    }

    printf("          Avg.           SD\n");

    
    /* Calculate avg */
    for (j = 0; j < i; j++){
        avg += s1[j];
    }

    avg /= i;

    /* Calc dist squared from avg for each score */
    for (j = 0; j < i; j++){
        dist += pow((s1[j] - avg), 2);
    }

    dist = sqrt(dist/(i - 1));

    printf("judge 1 : %f       %f\n", avg, dist);

    /* JUDGE 2 */
    avg = 0;
    dist = 0;
    
    /* Calculate avg */
    for (j = 0; j <= i; j++){
        avg += s2[j];
    }

    avg /= i + 1;

    /* Calc dist squared from avg for each score */
    for (j = 0; j <= i; j++){
        dist += pow((s2[j] - avg), 2);
    }

    dist = sqrt(dist/i);

    printf("judge 2 : %f       %f\n", avg, dist);

    
    /* JUDGE 3 */
    avg = 0;
    dist = 0;
    
    /* Calculate avg */
    for (j = 0; j <= i; j++){
        avg += s3[j];
    }

    avg /= i + 1;

    /* Calc dist squared from avg for each score */
    for (j = 0; j <= i; j++){
        dist += pow((s3[j] - avg), 2);
    }

    dist = sqrt(dist/i);

    printf("judge 3 : %f       %f\n", avg, dist);

    return EXIT_SUCCESS;
}
