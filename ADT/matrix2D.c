#include <stdio.h>
#include <stdlib.h>
#include "matrix2D.h"

void createMatrix2D(Matrix2D* m, int rows, int cols) {
    m->rows = rows;
    m->cols = cols;
}

bool isMatrix2DValid(const Matrix2D* m) {
    return (m->rows > 0 && m->rows <= MAX_ROWS &&
            m->cols > 0 && m->cols <= MAX_COLS);
}

void setMatrix2DElement(Matrix2D* m, int row, int col, int value) {
    if (row >= 0 && row < m->rows && col >= 0 && col < m->cols) {
        m->data[row][col] = value;
    }
}

int getMatrix2DElement(const Matrix2D* m, int row, int col) {
    if (row >= 0 && row < m->rows && col >= 0 && col < m->cols) {
        return m->data[row][col];
    }
    return 0;
}

void inputMatrix2D(Matrix2D* m) {
    printf("Masukkan elemen matrix2d%dx%d:\n", m->rows, m->cols);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &m->data[i][j]);
        }
    }
}

void printMatrix2D(const Matrix2D* m) {
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            printf("%d ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix2D addMatrix2D(const Matrix2D* a, const Matrix2D* b) {
    Matrix2D result;
    createMatrix2D(&result, a->rows, a->cols);
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Ukuran matrix2d tidak sama!\n");
        return result;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }
    return result;
}

Matrix2D subtractMatrix2D(const Matrix2D* a, const Matrix2D* b) {
    Matrix2D result;
    createMatrix2D(&result, a->rows, a->cols);
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Ukuran matrix2d tidak sama!\n");
        return result;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result.data[i][j] = a->data[i][j] - b->data[i][j];
        }
    }
    return result;
}

Matrix2D multiplyMatrix2D(const Matrix2D* a, const Matrix2D* b) {
    Matrix2D result;
    createMatrix2D(&result, a->rows, b->cols);
    if (a->cols != b->rows) {
        printf("Ukuran tidak cocok untuk perkalian matrix!\n");
        return result;
    }
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a->cols; k++) {
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            }
        }
    }
    return result;
}

Matrix2D transposeMatrix2D(const Matrix2D* m) {
    Matrix2D result;
    createMatrix2D(&result, m->cols, m->rows);
    for (int i = 0; i < m->rows; i++) {
        for (int j = 0; j < m->cols; j++) {
            result.data[j][i] = m->data[i][j];
        }
    }
    return result;
}

void clearMatrix2D(Matrix2D* m) {
    m->rows = 0;
    m->cols = 0;
}
