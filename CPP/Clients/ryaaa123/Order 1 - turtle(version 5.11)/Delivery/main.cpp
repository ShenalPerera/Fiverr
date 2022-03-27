#include <iostream>
#include <conio.h>
//Add the appropriate preprocessor directives here.
//Add the function prototypes here
void initialize(char[][25]);
void display(char[][25]);
void move(char[][25] , char);
bool checkMove(char[][25],char);

using namespace std;
//Globals for the turtle’s current and starting position.
int tr=9;
int tc=9;

int main() {
    char field[25][25];
    initialize(field);
    display(field);
    char dir;
    do{
        cout << "\t 8 - Move Up" << endl;
        cout << "\t 2 - Move Down" << endl;
        cout << "\t 4 - Move Left" << endl;
        cout << "\t 6 - Move Right" << endl;
        cout << "\t 0 - Exit" << endl;
        cout << "\t Direction to move: ";
        dir = getch();
        
		cout << "\n";
        
		if(dir != '0' )
            move(field, dir);
            
    }while(dir != '0');
    return 0;
}

void initialize(char field[][25]){
	for(int row = 0; row<25;row++){
		for(int col = 0; col < 25; col++){
			field[row][col] = ' ';
		}
	}
	field[tr][tc] = 'O';

}

void display(char field[][25]){
	for(int row = 0; row < 27; row++ ){
		for(int col = 0; col < 27; col++){
			if(row == 0 || row == 26){
				cout << '=';
				continue;
			}
			if(col == 0 || col == 26){
				cout << "|";
			}
			else{
				cout << field[row-1][col-1];
			}
		}
		
		cout <<"\n";
	}
}

void move(char field[][25],char dir){
	int isFound = 0;
	for(int row = 0; row <25;row++){
		for(int col=0; col < 25; col++){
			if(field[row][col] == 'O'){
				isFound = 1;
				
				if(checkMove(field,dir)){
					field[row][col] = '*';
					if (dir == '2'){
						field[row+1][col] = 'O';
					}
					else if(dir == '8'){
						field[row-1][col] = 'O';
					}
					else if(dir == '4'){
						field[row][col-1] = 'O';
					}
					else if(dir == '6'){
						field[row][col+1] = 'O';
					}
					else{
						field[row][col] = 'O';
					}
				}
				
				break;
			}
		}
		if (isFound){
			break;
		}
	}
	display(field);
}


bool checkMove(char field[][25],char dir){
	for(int row=0; row<25; row++){
		for(int col = 0; col < 25; col++){
			if(field[row][col] == 'O'){
				if (dir == '2' && row + 1 > 24){
					return false;
				}
				else if(dir == '8' && row -1 < 0){
					return false;
				}
				else if(dir == '4' && col -1 < 0){
					return false;
				}
				else if(dir == '6' && col + 1 > 24){
					return false;
				}
			}
		}
	}
	return true;
}
