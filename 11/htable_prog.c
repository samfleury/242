#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "htable.h"

int main(void){
    htable table = htable_new(2);
    htable_insert(table, "hector");
    htable_insert(table, "willard");
    htable_insert(table, "hector");
    htable_insert(table, "ponzi");
    htable_insert(table, "bilf");
    htable_print(table, stdout);
    htable_free(table);
    return EXIT_SUCCESS;
}
