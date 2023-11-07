#include <iostream>
#include "legal_move.h"

int get_winner(char first_payer, char second_player){
    if (!legal_move(first_payer) || !legal_move(second_player)){
        return -1;
    }
    else if( first_payer == second_player){
        return 0;
    }
    else if( (first_payer == 'r' && second_player == 's') || (first_payer == 's' && second_player == 'p') || (first_payer == 'p' && second_player == 'r') ){
        return 1;
    }
    else if ((first_payer == 's' && second_player == 'r') || (first_payer == 'p' && second_player == 's') || (first_payer == 'r' && second_player == 'p')){
        return 2;
    }
}