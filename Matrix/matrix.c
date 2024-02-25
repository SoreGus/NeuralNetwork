#include "matrix.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include <time.h> 

#define MAXCHAR 100
int srandIsRead = 0;

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
           printf("%.2f ", matrix->data[i][j]);
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
            copy->data[i][j] = matrix->data[i][j];
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

void initSRandIfNedded() {
    if (srandIsRead == 0) {
        srand(time(NULL));
        srandIsRead = 1;
    }
}

double uniformDistribution(double low, double high) {
    initSRandIfNedded();
    double difference = high - low;
    int scale = 10000;
    int scaledDifference = (int)(difference * scale);
    return low + (1.0 * (rand() % scaledDifference) / scale);
}

void randomizeMatrix(Matrix *matrix, int number) {
    int min = -1.0 / sqrt(number);
    int max = 1.0 / sqrt(number);
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            matrix->data[i][j] = uniformDistribution(min, max);
        }
    }
}

int flattenMatrixMaxValueIndex(Matrix *matrix) {
    if (matrix->columns > 1) {
        printf("flatten matrix must have only 1 colum");
        exit(EXIT_FAILURE);
    }
    double maxValue = 0;
    int index = 0;
    for (int i = 0; i < matrix->rows; i++) {
        if (matrix->data[i][0] > maxValue) {
            maxValue = matrix->data[i][0];
            index = i;
        }
    }
    return index;
}

Matrix* flattenMatrix(Matrix *matrix, int axis) {
    Matrix *flattenMatrix;
    if (axis < 1) {
        flattenMatrix = createMatrix(matrix->rows * matrix->columns, 1);
    } else {
        flattenMatrix = createMatrix(1, matrix->rows * matrix->columns);
    }
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            if (axis < 1) {
                flattenMatrix->data[i * matrix->columns + j][0] = matrix->data[i][j];
            } else {
                flattenMatrix->data[0][i * matrix->columns + j] = matrix->data[i][j];
            }
        }
    }
    return flattenMatrix;
}









