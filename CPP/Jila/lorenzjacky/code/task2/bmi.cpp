#include <iostream>

using namespace std;

int main() {
    const double POUNDS_IN_A_KILOGRAM = 2.20462;
    const int INCHES_IN_A_FEET = 12;
    const double CM_IN_A_INCH = 2.54;
    const double METERS_IN_A_CM = 0.01;

    int height_ft;
    int height_in;
    double weight_lbs;

    cout << "Enter height (ft. in.): ";
    cin >> height_ft >> height_in;

    cout << "Enter weight (lbs.): ";
    cin>> weight_lbs;

    double height = (height_ft * INCHES_IN_A_FEET + height_in) * CM_IN_A_INCH * METERS_IN_A_CM;
    double weight = weight_lbs / POUNDS_IN_A_KILOGRAM;

    double bmi = weight / (height * height);

    cout << "Height is " << height << "m. Weight is " << weight << "kg.\n";
    cout << "The BMI is " << bmi << ".\n";
    return 0;
}