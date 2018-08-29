#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 80
#define ARRAY_LEN 10000

void *emalloc(size_t s){
    void *result = malloc(s);
    if (NULL == result){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

void sort(char *a[], int n){
    int i = 0;
    int j;
    char *key = NULL;

    for (i = 1; i < n; i++){
        key =  a[i];
        j = i - 1;

        while (j >= 0 && 0 < strcmp(a[j], key)){
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main(void){
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    int i;

    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)){
        wordlist[num_words]= emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }

    sort(wordlist, num_words);

    for (i = 0; i < num_words; i++){
        printf("%s\n", wordlist[i]);
    }

    for (i = 0; i < num_words; i++){
        free(wordlist[i]);
    }

    return EXIT_SUCCESS;

    /*
    int a[10];
    int *b = a;

    a[3] = 60;
    *(a + 3) = 60;
    *(3 + a) = 60;
    3[a] = 60;
    */
}
