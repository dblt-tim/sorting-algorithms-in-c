
#include "helpers.h"

#include <stdlib.h>
#include <time.h>

void swap_values(int * val1, int * val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void shuffle(int* array, size_t size)
{
    for (int i = 0; i < size; i++) {
        swap_values(array + i, array + rand()%size);
    }
}

double measure_time(int* array, size_t size, void(*alg)(int*,size_t))
{
    clock_t before = clock();

    alg(array, size);

    clock_t delta = clock() - before;

    return ((double)delta / CLOCKS_PER_SEC);
}

bool is_sorted(int* tab, size_t size) {
    for (size_t i = 0; i < size-1; i++) {
        if (tab[i+1] < tab[i]) return false;
    }
    return true;
}