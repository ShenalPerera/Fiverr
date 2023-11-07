#include <iostream>

using namespace std;

int main(){
    const int PENNIES_IN_A_DOLLAR = 100;
    const int PENNIES_IN_A_QUARTER = 25;
    const int PENNIES_IN_A_DIME = 10;
    const int PENNIES_IN_A_NICKLE = 5;


    double dollar_amount;
    cout << "Enter dollar amount: ";
    cin >> dollar_amount;


    int remaining_pennies =(int) (dollar_amount * PENNIES_IN_A_DOLLAR);

    int quarters = (int)(remaining_pennies / PENNIES_IN_A_QUARTER);
    remaining_pennies = remaining_pennies % PENNIES_IN_A_QUARTER;

    int dimes = (int)(remaining_pennies / PENNIES_IN_A_DIME);
    remaining_pennies = remaining_pennies % PENNIES_IN_A_DIME;

    int nickles = (int)(remaining_pennies / PENNIES_IN_A_NICKLE);
    remaining_pennies = remaining_pennies % PENNIES_IN_A_NICKLE;

    cout << "Quarters : " << quarters << endl;
    cout << "Dimes    : " << dimes << endl;
    cout << "Nickels  : " << nickles << endl;
    cout << "Pennies  : " << remaining_pennies << endl;


    return 0;
}