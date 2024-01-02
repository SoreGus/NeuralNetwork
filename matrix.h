#include<stdio.h>
#include<malloc.h>

typedef struct
{
    int rows;
    int columns;
}Matrix;

Matrix* create(int rows, int columns);
void print(Matrix *matrix);