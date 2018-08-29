#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"

int main(int argc, char **argv){
    htable h = htable_new(*argv[1]);
    char word[256];

    while (getword(word, sizeof word, stdin) != EOF){
        htable_insert(h, word);
    }

    htable_print(h, stdout);
    htable_free(h);

    return EXIT_SUCCESS;
}
