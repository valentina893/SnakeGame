#pragma once

typedef struct matrix {

    int rows;
    int cols;
    int size;
    int** data;

} matrix;

matrix createMatrix(int numRows, int numCols);

void setMatrix(int newData, matrix* mat);

void deleteMatrix(matrix* mat);

void stringMatrix(matrix mat);