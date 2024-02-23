#include "matrix.h"
#include<stdio.h>
#include<stdlib.h>

#define MAXCHAR 100

Matrix* createMatrix(int rows, int columns) {
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

void printMatrix(Matrix *matrix) {
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

void fillMatrix(Matrix *matrix, double value) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            matrix->data[i][j] = value;
        }
    }
}

void freeMatrix(Matrix *matrix) {
    for (int i = 0; i < matrix->columns; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
    matrix = NULL;
}

Matrix* copyMatrix(Matrix *matrix) {
    Matrix *copy = createMatrix(matrix->rows, matrix->columns);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            copy->data[i][j] = copy->data[i][j];
        }
    }
    return copy;
}

void saveMatrix(Matrix *matrix, char* path) {
    FILE *file = fopen(path, "w");
    fprintf(file, "%d\n", matrix->rows);
    fprintf(file, "%d\n", matrix->columns);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            fprintf(file, "%.6f\n", matrix->data[i][j]);
        }
    }
    fclose(file);
}

Matrix* loadMatrix(char* path) {
    FILE *file = fopen(path, "r");
    char entry[MAXCHAR];
    fgets(entry, MAXCHAR, file);
    int rows = atoi(entry);
    fgets(entry, MAXCHAR, file);
    int columns = atoi(entry);
    Matrix *matrix = createMatrix(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fgets(entry, MAXCHAR, file);
            matrix->data[i][j] = strtod(entry, NULL);
        }
    }
    fclose(file);
    return matrix;
}
