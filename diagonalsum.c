#include <stdio.h>
#include "ADT/matrix2D.h"

int main() {
    int N;
    printf("Masukkan dimensi matriks: ");
    scanf("%d", &N);

    while (N < 2) {
        printf("Jumlah elemen matriks tidak boleh kurang dari 2:\n");
        printf("Masukkan dimensi matriks: ");
        scanf("%d", &N);       
    }

    Matrix M;
    createMatrix(&M, N, N);
    inputMatrix(&M);

    printf("Berikut adalah matrixmu!\n");
    printMatrix(&M);

    int i = 0;
    int j = 0;
    int sum = 0;

    while (i <= N-1 && j <= N-1) {
        int val = getElement(&M, i, j);
        sum += val;
        i++;
        j++;
    }

    printf("Berikut hasil penjumlahan diagonal: %d", sum) ;
}