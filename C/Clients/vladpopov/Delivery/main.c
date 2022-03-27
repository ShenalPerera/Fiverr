#include <stdio.h>
#include <stdlib.h>

#define N 10

#define ROWS 10
#define COLS 10

#include "displayMatrix.h"
#include "multiplication.h"
#include "sum.h"
#include "tickets.h"


char menu();
void display();

int main() {
    menu();
}

void display(){
    printf("Please choose one of the following option\n");
    printf("A/a - add two matrices\nM/m - multiply two matrices\nT/t - buy tickets\nE/e - exit\n");
}
char menu(){
    char userInput;


    while (1){
        display();
        scanf(" %c",&userInput);
        switch (userInput) {
            case 'A':
            case 'a':
                doSumMat();
                break;
            case 'M':
            case 'm':
                doMultMat();
                break;
            case 'T':
            case 't':
                doTickets();
                break;
            case 'E':
            case 'e':
                exit(0);

            default:
                printf("Invalid Option\n");
                break;
        }

    }
}