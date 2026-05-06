#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matrix {
    int **mat;
    int *arr;
    int size;
} matrix;

matrix init_matrix(int n);
void free_matrix(matrix mat);
void printSudoku(matrix mat);
int getBlockSize(int n);
bool isLegal(matrix mat, int row, int col, int value);
bool findEmptyCell(matrix mat, int *row, int *col);
bool solveSudoku(matrix mat);

matrix init_matrix(int n) {
    matrix Matrix;
    Matrix.size = n;

    Matrix.arr = malloc(sizeof(int) * n * n);
    Matrix.mat = malloc(sizeof(int *) * n);

    if (Matrix.arr == NULL || Matrix.mat == NULL) {
        printf("malloc failure - exiting\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        Matrix.mat[i] = &Matrix.arr[i * n];
    }

    for (int i = 0; i < n * n; i++) {
        Matrix.arr[i] = 0;
    }

    return Matrix;
}

void free_matrix(matrix mat) {
    free(mat.arr);
    free(mat.mat);
}

int getBlockSize(int n) {
    for (int i = 1; i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }
    return -1;
}

bool isLegal(matrix mat, int row, int col, int value) {
    for (int j = 0; j < mat.size; j++) {
        if (mat.mat[row][j] == value) {
            return false;
        }
    }

    for (int i = 0; i < mat.size; i++) {
        if (mat.mat[i][col] == value) {
            return false;
        }
    }

    int blockSize = getBlockSize(mat.size);
    if (blockSize == -1) {
        return false;
    }

    int startRow = row - (row % blockSize);
    int startCol = col - (col % blockSize);

    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < blockSize; j++) {
            if (mat.mat[startRow + i][startCol + j] == value) {
                return false;
            }
        }
    }

    return true;
}
