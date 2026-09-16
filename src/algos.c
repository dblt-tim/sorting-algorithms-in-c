
#include "algos.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    // recursive break case
    if (size == 1) return;
    if (size <= 2) {
        if (tab[1] < tab[0]) swap_values(tab, tab+1);
        return;
    }
    
    // choose pivot, arbitrary I'm taking the middle of the array
    // and we put it in the end of the array
    size_t index_pivot = size / 2;
    int pivot = tab[index_pivot];

    swap_values(tab + index_pivot, tab + size - 1);

    // then partition the array to put all lesser values than the pivot to the left
    size_t walker = 0;

    for (size_t runner = 0; runner < size; runner++) {
        if (tab[runner] < pivot) {
            swap_values(tab + walker, tab + runner);
            walker++;
        }
    }
    // then we get the pivot back to where it should be
    swap_values(tab + walker, tab + size - 1);

    // then partition smaller portions of the array
    quick_sort(tab, walker);
    quick_sort(tab + walker + 1, size - walker - 1);
}

void merge_sort(int* tab, size_t size)
{
    // recursive break case
    if (size == 1) return;
    if (size == 2) {
        if (tab[0] > tab[1]) swap_values(tab, tab+1);
        return;
    }

    size_t middle = size / 2;
    merge_sort(tab, middle);
    merge_sort(tab + middle, size - middle);

    int* left = malloc(sizeof(int) * middle);
    int* right = malloc(sizeof(int) * (size - middle));

    for (int i = 0; i < middle; i++) {
        left[i] = tab[i];
    }
    for (int i = 0; i < size - middle; i++) {
        right[i] = (tab+middle)[i];
    }

    int* left_walker = left;
    int* right_walker = right;

    for (size_t i = 0; i < size; i++) {
        if (left_walker >= left + middle) {
            tab[i] = *right_walker++;
            continue;
        }
        if (right_walker >= right + size - middle) {
            tab[i] = *left_walker++;
            continue;
        }
        if (*left_walker < *right_walker)
            tab[i] = *left_walker++;
        else tab[i] = *right_walker++;
    }

    free(left);
    free(right);
}

void heap_sort(int* tab, size_t size)
{
    // TODO
}