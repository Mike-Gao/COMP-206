// Name: Mike Gao
// ID: 260915701

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ROWS 5
#define COLS 5


void fillMatrix(int matrix[ROWS][COLS]){
    srand(clock());
     for(int o = 0; o < ROWS; o++){
        for(int i = 0; i < COLS; i++){
            matrix[o][i] = rand()% 100 + 1;
        }
     }
        
}

void printMatrix(int matrix[ROWS][COLS]){
    printf("{\n");
    for(int o = 0; o < ROWS; o++){
        printf("\t{");
        const char* delimiter = "%d";
        for(int i = 0; i < COLS; i++){
            printf(delimiter,matrix[o][i]);
            delimiter = ",%d";
        }
        printf("},\n");
     }
    printf("}\n");
}

void transposeMatrix(int matrix[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<i; j++){
            int* y = &matrix[0][0] + (i*ROWS+j);
            int* u = &matrix[0][0] + (j*ROWS+i);
            int temp;
            temp = *y;
            *y = *u;
            *u = temp;
        }
    }
}

void multiplyMatrix(int m1[2][COLS],int m2[ROWS][COLS],int resultMatrix[ROWS][COLS]){
    for(int r=0; r<ROWS; r++){
        for(int c=0; c<COLS; c++){
            resultMatrix[r][c]=0;
        }
    }
    for (int r=0; r<2; r++){
        for(int c=0; c<COLS; c++){
            for(int i=0; i<COLS; i++){
                resultMatrix[r][c] += m1[r][i] * m2[i][c];
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS];
    fillMatrix(matrix);
    printMatrix(matrix);
    transposeMatrix(matrix);
    printMatrix(matrix);
    int matrix2[2][COLS]={0,1,2,3,4,5,6,7,8,9};
    int matrixResult[ROWS][COLS];
    multiplyMatrix(matrix2, matrix, matrixResult);
    printMatrix(matrixResult);
    return 0; 
}
