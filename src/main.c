
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algos.h"

int main() {
    srand(time(NULL)); // init random generator
    
    int a[10000];
    for (int i = 0; i < 10000; i++) {
        a[i] = i;
    }

    shuffle(a, 10000);

    printf("%lf\n", measure_time(a, 10000, select_sort));

    printf("%s", is_sorted(a, 10000) ? "true" : "false");
    
    return 0;
}