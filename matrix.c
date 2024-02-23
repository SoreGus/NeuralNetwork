#include "matrix.h"

Matrix* create(int rows, int columns) {
    Matrix *matrix;
    matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    matrix->data = malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix->data[i] = malloc(columns * sizeof(double));
        }
    }
    return matrix;
}

void print(Matrix *matrix) {
    printf("Matrix:\n\n");
    printf("Rows: %d\n", matrix->rows);
    printf("Columns: %d\n", matrix->columns);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
           printf("%.0f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

void fill(Matrix *matrix, double value) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            matrix->data[i][j] = value;
        }
    }
}