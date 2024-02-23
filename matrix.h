#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int rows;
    int columns;
}Matrix;

Matrix* create(int rows, int columns);
void print(Matrix *matrix);
