#include <stdio.h>
#include <stdlib.h>


int str_to_int(const char * str);                  // function to convert string to integer
long int factorial(int number);                // function to calculate the factorial
long int ncr ( int n, int r);
void get_pascal_triangle(int row_count);                 // printing function
void print_spaces(int number);

int main(int argc, char *argv[]){

    // Handling error
    if(argc == 2){
        long number = str_to_int(argv[1]);
        if(number < 1 || number > 20){
            printf("Argument should be an integer between 1- 20 inclusive\n");
            return 1;
        }

    }
    else{
        printf("Invalid number of arguments!\n");
        return 1;
    }
    get_pascal_triangle(str_to_int(argv[1]));
    return 0;
}

// pasre string to integer
int str_to_int(const char * str){
    char * rest;    // unwanted part of te string
    return strtol(str,&rest,10);
}

// function to get a factorial of a number
long int factorial( int number) {
    long int facts = 1;
    int i;
    for ( i = 1; i<= number; i++)
        facts = facts * i;
    return( facts);
}

// function to get combinations
long int ncr ( int n, int r) {
    return( factorial( n) / (factorial( r) * factorial(n- r) ) ) ;
}


void get_pascal_triangle(int row_count){
    for (int i = row_count-1; i >= 0 ; i--) {

        print_spaces(row_count-1 - i);

        for (int j = 0; j <= i; ++j) {
            printf("%4li ", ncr(i,j));
        }
        printf("\n");
    }
}

// print the number of spaces from the argument given
void print_spaces(int number){
    for (int i = 0; i < number; ++i) {
        printf("  ");
    }
}