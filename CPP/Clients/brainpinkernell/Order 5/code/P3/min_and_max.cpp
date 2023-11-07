#include "min_and_max.h"

void min_and_max(const double array[], int size, double * min,double * max){
    if(size > 0){
        *min = array[0];
        *max = array[0];

        for (int i = 1; i < size; ++i) {
            if (*min > array[i]){
                *min = array[i];
            }
            if (*max < array[i]){
                *max = array[i];
            }
        }

    }

}
