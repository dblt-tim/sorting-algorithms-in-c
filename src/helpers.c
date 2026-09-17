
#include "helpers.h"

#include <stdlib.h>
#include <stdio.h>
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
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    alg(array, size);

    clock_gettime(CLOCK_MONOTONIC, &end);

    
    double elapsed = (end.tv_sec - start.tv_sec) +
                      (end.tv_nsec - start.tv_nsec) / 1e9;
    
}

bool is_sorted(int* arr, size_t size) {
    for (size_t i = 0; i < size-1; i++) {
        if (arr[i+1] < arr[i]) return false;
    }
    return true;
}

void print_list(int* arr, size_t size)
{
    printf("[");

    for (int i = 0; i < size - 1; i++) printf("%d, ", arr[i]);
    printf("%d]\n", arr[size-1]);
}