#include <stdio.h>

#define SIZE 10

double minmaxavg(double *array, double *out_min, double *out_max) {
    double out_avg = 0.0;
    int i;

    *out_min = array[0];
    *out_max = array[0];

    for(i = 0; i < SIZE; i++) {
        if(*out_min < array[i])
            *out_min = array[i];
        if(*out_max > array[i])
            *out_max = array[i];
        out_avg += array[i];
    }

    return out_avg / SIZE;
}

int main(void) {
    double min;
    double max;
    double avg;

    double array[10] = {5.5, 19.9, 2.2, 42.2, 11.1, 7.7, 101.1, 17.7, 3.3, 13.3};

    avg = minmaxavg(array, &min, &max);

    printf("min: %g, max: %g, agv: %g\n", min, max, avg);
}
