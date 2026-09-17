
#include "csv.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algos.h"

#define N_TRIES 20 // to average time on N tries for each algorithm

#define N_EL_SIZE 4
const int n_elements[] = {10, 100, 1000, 10000, 100000, 1000000};

#define N_ALGS 6
void(*algorithms[])(int*, size_t) = {
    bubble_sort,
    select_sort,
    insertion_sort,
    quick_sort,
    merge_sort,
    heap_sort
};

int main() {
    srand(time(NULL)); // init random generator

    init_csv_writer("data.csv");
    
    for (int i = 0; i < N_ALGS; i++) {
        for (int j = 0; j < N_EL_SIZE; j++) {
            for (int k = 0; k < N_TRIES; k++) {
                int* array = malloc(sizeof(int)* n_elements[j]);
                for (int l = 0; l < n_elements[j]; l++) array[l] = l+1;
                shuffle(array, n_elements[j]);
                append_line((ALG)i, n_elements[j], measure_time(array, n_elements[j], algorithms[i]));
                free(array);
            }
        }
    }
    end_file_writer();
    return 0;
}