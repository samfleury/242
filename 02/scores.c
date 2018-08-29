#include <stdio.h>
#include <stdlib.h>

int main(void){
    double s1;
    double s2;
    double s3;
    int return_code;
    double result;

    printf("Enter three floating-point numbers: \n");
    fflush(stdout);

    return_code = scanf("%lg%lg%lg", &s1, &s2, &s3);
    if (return_code != 3){
        printf("scanf returned code %d\n", return_code);
        return EXIT_FAILURE;
    }

    if (s1 < s2 && s1 < s3){
        result = (s2 + s3) / 2;
        printf("%f\n", result);
    } else if (s2 < s1 && s2 < s3){
        result = (s1 + s3) / 2;
        printf("%f\n", result);
    } else{
        result = (s1 + s2) / 2;
        printf("%f\n", result);
    }

    return EXIT_SUCCESS;
}
