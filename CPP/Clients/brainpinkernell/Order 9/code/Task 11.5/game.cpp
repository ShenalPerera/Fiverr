#include <iostream>

#include "GameCard.h"
#include "rand_int.h"

#include <vector>

using namespace std;

int main(){
    char suits [4]  = {'S','H','D','C'};
    int toughness[] = {30,2,3,4,5,6,7,8,9,10,15,20,25};

    // player 1 cards pack
    vector<GameCard*> player1;
    for (int i = 0; i < 3; ++i) {
        int pos = rand_int(0,12);
        player1.push_back(new GameCard(suits[rand_int(0,3)],pos+1,toughness[pos]));
    }

    cout << "Player 1 pack : " << endl;
    for (int i = 0; i < player1.size(); ++i) {
        player1.at(i)->display();
    }
    // player 2 cards pack
    vector<GameCard*> player2;
    for (int i = 0; i < 3; ++i) {
        int pos = rand_int(0,12);
        player2.push_back(new GameCard(suits[rand_int(0,3)],pos+1,toughness[pos]));
    }
    cout << "\n\nPlayer 2 pack : " << endl;
    for (int i = 0; i < player2.size(); ++i) {
        player2.at(i)->display();
    }

    cout << " Choosing winner ...." << endl;

    int player1_wins = 0;
    int player2_wins = 0;

    for (int i = 0; i < 3; ++i) {
        cout << "Round " << i+1 << endl;
        double r1 = player1.at(i)->compute_rank();
        double r2 = player2.at(i)->compute_rank();

        if (r1 > r2){
            player1_wins++;
            cout << "Player 1 won the round" << endl;
        }
        if (r2 > r1){
            player2_wins++;
            cout << "Player 2 won the round" << endl;
        }

        if (r1 == r2){
            player1_wins++;
            player2_wins++;
            cout << "Tie" << endl;
        }
    }


    if (player1_wins > player2_wins){
        player1_wins++;
        cout << "\n\nPlayer 1 won the game" << endl;
    }
    if (player2_wins > player1_wins){
        cout << "\n\nPlayer 2 won the game" << endl;
    }

    if (player1_wins == player2_wins){

        cout << "\n\nGame is Tie" << endl;
    }
    return 0;
}