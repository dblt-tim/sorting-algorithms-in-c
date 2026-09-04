
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algos.h"

int main() {
    srand(time(NULL));
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    shuffle(a, 10);

    for (int i = 0; i < 10; i++) printf("%d ", a[i]); printf("\n");

    insertion_sort(a, 10);

    for (int i = 0; i < 10; i++) printf("%d ", a[i]); printf("\n");
    
    return 0;
}