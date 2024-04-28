#include <stdio.h>
#include <omp.h>
#include <stdlib.h> // For omp_set_num_threads

int main() {
    omp_set_num_threads(4);
    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double max_val = 0.0;
    double min_val = 100.0;
    double avg = 0.0, sum = 0.0, sum_val = 0.0;
    int i;

#pragma omp parallel for reduction(min:min_val)
    for (i = 0; i < 10; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

#pragma omp parallel for reduction(max:max_val)
    for (i = 0; i < 10; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

#pragma omp parallel for reduction(+:sum_val)
    for (i = 0; i < 10; i++) {
        sum_val += arr[i];
    }

#pragma omp parallel for reduction(+:sum)
    for (i = 0; i < 10; i++) {
        sum += arr[i];
    }

    avg = sum / 10;

    printf("min_val = %f\n", min_val);
    printf("max_val = %f\n", max_val);
    printf("sum_val = %f\n", sum_val);
    printf("avg_val = %f\n", avg);

    return 0;
}
/*
 g++ -o HPC3 -fopenmp HPC3.cpp -lstdc++
 ./HPC3
min_val = 1.000000
max_val = 10.000000
sum_val = 55.000000
avg_val = 5.500000
*/

