#include "matrixOperations.h"
#include<stdlib.h>
#include<stdio.h>

int checkMatrixMatch(Matrix* firstMatrix, Matrix* secondMatrix) {
    if (firstMatrix->rows != secondMatrix->rows || firstMatrix->columns != secondMatrix->columns) return 1;
    return 0;
}

Matrix* applyMatrixOperation(Matrix* firstMatrix, Matrix* secondMatrix, MatrixOperation operation) {
    if (checkMatrixMatch(firstMatrix, secondMatrix) == 1) {
        printf("Matrix not match");
        exit(EXIT_FAILURE);
    }
    Matrix *newMatrix = createMatrix(firstMatrix->rows, secondMatrix->columns);
    for (int i = 0; i < newMatrix->rows; i++) {
        for (int j = 0; j < newMatrix->columns; j++) {
            double firstValue = firstMatrix->data[i][j];
            double secondValue = secondMatrix->data[i][j];
            switch (operation)
            {
            case SUN: newMatrix->data[i][j] = firstValue + secondValue;
                break;
            case SUB: newMatrix->data[i][j] = firstValue - secondValue;
                break;
            case MULT: newMatrix->data[i][j] = firstValue * secondValue;
                break;
            default:
                break;
            }
        }
    }
    return newMatrix;
}

Matrix* scaleMatrix(Matrix* matrix, double value, MatrixOperation operation) {
    Matrix *newMatrix = copyMatrix(matrix);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            switch (operation)
            {
            case SUN: newMatrix->data[i][j] += value;
                break;
            case MULT: newMatrix->data[i][j] *= value;
                break;
            default:
                break;
            }
        }
    }
    return newMatrix;
}

Matrix* transposeMatrix(Matrix* matrix) {
    Matrix *newMatrix = createMatrix(matrix->columns, matrix->rows);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            newMatrix->data[j][i] = matrix->data[i][j];
        }
    }
    return newMatrix;
}

