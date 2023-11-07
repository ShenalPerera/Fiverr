#include <iostream>

#include "GameCard.h"

int main(){
    // size of the cards
    int number_of_cards;

    // Get the number of cards
    cout << "Enter the number of cards : ";
    cin >> number_of_cards;

    // Create the array of cards
    GameCard * gameCard_array = new GameCard[number_of_cards];

    for (int i = 0; i < number_of_cards; ++i) {
        int value;
        char suit;

        cout << "Card " << i+1 << endl;

        // get the value of the card
        cout << "Enter the value [1-13] : ";
        cin >> value;
        gameCard_array[i].setValue(value);

        // get the suit of the card
        cout << "Enter the suit (H,D,C and S) : ";
        cin >> suit;
        gameCard_array[i].setSuit(suit);


    }

    // Display the all cards in the array

    for (int i = 0; i < number_of_cards; ++i) {
        cout << "Card " << i+1 << endl;
        gameCard_array[i].displayCard();    // use the display method
        cout << endl;

    }


    // apply changes to the cards
    /* Change the card by asking from the user
     */

    cout << "Change the cards !" << endl << endl;

    for (int i = 0; i < number_of_cards; ++i) {
        cout << "Card " << i+1 << endl;
        gameCard_array[i].displayCard();

        char user_choice;
        cout << "Do you want to change the card " << i+1 << " (Y/N) : ";
        cin >> user_choice;

        // check the user choice
        if (tolower(user_choice) == 'y'){
            int value;
            char suit;

            // get the value of the card
            cout << "Enter the value [1-13] : ";
            cin >> value;
            gameCard_array[i].setValue(value);

            // get the suit of the card
            cout << "Enter the suit (H,D,C and S) : ";
            cin >> suit;
            gameCard_array[i].setSuit(suit);
        }
        else if(tolower(user_choice) == 'n'){
            continue;
        }
        else{
            cout << "Invalid input! try again" << endl;
            i--;

        }
    }

    // Display the all cards in the array

    for (int i = 0; i < number_of_cards; ++i) {
        cout << "Card " << i+1 << endl;
        gameCard_array[i].displayCard();    // use the display method
        cout << endl;

    }

    delete[] gameCard_array;
    gameCard_array = nullptr;
    return EXIT_SUCCESS;
}