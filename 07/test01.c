#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_LEN 100
#define BUFF_SIZE 80

/* error-checking malloc */
/* returns a void pointer, takes a size_t */
void *emalloc(size_t s){
    /* call to regular malloc */
    void *result = malloc(s);
    /* check malloc result */
    if (NULL == result){
        fprintf(stderr, "Can't allocate mem\n");
        /* can just call exit like this, passing exit status */
        exit(EXIT_FAILURE);
    }
    /* if doesn't fail, just return the memory. */
    return result;
}


/* recursive call for printing, taking an array of char pointers, array length, and avg word length */
void print_big_words(char **words, int len, double average){
    /* check that there are words left to print (i.e. BASE CASE */
    if (len > 0){
        /* if first word of array is above average, print it */
        if (strlen(words[0]) > average){
            printf("%s\n", words[0]);
        }
        /* recursive call: make array one smaller, make length one smaller, leave average */
        print_big_words(words + 1, len - 1, average);
    }
}


int main(void){
    char *words[ARRAY_LEN]; /* words array */
    char word[BUFF_SIZE]; /* buffer to hold word while allocating memory in array for it */
    int count = 0; /* count num words */
    double average = 0.0; /* hold average word length */
    int i;

    /* take in words */
    while (count < ARRAY_LEN && 1 == scanf("%79s", word)){
        /* hold each word in buffer while allocating memory for it */
        words[count] = emalloc((strlen(word) + 1) * sizeof word[0]);
        /* once allocated, copy word into memory */
        strcpy(words[count++], word);
        /* don't forget to increment sum */
        average += strlen(word);
    }

    /* if there are any words in the array, */
    if (count > 0){
        /* calculate average */
        average /=  count;
        /* print average to stderr */
        fprintf(stderr, "%.2f\n", average);
        /* call recursive method */
        print_big_words(words, count, average);
    }

    /* free words array */
    for (i = 0; i < count; i++){
        free(words[i]);
    }
    
    /*
      for ( i = 0; i < count; i++){
    printf("%d %s\n", i, words[i]);
        }
    */

    return EXIT_SUCCESS;
}
