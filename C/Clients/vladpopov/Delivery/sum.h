#ifndef CODE_SUM_H
#define CODE_SUM_H

void sumMatrix(int A[ROWS][COLS],int B[ROWS][COLS],int C[ROWS][COLS],int rowSize, int colSize){
    for (int row = 0; row < rowSize; ++row) {
        for (int col = 0; col < colSize; ++col) {
            C[row][col] = A[row][col] + B[row][col];
        }
    }
}

void doSumMat(){
    printf("ROWS = %d\nCOLS = %d\n",ROWS,COLS);
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int C[ROWS][COLS];

    int rowSize;
    int colSize;

    printf("Enter number of rows of A matrix between 1 and %d\n",ROWS);
    scanf("%d",&rowSize);

    printf("Enter number of cols of A matrix between 1 and %d\n",ROWS);
    scanf("%d",&colSize);

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            A[i][j] = (rand() % 21 ) - 10;
            B[i][j] = (rand() % 21 ) - 10;
        }
    }
    diplayMatrix("matrix A",A,rowSize,colSize);
    diplayMatrix("matrix B",B,rowSize,colSize);
    sumMatrix(A,B,C,rowSize,colSize);
    diplayMatrix("Result matrix",C,rowSize,colSize);

}

#endif //CODE_SUM_H
