#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

// Comparison function for qsort
int compare(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    return (diff > 0) - (diff < 0);
}

int main() {
    double *data;
    int n;

    // Prompt the user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    data = (double *)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Load data into the array
    printf("LOAD DATA...\n");
    input(data, &n);  // Pass the address of n

    // Print raw data
    printf("RAW DATA:\n\t");
    output(data, n);

    // Normalize the data
    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n) == 0) {
        output(data, n);
    } else {
        printf("Normalization failed: size is too small.\n");
    }

    // Sort the normalized data using qsort
    printf("\nSORTED NORMALIZED DATA:\n\t");
    qsort(data, n, sizeof(double), compare);
    output(data, n);

    // Make a decision based on the data
    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    // Free the allocated memory
    free(data);

    return 0;
}
