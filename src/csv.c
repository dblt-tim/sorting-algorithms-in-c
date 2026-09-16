
#include <stdlib.h>
#include <stdio.h>

#include "csv.h"

static const char* algs[] = {
    "bubble_sort",
    "selection_sort",
    "insertion_sort",
    "quick_sort",
    "merge_sort",
    "heap_sort"
};

FILE* csv_file = NULL;

void init_csv_writer(const char* filename) 
{
    csv_file = fopen(filename, "w");
    fprintf(csv_file, "algorithm;number of elements;time spent\n");
}

void append_line(ALG alg, size_t n_elements, double time)
{
    if (!csv_file) return;
    
    fprintf(csv_file, "%s;%ld;%lf\n",
        algs[alg],
        n_elements,
        time
    );
}

void end_file_writer() {
    fclose(csv_file);
}