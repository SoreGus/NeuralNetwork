#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    double **data;
    int rows;
    int columns;
}Matrix;

Matrix* create(int rows, int columns);
void fill(Matrix *matrix, double value);
void print(Matrix *matrix);
