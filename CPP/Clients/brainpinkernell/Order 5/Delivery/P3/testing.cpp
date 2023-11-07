#include <iostream>
#include "get_user_answer.h"
#include "put_in_order.h"
#include "min_and_max.h"

using namespace std;

int main(){

    char dummy;
    get_user_answer(&dummy);
    cout << "Test get_user_answer : " << " value = " << dummy << endl << endl << endl;

    double value1 = 115.90;
    double value2 = 26.89;
    cout << "Testing put_in_order function" << endl;
    cout << "Values before call the function value1 = " << value1 << " value2 = " << value2 << endl;
    put_in_order(&value1,&value2);
    cout << "Values after call the function value1 = " << value1 << " value2 = " << value2 << endl;

    double min ,max;
    double array[] = {9.0, 2.1, 10.1, 11.2, 0.5};

    min_and_max(array, 5, &min, &max);

    cout << "Testing min_max : max = " << max << " min = " << min << endl;

    return EXIT_SUCCESS;
}
