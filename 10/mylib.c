#include <stdio.h> /* for printf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include "mylib.h"

void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Mem alloc failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void *erealloc(void *p, size_t s){
    void *result = realloc(p, s);
    if (NULL == result){
        fprintf(stderr, "Mem realloc failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
