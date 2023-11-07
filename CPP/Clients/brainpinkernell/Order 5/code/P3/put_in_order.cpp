#include "put_in_order.h"

void put_in_order(double * val1, double * val2){
    if (*val1 > *val2){
        double temp;
        temp = *val1;
        *val1 = *val2;
        *val2 = temp;
    }
}
