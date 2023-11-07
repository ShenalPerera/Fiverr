#ifndef CODE_BANK_H
#define CODE_BANK_H
#include <vector>
#include "InvestData.h"

using namespace std;

class Bank{
    private:
        vector<string> userPrompts;     // Keep the inline messages as array of strings

        double initAmount;              // Initial amount
        double monthlyDeposit;          // Monthly deposit value
        double annualInterest;          // Annual interest
        int numYears;                   // Number of years
        InvestData investmentNormal;    // Object of InvestData - details of year-end balances and year-end earned interest
        InvestData investDataMonthly;   // Keep details of year-end balances and year-end earned interest with Monthly deposit

    public:
        Bank();                 // Constructor method

        // Getter methods
        double getInitAmount() const;
        double getMonthlyDeposit() const;
        double getAnnualInterest() const;
        int getNumYears() const;
        const vector<string> &getUserPrompts() const;

        // Setter methods
        void setInitAmount(double amount);
        void setMonthlyDeposit(double value);
        void setAnnualInterest(double interest);
        void setNumYears(int years);
        void setUsersValues();

        void displayHeader();           // Method to display the headers
        bool getCheckEnterVal();        // Method to check whether user input the 'enter'
        vector<double> userInputs();    // Hold the every user inputs as a vector of doubles

        void userPrompt();              // Method to prompts the user
        void displayData();       // Method to print data of user's values back to user

        // Calculate the annual Balance with the given data
        vector<vector<double>> annualBalanceIntrst(double t_openAmount, double t_depositAmount, int t_intRate, int t_years);

        // Method to generate details according to the bool data(With monthly deposit or without )
        InvestData calculateAnnualInvestment(bool t_monthlyDep = false);

        // Print the data in each report (InvestData two attributes of the Bank class)
        void printReportData(InvestData &report);

        // Method to combine all print members and print the final results
        void printFinalData();
};
#endif //CODE_BANK_H
