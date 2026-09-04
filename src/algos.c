
#include "algos.h"
#include "helpers.h"

#include <stdio.h>

void bubble_sort(int* tab, size_t size)
{
    while (!is_sorted(tab, size)) {
        for (size_t i = 0; i < size-1; i++) {
            if (tab[i+1] < tab[i]) swap_values(tab+i, tab+i+1);
        }
    }
}

void select_sort(int* tab, size_t size)
{
    for (int i = 0; i < size; i++) {
        size_t min_index = i;
        int min = tab[i];

        for (int j = i; j < size; j++) {
            if (tab[j] < min) {
                min = tab[j];
                min_index = j;
            }
        }
        swap_values(tab+i, tab+min_index);
    }
}

void insertion_sort(int* tab, size_t size)
{
    for (size_t i = 1; i < size; i++) {
        int hostage = tab[i];

        for (size_t j = i-1; j >= 0; j--) {
            if (tab[j] < hostage) {
                tab[j+1] = hostage;
                break;
            } else {
                tab[j+1] = tab[j];
                if (j == 0) tab[j] = hostage;
            }
        }
    }
}

void quick_sort(int* tab, size_t size)
{
    
}

void fusion_sort(int* tab, size_t size)
{
    
}

void heap_sort(int* tab, size_t size)
{
    
}