#include "matrix.h"

Matrix* create(int rows, int columns) {
    Matrix *matrix;
    matrix = malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->columns = columns;
    return matrix;
}

void print(Matrix *matrix) {
    printf("Matrix:\n\n");
    printf("Rows: %d\n", matrix->rows);
    printf("Columns: %d\n", matrix->columns);
}