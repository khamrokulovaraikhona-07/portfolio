#include "data_stat.h"
#include <math.h>

double max(double *data, int n) {
    double max_value = data[0];  // Start by assuming the first value is the max
    for (int i = 1; i < n; i++) {
        if (data[i] > max_value)
            max_value = data[i];  // Update max_value if a higher value is found
    }
    return max_value;  // Return the maximum value found
}

double min(double *data, int n) {
    double min_value = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] < min_value)
            min_value = data[i];
    }
    return min_value;
}

double mean(double *data, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double mean_value = mean(data, n);
    double variance_value = 0;
    for (int i = 0; i < n; i++) {
        variance_value += pow(data[i] - mean_value, 2);  // Ensure math.h is included for pow()
    }
    return variance_value / n;
}

