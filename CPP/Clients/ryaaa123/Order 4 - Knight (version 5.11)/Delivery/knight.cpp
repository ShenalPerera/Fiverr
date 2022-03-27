#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Declare the board
int board[8][8];

int horizontal[] = {2,1,-1,-2,-2,-1,1,2};
int vertical[]   = {-1,-2,-2,-1,1,2,2,1};

// Heuristic Rows
int heuristic[8][8] = {{2,3,4,4,4,4,3,2},
                       {2,4,6,6,6,6,4,3},
                       {4,6,8,8,8,8,6,4},
                       {4,6,8,8,8,8,6,4},
                       {4,6,8,8,8,8,6,4},
                       {4,6,8,8,8,8,6,4},
                       {3,4,6,6,6,6,4,3},
                       {2,3,4,4,4,4,3,2}
                       };

void initBoard();
void displayBoard();
bool moveKnight(int count);


int main(){
    srand((unsigned)time(0));

    initBoard();

    int count = 0;
    // Start position
    int startRow = (rand() % 2) * 7;
    int startCol = (rand() % 2) * 7;

    // Initialize the Knight
    board[startRow][startCol] = -1;
    displayBoard();
    cout << "Initial Board\n";
    bool isStop;

    while (count != 64){

        isStop = moveKnight(count + 1);
        if (!isStop) break;

        displayBoard();

        count++;
        cout << "round " << count << endl;

    }
    return 0;
}



void initBoard(){
	for(int i=0; i < 8; i++){
		for(int j=0; j < 8; j++){
			board[i][j] = 0;
		}
	}
}


void displayBoard(){
    cout << "\n     1    2    3    4    5    6    7    8" << endl;
    cout << "   +----+----+----+----+----+----+----+----+" << endl;
    for (int i = 0; i < 8; ++i) {
        cout << i+1 << "  |";
        for (int j = 0; j < 8; ++j) {



            if (board[i][j] == 0){
                cout << "    |";
            }
            else if (board[i][j] == -1){
                cout << "  K |";
            }
            else {
                if (board[i][j] <= 9) cout << "  " << board[i][j] << " |";
                else cout << " " << board[i][j] << " |";
            }
        }

        cout << "\n   +----+----+----+----+----+----+----+----+" << endl;
    }
}


bool moveKnight(int count){
    int currentRow;
    int currentCol;

    int nextRow = 9;
    int nextCol = 9;

    int minValue = 9;

    bool isFound = false;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == -1){
                currentRow = i;
                currentCol = j;
                isFound = true;
                break;
            }
        }
        if (isFound) break;
    }

    for (int i = 0; i < 8; ++i) {
        int tempRow = currentRow + vertical[i];
        int tempCol = currentCol + horizontal[i];

        if ((tempCol <= 7 && tempCol >= 0) && (tempRow <= 7 && tempRow >= 0)){
            if (board[tempRow][tempCol] == 0 ){
                if (minValue > heuristic[tempRow][tempCol]){
                    minValue = heuristic[tempRow][tempCol];
                    nextRow = tempRow;
                    nextCol = tempCol;
                }
                if (minValue == heuristic[tempRow][tempCol] && rand() % 2 == 1){
                    nextRow = tempRow;
                    nextCol = tempCol;
                }
            }
        }
    }
    if (nextRow >=0 && nextRow <=7 && nextCol >=0 && nextCol <= 7){
        board[nextRow][nextCol] = -1;
        board[currentRow][currentCol] = count;
        return true;
    }
    return false;

}

