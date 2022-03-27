#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <conio.h>

using namespace std; 

void initialize(char [][3]);
bool checkWin(char [][3]);
void play(char [][3]);
void showBoard(char [][3]);
bool valid(char [][3], int);

bool Xs_turn = true; 
char ltr = 'X';  //The letter being played
int round = 0;

int main () 
{ 
char board[3][3];
initialize(board); 
//Create any other variable you need here.


do{
/*
This loop will manage the game play and determine whose turn it is.
The loop should execute the play function, check to see if there is a winner, and then
change the turn to the next player.

Remember a maximim of 9 playes can be made per game, but possibley less if someone wins.
*/
	play(board);
	
	if(checkWin(board)){
		round = 0;
		break;
	}
	
	Xs_turn = !Xs_turn;
	ltr = Xs_turn ? 'X':'O';	

}while(round <9);  //Repeate while there is no winner and less than 10 plays have been made.

showBoard(board); //Displayes the funal board after the game is over.

//Here you should ouput who the winner is, X or O, or if the game is a tie, no winner.

if(round == 0){
	cout << "Game Over! " << ltr << " is the winner!";
}
else if(round == 9){
	cout << "Game is a tie!";
}

}

void showBoard(char b[][3])
{
	/*
	This function should clear the screen and show the Tic Tac Toe header and then display the board. 
	The header and board should be tabbed over.
	*/
	cout << "\t\tTic-Tac-Toe!\n"<< endl;
	for(int row = 0; row<3; row++){
		cout << "\t\t";
		for(int col = 0; col<3; col++){
			cout << b[row][col] << "       ";
		}
		cout << "\n";
	}
	
}
	

void initialize(char b[][3])
{
	/*
	This function should use a nest for loop to initialzie the baord with char values 1 - 9. Note that the char equivalent of 1 is 49.
	You will need to type cast to conver the int value to char.
	example if counter starts at 49, this will store the char '1' in the first square of the board:
		board[r][c] = (char) counter;
	*/
	int counter = 49;
	for(int row = 0; row<3; row++){
		for(int col = 0; col<3; col++){
			b[row][col] = (char)(counter);
			counter++;
		}
	}
}

void play(char b[][3])
{
/*
This function receives the board and runs the showBaord function, then and prompts the player to enter their move. 
If the move is valid, then the X or O should be placed on the board in the appropriate spot. This function only 
makes one play at a time.
*/	
	showBoard(b);
	cout << "Select your move: ";
	int move ;
	cin >> move;
	
	if (valid(b,move)){
		b[(move-1)/3][(move-1)%3] = ltr;
		round++;
	}
	else{
		Xs_turn = !Xs_turn;
	}
	
}

bool valid(char b[][3], int m)
{
/*
This function receives the board and the potential move and checks to see if a potential 
move is valid. If it is, the function returns true, otherwise it returns false.
*/
	bool validMove = (m - 1) <=8 && (m-1) >= 0;
	
	int row = (m-1) / 3;
	int col = (m-1) % 3;
	
	bool validPosition = b[row][col] <= '9' && b[row][col] >= '1'; 
	
	return validMove && validPosition;
}

bool checkWin(char b[][3])
{
/*
This function receives the board and a player, X or O, to see if it won. If the player won,
the function will return true, otherwise it will return false.

You will need to compaire the positions of the letter to 
*/	
	ltr = Xs_turn ? 'X':'O';
	if(b[0][0] == b[0][1] && b[0][1] == b[0][2]){
		return true;
	}
	else if(b[1][0] == b[1][1] && b[1][1] == b[1][2]){
		return true;
	}
	else if(b[2][0] == b[2][1] && b[2][1] == b[2][2]){
		return true;
	}
	else if(b[0][0] == b[1][0] && b[1][0] == b[2][0]){
		return true;
	}
	else if(b[0][1] == b[1][1] && b[1][1] == b[2][1]){
		return true;
	}
	else if(b[0][2] == b[1][2] && b[1][2] == b[2][2]){
		return true;
	}
	else if(b[0][0] == b[1][1] && b[1][1] == b[2][2]){
		return true;
	}
	else if(b[0][2] == b[1][1] && b[1][1] == b[2][0]){
		return true;
	}
	else{
		return false;
	}

}
