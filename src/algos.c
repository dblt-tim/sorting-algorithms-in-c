
#include "algos.h"
#include "helpers.h"

#include <stdio.h>

void bubble_sort(int* tab, size_t size)
{
    bool is_sorted = false;
    
    while (!is_sorted) {
        is_sorted = true;
        
        for (size_t i = 0; i < size-1; i++) {
            if (tab[i+1] < tab[i]) {
                swap_values(tab+i, tab+i+1); // swap tab[i] and tab[i+1]
                is_sorted = false;
            }
        } // if no value have been swapped then the sort is finished
    }
}

void select_sort(int* tab, size_t size)
{
    for (int i = 0; i < size; i++) {
        size_t min_index = i;
        int min = tab[i];

        for (int j = i; j < size; j++) { // find the minimum value and its index
            if (tab[j] < min) {
                min = tab[j];
                min_index = j;
            }
        }
        swap_values(tab+i, tab+min_index); // swap tab[i] and tab[min_index]
    }
}

void insertion_sort(int* tab, size_t size)
{
    for (size_t i = 1; i < size; i++) { // loop starts at one as we assume the first value is "sorted"
        int hostage = tab[i];

        for (size_t j = i-1; j >= 0; j--) { // we go right to left of the array starting from i-1
            if (tab[j] < hostage) { // we let bigger values go past
                tab[j+1] = hostage;
                break;
            } else { // once all the bigger values have gone past we put back the hostage
                tab[j+1] = tab[j];
                if (j == 0) tab[j] = hostage; // this is necessary as the hostage won't be placed 
                                              // back on the front of the array by itself
                                              // because we cannot be at tab[-1]
            }
        }
    }
}

void quick_sort(int* tab, size_t size)
{
    // TODO
}

void fusion_sort(int* tab, size_t size)
{
    // TODO
}

void heap_sort(int* tab, size_t size)
{
    // TODO
}