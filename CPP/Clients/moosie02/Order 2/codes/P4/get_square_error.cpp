#include "get_square_error.h"
#include <cmath>


double get_square_error(double actual_value, double sample_value){
    return pow(actual_value - sample_value,2);
}