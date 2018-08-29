#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;
    int y;
    double conc;
};

void print_ocean_datum(struct ocean_datum *o){
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum *o){
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

void sort_ocean_data(struct ocean_datum a[], int n){
    int i;
    int j;
    struct ocean_datum key;

    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j].conc > key.conc){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }
}

void print_array(struct ocean_datum a[], int n){
    if (n > 0){
        print_ocean_datum(&a[0]);
        print_array(a + 1, n - 1);
    }
}

int main(void){
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;

    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])){
        num_items++;
    }

    /*  sort data here */
    sort_ocean_data(ocean_data, num_items);

    /* print array of structs  */
    print_array(ocean_data, num_items);

    return EXIT_SUCCESS;
}
