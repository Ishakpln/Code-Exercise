#include <stdio.h>
#include "matrix3D.h"

void createMatrix3D(Matrix3D* m, int depth, int rows, int cols) {
    m->depth = depth;
    m->rows = rows;
    m->cols = cols;
}

bool isMatrix3DValid(const Matrix3D* m) {
    return m->depth > 0 && m->depth <= MAX_DEPTH &&
           m->rows > 0 && m->rows <= MAX_ROWS &&
           m->cols > 0 && m->cols <= MAX_COLS;
}

void setElement3D(Matrix3D* m, int z, int y, int x, int value) {
    if (z >= 0 && z < m->depth && y >= 0 && y < m->rows && x >= 0 && x < m->cols) {
        m->data[z][y][x] = value;
    }
}

int getElement3D(const Matrix3D* m, int z, int y, int x) {
    if (z >= 0 && z < m->depth && y >= 0 && y < m->rows && x >= 0 && x < m->cols) {
        return m->data[z][y][x];
    }
    return 0;
}

void inputMatrix3D(Matrix3D* m) {
    printf("Input elemen matrix 3D %dx%dx%d:\n", m->depth, m->rows, m->cols);
    for (int z = 0; z < m->depth; z++) {
        printf("Lapisan ke-%d:\n", z);
        for (int y = 0; y < m->rows; y++) {
            for (int x = 0; x < m->cols; x++) {
                printf("Elemen [%d][%d][%d]: ", z, y, x);
                scanf("%d", &m->data[z][y][x]);
            }
        }
    }
}

void printMatrix3D(const Matrix3D* m) {
    for (int z = 0; z < m->depth; z++) {
        printf("Lapisan ke-%d:\n", z);
        for (int y = 0; y < m->rows; y++) {
            for (int x = 0; x < m->cols; x++) {
                printf("%d ", m->data[z][y][x]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void clearMatrix3D(Matrix3D* m) {
    m->depth = 0;
    m->rows = 0;
    m->cols = 0;
}
