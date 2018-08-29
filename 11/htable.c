#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "htable.h"

struct htablerec{
    int* freqs;
    char** keys;
    int num_keys;
    int capacity;
};

static unsigned int htable_word_to_int(char* word){
    unsigned int result = 0;

    while (*word != '\0'){
        result = (*word++ + 31 * result);
    }
    return result;
}

static unsigned int htable_step(htable h, unsigned int i_key) {
    return 1 + (i_key % (h->capacity - 1));
}

void htable_free(htable h){
    int i;
    for (i = 0; i < h->capacity; i++){
        if (h->keys[i] != NULL){
            free(h->keys[i]);
        }
    }
    free(h->keys);
    free(h->freqs);
    free(h);
}


int htable_insert(htable h, char *str){
    int count  = 0;
    unsigned int to_add = htable_word_to_int(str);
    unsigned int step = htable_step(h, to_add);
    to_add = to_add % h->capacity;
    while (count < h->capacity){
        if (h->keys[to_add] == NULL){ /* if space is empty */
            h->keys[to_add] = emalloc((strlen(str) + 1) * sizeof h->keys[to_add][0]);
            strcpy(h->keys[to_add], str);
            h->freqs[to_add]++;
            return 1;
        } else if(strcmp(h->keys[to_add], str) == 0){ /* else if space has same word */
            h->freqs[to_add]++;
            return h->freqs[to_add];
        }else{ /* otherwise collision */
            to_add = (to_add + step) % h->capacity;
            count++;
        }
    }
    return 0;
}


htable htable_new(int capacity){
    int i;
    htable h = emalloc(sizeof *h);
    h->capacity = capacity;
    h->num_keys = 0;
    h->freqs = emalloc(h->capacity * sizeof h->freqs[0]);
    h->keys = emalloc(h->capacity * sizeof h->keys[0]);

    for (i = 0; i < h->capacity; i++){
        h->freqs[i] = 0;
        h->keys[i] = NULL;
    }
    return h;
}

void htable_print(htable h, FILE *stream){
    int i;
    for (i = 0; i < h->capacity; i++){
        if(h->keys[i] != NULL){
            fprintf(stream, "%5d %s\n", h->freqs[i], h->keys[i]);
        }
    }
}

int htable_search(htable h, char *str){
    int colls = 0;
    unsigned int index = htable_word_to_int(str);
    unsigned int step = htable_step(h, index);
    index = index % h->capacity;
    while (h->keys[index] != NULL && strcmp(h->keys[index], str) != 0 && colls < h->capacity){
        colls++;
        index = (index + step) % h->capacity;
    }
    if (colls == h->capacity){
        return 0;
    } else{
        return h->freqs[index];
    }
}
