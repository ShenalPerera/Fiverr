#include <iostream>
#include <iomanip>

using namespace std;

// Show menu
void show_menu();

double calculate_assessment_value(double value_of_arc);

// Calculate the property tax
void calculate_tax(double value_of_arc);

// Get input for calculate tax
double get_arc_value(){
    double value_of_arc;
    cout << "\nEnter the value of a arc : $";
    cin >> value_of_arc;
    return value_of_arc;
}

int main() {
    int input;

    do {
        // Prompt the menu
        show_menu();

        // get the user input;
        cin >> input;

        // Handle the invalid input
        if (input < 0 || input > 1){
            cout << "Invalid input!" << endl;
            continue;
        }

        if (input == 1){
            calculate_tax(get_arc_value());
        }

    } while (input != 0);

    cout << "Thank you come again!" << endl;

    return 0;
}


void show_menu(){
    cout << "\n___Welcome to property tax calculator____" << endl;
    cout << "1 - Calculate a property tax" << endl;
    cout << "0 - Exit" <<  endl;
    cout << "Enter your choice : "  ;
}


double calculate_assessment_value(double value_of_arc){
    return (value_of_arc * 60)/100.0;
}


void calculate_tax(double value_of_arc){
    double assessment_value = calculate_assessment_value(value_of_arc);
    double property_tax = (assessment_value/100) * 0.64;

    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    cout << "Assessment value : $" << assessment_value<< endl;
    cout << "Property tax is $" << property_tax << endl;
}