#ifndef MATRIX3D_H
#define MATRIX3D_H

#include <stdbool.h>

#define MAX_DEPTH 50
#define MAX_ROWS 50
#define MAX_COLS 50

typedef struct {
    int data[MAX_DEPTH][MAX_ROWS][MAX_COLS];
    int depth;
    int rows;
    int cols;
} Matrix3D;

void createMatrix3D(Matrix3D* m, int depth, int rows, int cols);
bool isMatrix3DValid(const Matrix3D* m);
void setElement3D(Matrix3D* m, int z, int y, int x, int value);
int getElement3D(const Matrix3D* m, int z, int y, int x);
void inputMatrix3D(Matrix3D* m);
void printMatrix3D(const Matrix3D* m);
void clearMatrix3D(Matrix3D* m);

#endif
