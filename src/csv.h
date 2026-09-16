
#pragma once

#include <stddef.h>

typedef enum {
    BUBBLE,
    SELECT,
    INSERTION,
    QUICK,
    MERGE,
    HEAP
} ALG;

void init_csv_writer(const char* filename);

void append_line(ALG alg, size_t n_elements, double time);

void end_file_writer();