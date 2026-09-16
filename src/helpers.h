
#pragma once
#include <stddef.h>
#include <stdbool.h>

// helper functions for the program

void swap_values(int * val1, int * val2);

void shuffle(int* array, size_t size);

double measure_time(int* array, size_t size, void(*alg)(int*,size_t));

bool is_sorted(int* tab, size_t size);

void print_list(int* tab, size_t size);