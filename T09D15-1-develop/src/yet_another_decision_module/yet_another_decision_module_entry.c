#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "decision.h"

int main() {
    int n;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }

    double *data = (double *)calloc(n, sizeof(double));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            printf("Invalid input!\n");
            free(data);
            return 1;
        }
    }

    if (make_decision(data, n))
        printf("YES\n");
    else
        printf("NO\n");

    free(data);

    return 0;
}
