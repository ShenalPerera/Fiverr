#include <iostream>
#include <iomanip>
#include "Bank.h"
#include <limits>

using namespace std;

// Define the name for after uses
const char* YEAR = "Year";
const char* YEAR_END_BAL = "Year End Balance";
const char* YEAR_END_INTEREST = "Year End Interest";

//Constructor
Bank::Bank() {
    setUsersValues();
}

// Getters and setter methods
double Bank::getAnnualInterest() const {
    return this->annualInterest;
}

double Bank::getInitAmount() const {
    return this->initAmount;
}

double Bank::getMonthlyDeposit() const {
    return this->monthlyDeposit;
}

int Bank::getNumYears() const {
    return this->numYears;
}

const vector<string> &Bank::getUserPrompts() const {
    return this->userPrompts;
}

void Bank::setAnnualInterest(double interest) {
    this->annualInterest = interest;
}

void Bank::setMonthlyDeposit(double value) {
    this->monthlyDeposit = value;
}

void Bank::setInitAmount(double amount) {
    this->initAmount = amount;
}

void Bank::setNumYears(int years) {
    this->numYears = years;
}

// Initialize ethe vector with inline string that will be prompt to the user
void Bank::setUsersValues() {
    Bank::userPrompts = {
            "Initial Investment Amount:  ",
            "Monthly Deposit:  ",
            "Annual Interest:  ",
            "Number of Years:  "
    };
}

// Method to display header
void Bank::displayHeader() {
    cout <<string(36,'*')<< endl;
    cout << string(12, '*') << " Data Input " << string(12, '*') << endl;
}

// Method to get the user Inputs and return all the inputs as a vector
vector<double> Bank::userInputs() {

    // This is the vector that will be hold the user inputs
    vector<double> responses;

    // Get the prompts messages vector as promptUser for easy
    vector<string> promptsUser = getUserPrompts();

    //Loop until each message and prompt the user to get an input
    for (int i = 0; i < promptsUser.size(); ++i) {
        // Relevant inline message
        string prompt = promptsUser.at(i);

        // Variable to hold the user input
        double userInput;
        // Prompt the message to the user
        cout << prompt;
        // Get the input from the user
        cin >> userInput;

        // Validate the user Inputs
        if (!cin || userInput < 0.01) {
            throw invalid_argument("\n\nInvalid Input!!! \n\n");
        }

        // If the input is valid add them into the responses
        responses.push_back(userInput);
    }
    // Return that vector
    return responses;
}

// Method to prompt the user
void Bank::userPrompt() {
    // Hold the deposit details
    vector<double> depositDetails;
    // exit condition
    char isQuit = 's';

    while (isQuit != 'q') {

        try {
            // Clear the buffer
            depositDetails.clear();

            // Display interface header
            displayHeader();

            // Collect user input
            depositDetails = userInputs();

        }
            // Catch any invalid arguments and handle them gracefully
        catch (invalid_argument& except) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
            cout << except.what() << endl;
        }

        // Check that depositDetails vector is full and user decides to continue
        if (depositDetails.size() == 4 && getCheckEnterVal()) {
            // Set our class's private members

            setInitAmount(depositDetails.at(0));
            setMonthlyDeposit(depositDetails.at(1));
            setAnnualInterest(depositDetails.at(2));
            setNumYears(depositDetails.at(3));

            // Calculate and store Annual balance data with and without monthly deposit in relevant private members
            this->investmentNormal = calculateAnnualInvestment(false);
            this->investDataMonthly= calculateAnnualInvestment(true);

            // Exit this class and return to main()
            isQuit = 'q';
        }
    }
}

// Method to check whether user inputs the 'enter'
bool Bank::getCheckEnterVal() {
    cin.ignore();
    cout << "Press enter to continue . . .";
    return cin.get() == '\n';
}

// Print back the user entered details back to the users
void Bank::displayData() {
    vector<string> promptsUser = getUserPrompts();

    for (int i = 0; i < promptsUser.size(); ++i) {
        string prompt = promptsUser.at(i);

        if (i == 0){
            cout << prompt << "$" << this->getInitAmount() << endl;
        }
        else if (i == 1){
            cout << prompt << "$" << this->getMonthlyDeposit() << endl;
        }
        else if (i == 2){
            cout << prompt << "%" << this->getAnnualInterest() << endl;
        }
        else{
            cout << prompt <<  this->getNumYears() << endl;
        }

    }
    string text;
    cout << "Press enter to continue . . ." ;
    getline(cin,text);

    while (!text.empty()){
        cout << "Press enter to continue . . ." ;
        getline(cin,text);
    }

}

