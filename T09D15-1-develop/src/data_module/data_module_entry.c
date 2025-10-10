#include <stdio.h>
#include <stdlib.h>
#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "data_process.h"
#include <math.h>

int main() {
    double *data;
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("You entered: %d elements\n", n);

    data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    input(data, &n); 

    printf("Before Normalization:\n");
    printf("Max: %.2f\n", max(data, n));
    printf("Min: %.2f\n", min(data, n));
    printf("Mean: %.2f\n", mean(data, n));
    printf("Variance: %.2f\n", variance(data, n));

    if (normalization(data, n)) {
        printf("Normalized data: ");
        output(data, n);

        printf("After Normalization:\n");
        printf("Max: %.2f\n", max(data, n));
        printf("Min: %.2f\n", min(data, n));
        printf("Mean: %.2f\n", mean(data, n));
        printf("Variance: %.2f\n", variance(data, n));
    } else {
        printf("Normalization failed due to identical values.\n");
    }

    free(data);

    return 0;
}

