#ifndef CODE_DISPLAYMATRIX_H
#define CODE_DISPLAYMATRIX_H

void diplayMatrix(char* name,int matrix[][N],int rowSize,int colSize){
    printf("************ %s ************\n",name);
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            printf("%5i",matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif //CODE_DISPLAYMATRIX_H