// Calculate the annual interest and the balance for given data
vector<vector<double>>
Bank::annualBalanceIntrst(double t_openAmount, double t_depositAmount, int t_intRate, int t_years) {

    // Annual interest
    vector<double> annualInterestOnly;

    // Annual Balance
    vector<double> annualBalWithInterest;

    double newBal;
    double yearEndInt;

    // Percentage of the interest
    double precIntRate = (t_intRate/100.00)/12.00;

    double intTracker = 0;
    double intOnly = 0;

    // Keep the balance and the interest same as 2d vector
    vector<vector<double>> balanceNInts;

    // Loop over months in requested time frame and calculate annual balance & earned interest
    for (int i = 0; i < (t_years * 12); ++i) {
        yearEndInt += ((intTracker + t_openAmount) + (t_depositAmount * (i+1))) * precIntRate;
        // Allows tracking earned interest back into principle
        intTracker = yearEndInt;
        if (((i+1) % 12) == 0) {
            annualInterestOnly.push_back(yearEndInt - intOnly); // Add just the annual interest to one vector first
            intOnly = yearEndInt;
            newBal = t_openAmount + (t_depositAmount * (i+1)) + yearEndInt; // Add interest, opening, & monthly amount
            annualBalWithInterest.push_back(newBal); // Add annual bal with interest to a second vector
        }
    }

    if (newBal > INT32_MAX ) {
        throw runtime_error("Unable to complete calculation. Amount too large.");
    }

    balanceNInts.push_back(annualInterestOnly); // One vector for tracking interest
    balanceNInts.push_back(annualBalWithInterest); // One vector for tracking interest + balance

    // Pass vectors back to fill out InvestmentInfo objects
    return balanceNInts;
}


InvestData Bank::calculateAnnualInvestment(bool monthlyDep) {
    vector<int> years;
    vector<vector<double>> yearEndBalances;

    InvestData investmentDetails;

    try {

        // Return years as array of ints for display to the user
        for (int i = 0; i < numYears; ++i) {
            years.push_back(i + 1);
        }

        if (!monthlyDep) {
            // Calculate without monthly deposit
            yearEndBalances = annualBalanceIntrst(this->initAmount, 0, this->annualInterest, numYears);
        } else {
            // Calculate with monthly deposits
            yearEndBalances = annualBalanceIntrst(this->initAmount, this->monthlyDeposit, this->annualInterest, numYears);
        }

        // Populate Investment object properties
        investmentDetails.setYears(years);
        investmentDetails.setYearEndEarnedInterests(yearEndBalances.at(0));
        investmentDetails.setYearEndBalances(yearEndBalances.at(1));

        return investmentDetails;
    }
    catch (runtime_error& except) {
        cout << except.what() << endl;
        return investmentDetails;
    }

}


void Bank::printReportData(InvestData &report) {
    // Get years , year interest and year-end balance to local variables
    vector<int> years = report.getYears();
    vector<double> yearEndBalances = report.getYearEndBalances();
    vector<double> yearEndEarnedInterests = report.getYearEndEarnedInterests();

    // Print the main header message to the user
    cout << string(66, '=') << endl;
    cout << setw(9) << YEAR << setw(26) << YEAR_END_BAL << setw(27) << YEAR_END_INTEREST << endl;
    cout << string(66, '-') << endl;

    // Loop over InvestmentInfo object to fill out report
    for (int i = 0; i < years.size(); ++i) {
        cout << setw(9) << years.at(i) << fixed << setprecision(2);
        cout << setw(26) << yearEndBalances.at(i) << fixed << setprecision(2);
        cout << setw(27) << yearEndEarnedInterests.at(i) << fixed << setprecision(2)<< endl;
    }
    cout << endl << endl;
}


void Bank::printFinalData() {

    cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
    printReportData(investmentNormal);

    cout << "     Balance and Interest Without Additional Monthly Deposits     " << endl;
    printReportData(investDataMonthly);

}



