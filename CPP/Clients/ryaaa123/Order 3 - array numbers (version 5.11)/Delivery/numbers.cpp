#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printNumbers(int [][10]);
void initNumbers(int [][10]);


int main(){
	
	srand((unsigned)time(0));
	
	int numbers[10][10];

	initNumbers(numbers);
	
	int sum = 0;
	
	int row = rand() % 10 ;
	int col = rand() % 10 ;
	
	sum = numbers[row][col];
	numbers[row][col] = 0;
	
	do{
		row = rand() % 10 ;
		col = rand() % 10 ;
		
		
		sum = sum + numbers[row][col];
		numbers[row][col] = 0;
		
		printNumbers(numbers);
		cout << "\nsum = " <<sum << endl;
		
	}while(sum <=1000);
	
	
	
	return 0;
}


void printNumbers(int numbers[][10]){
	system("cls");
	system("clear");
	for(int i = 0; i <10; i++){
		cout << "|\t";
		for(int j =0; j<10; j++){
			cout << numbers[i][j] << "\t";
		}
		cout << " |";
		if(i != 9){
			cout << "\n";
		}
	}
}

void initNumbers(int numbers[][10]){
	int number =1;

	for(int i = 0; i <10; i++){
		for(int j =0; j<10; j++){
			numbers[i][j] = number;
			number++;
		}
	}
}
