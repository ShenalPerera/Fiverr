#ifndef CODE_MULTIPLICATION_H
#define CODE_MULTIPLICATION_H

void multMatrix(int A[N][N],int B[N][N],int C[N][N], int size){

    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            C[row][col] = 0;
            for (int i = 0; i < size; ++i) {
                C[row][col] += A[row][i] * B[i][col];
            }
        }
    }


}

void doMultMat(){
    int A[N][N];
    int B[N][N];
    int C[N][N];

    int userInput;

    printf("Enter number of A matrix between 1 and %i\n",N);
    scanf("%i",&userInput);

    for (int i = 0; i < userInput; ++i) {
        for (int j = 0; j < userInput; ++j) {
            A[i][j] = (rand() % 21 ) - 10;
            B[i][j] = (rand() % 21 ) - 10;
        }
    }
    diplayMatrix("matrix A",A,userInput,userInput);
    diplayMatrix("matrix B",B,userInput,userInput);

    multMatrix(A,B,C,userInput);

    diplayMatrix("Result matrix",C,userInput,userInput);
}

#endif //CODE_MULTIPLICATION_H
