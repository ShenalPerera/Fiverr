#ifndef CODE_APP_H
#define CODE_APP_H

#include <iostream>
#include "Bank.h"
using  namespace std;

void run(){
    bool quit= false;
    string userInput;
    while (!quit){
        try {
            Bank bank; // Object of the bak

            // Prompt the user and get the data
            bank.userPrompt();

            // Prompts back to user
            bank.displayData();

            // Print the two reports
            bank.printFinalData();



            cout << "Press enter if you wish to continue (q to quit): " ;

            getline(cin,userInput);

            if (userInput.empty()){
                system("clear");
                continue;
            }
            else{

                quit = true;
            }


        }
        catch (runtime_error& error) {
            cout << "There an unexpected error occurred; " <<  error.what() << endl;
        }
    }
}

#endif //CODE_APP_H
