#include <stdio.h>

// Function 2
int fibonacci(int n);

// Function 3
void runHanoi(int n, char x, char y, char z);

// Function 5
void convertToBin();

int main() {
//    int n =10;
//    printf("%i", fibonacci(n));
//
//    runHanoi(4,'X','Y','Z');

    convertToBin();
    return 0;
}

int fibonacci(int n){
    if( n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


void runHanoi(int n, char x, char y, char z){
    if(n == 1){
        printf("\nMove disk from peg %c to peg %c", x, y);
    }
    else{
        runHanoi(n-1,x,z,y);
        runHanoi(1,x,y,z);
        runHanoi(n-1,y,x,z);
    }
}

void convertToBin(){
    char word[100];
    printf("Enter the input string: ");

    scanf("%s",word);

    char c = word[0];
    int count  = 0;

    while(c != '\0'){
        for (int i = 7; i >=0; i--) {
            printf("%c", c & (1 << i)  ? '1': '0');
        }
        count++;
        c = word[count];
    }
}