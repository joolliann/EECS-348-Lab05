#include <stdio.h>
#define SIZE 5

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]);
void transposeMatrix(int m1[SIZE][SIZE], int m3[SIZE][SIZE]);
void printMatrix(int m1[SIZE][SIZE]);

int main(){
    /*Be starting point of the program*/
    int m1[SIZE][SIZE] = {
        {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}
    };
    int m2[SIZE][SIZE] = {
        {21,22,23,24,25},{16,17,18,19,20},{11,12,13,14,15},{6,7,8,9,10},{1,2,3,4,5}
    };
    int m3[SIZE][SIZE];
    printf("Matrix 1: \n");
    printMatrix(m1);
    printf("Matrix 2: \n");
    printMatrix(m2);
    printf("\nAdded Matrix:\n");
    addMatrices(m1,m2,m3);
    printMatrix(m3);
    printf("\nMultiplied Matrix: \n");
    multiplyMatrices(m1,m2,m3);
    printMatrix(m3);
    printf("\nTranspose Matrix 1: \n");
    transposeMatrix(m1, m3);
    printMatrix(m3);
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]){
    /*Add the two matrices*/
    int i,j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int m3[SIZE][SIZE]){
    /*Multiply the two matrices, no error handling because always symmetrical matrix*/
    int i,j,k;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            m3[i][j] = 0;
        }
    }
    /*Makes sure input matrix is set to a zero matrix*/
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            for (k = 0; k < SIZE; k++){
                m3[i][j] = m1[i][k]*m2[k][j] + m3[i][j];
            }
        }
    }
    /*Uses another for loop at the bottom to make sure that the correct indices are being multiplied together then added*/

}

void printMatrix(int m1[SIZE][SIZE]){
    /*Print given matrix*/
    int i,j;
    for (i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%d ", m1[i][j]);
        }
        printf("\n");
    }
}

void transposeMatrix(int m1[SIZE][SIZE], int m3[SIZE][SIZE]){
    /*Transpose the given matrix*/
    int i, j;
    for (i = 0; i < SIZE; i++){
        for (j = 0; j < SIZE; j++){
            m3[i][j] = m1[j][i];
        }
    }
}
