
#include "algos.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int* arr, size_t size)
{
    bool is_sorted = false;
    
    while (!is_sorted) {
        is_sorted = true;
        
        for (size_t i = 0; i < size-1; i++) {
            if (arr[i+1] < arr[i]) {
                swap_values(arr+i, arr+i+1); // swap arr[i] and arr[i+1]
                is_sorted = false;
            }
        } // if no value have been swapped then the sort is finished
    }
}

void select_sort(int* arr, size_t size)
{
    for (int i = 0; i < size; i++) {
        size_t min_index = i;
        int min = arr[i];

        for (int j = i; j < size; j++) { // find the minimum value and its index
            if (arr[j] < min) {
                min = arr[j];
                min_index = j;
            }
        }
        swap_values(arr+i, arr+min_index); // swap arr[i] and arr[min_index]
    }
}

void insertion_sort(int* arr, size_t size)
{
    for (size_t i = 1; i < size; i++) { // loop starts at one as we assume the first value is "sorted"
        int hostage = arr[i];

        for (size_t j = i-1; j >= 0; j--) { // we go right to left of the array starting from i-1
            if (arr[j] < hostage) { // we let bigger values go past
                arr[j+1] = hostage;
                break;
            } else { // once all the bigger values have gone past we put back the hostage
                arr[j+1] = arr[j];
                if (j == 0) arr[j] = hostage; // this is necessary as the hostage won't be placed 
                                              // back on the front of the array by itself
                                              // because we cannot be at arr[-1]
            }
        }
    }
}

void quick_sort(int* arr, size_t size)
{
    // recursive break case
    if (size == 1) return;
    if (size <= 2) {
        if (arr[1] < arr[0]) swap_values(arr, arr+1);
        return;
    }
    
    // choose pivot, arbitrary I'm taking the middle of the array
    // and we put it in the end of the array
    size_t index_pivot = size / 2;
    int pivot = arr[index_pivot];

    swap_values(arr + index_pivot, arr + size - 1);

    // then partition the array to put all lesser values than the pivot to the left
    size_t walker = 0;

    for (size_t runner = 0; runner < size; runner++) {
        if (arr[runner] < pivot) {
            swap_values(arr + walker, arr + runner);
            walker++;
        }
    }
    // then we get the pivot back to where it should be
    swap_values(arr + walker, arr + size - 1);

    // then partition smaller portions of the array
    quick_sort(arr, walker);
    quick_sort(arr + walker + 1, size - walker - 1);
}

void merge_sort(int* arr, size_t size)
{
    // recursive break case
    if (size == 1) return;
    if (size == 2) {
        if (arr[0] > arr[1]) swap_values(arr, arr+1);
        return;
    }

    size_t middle = size / 2;
    merge_sort(arr, middle); // sort left half
    merge_sort(arr + middle, size - middle); // sort right half

    // allocate and fill temporary lists
    int* left = malloc(sizeof(int) * middle);
    int* right = malloc(sizeof(int) * (size - middle));

    for (int i = 0; i < middle; i++) {
        left[i] = arr[i];
    }
    for (int i = 0; i < size - middle; i++) {
        right[i] = (arr+middle)[i];
    }

    // copy the pointers to walk them
    int* left_walker = left;
    int* right_walker = right;

    for (size_t i = 0; i < size; i++) {
        if (left_walker >= left + middle) { // if no more values in left
            arr[i] = *right_walker++;
            continue;
        }
        if (right_walker >= right + size - middle) { // if no more values in right
            arr[i] = *left_walker++;
            continue;
        }
        if (*left_walker < *right_walker) // last case
            arr[i] = *left_walker++;
        else arr[i] = *right_walker++;
    }

    // free allocated arrays
    free(left);
    free(right);
}


// heavily inspired by https://www.geeksforgeeks.org/c/c-program-for-heap-sort/
void make_heap(int* arr, size_t size, size_t i) // i is the index of the root node of the subtree
{
    size_t largest = i; // identify the largest as the root

    // get the index of the left and right children of i
    size_t left = 2*i +1;
    size_t right = 2*i +2;

    // find the largest
    if (left < size && arr[left] > arr[largest]) { // check if left is within arr and is larger than the root
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) { // same thing for right
        largest = right;
    }

    if (largest != i) { // if largest isn't the root
        swap_values(arr+i, arr+largest);

        make_heap(arr, size, largest); // recursively make the affected subtree a heap aswell
    }
}
void heap_sort(int* arr, size_t size)
{
    // first make the array a heap
    for (size_t i = size / 2; i-- > 0;) {
        make_heap(arr, size, i);
    }

    for (size_t i = size; i-- > 0;) {
        // i will act as the size of the un-sorted array, 
        // as every iteration will sort one element at the end

        // swap first and last value (because first is larger)
        swap_values(arr, arr+i);

        // then remake the heap
        make_heap(arr, i, 0); // size = i, starting from index 0
    }
}