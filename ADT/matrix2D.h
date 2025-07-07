#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int data[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
} Matrix2D;

void createMatrix2D(Matrix2D* m, int rows, int cols);
bool isMatrix2DValid(const Matrix2D* m);
void setMatrix2DElement(Matrix2D* m, int row, int col, int value);
int getMatrix2DElement(const Matrix2D* m, int row, int col);
void inputMatrix2D(Matrix2D* m);
void printMatrix2D(const Matrix2D* m);
Matrix2D addMatrix2D(const Matrix2D* a, const Matrix2D* b);
Matrix2D subtractMatrix2D(const Matrix2D* a, const Matrix2D* b);
Matrix2D multiplyMatrix2D(const Matrix2D* a, const Matrix2D* b);
Matrix2D transposeMatrix2D(const Matrix2D* m);
void clearMatrix2D(Matrix2D* m);

#endif
