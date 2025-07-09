#include <stdio.h>
#include "ADT/matrix2D.h"


int islandIDXLength = 0;

void add() {
    islandIDXLength += 1;
}

int isElementInIslandIDXExist(Matrix2D M, int x, int y) {
    for (int i = 0;i < islandIDXLength;i++) {
        if ((M.data[i][0] == x) && (M.data[i][1] == y)) {
            return 1;
        }
    }
    return 0;
}

void addElemenToIslandIDX(Matrix2D *M, int x, int y) {
    M->data[islandIDXLength][0] = x;
    M->data[islandIDXLength][1] = y;
}

Matrix2D* findAllRelated(Matrix2D* M, Matrix2D *island) {
    int done;

    for (int i = 0;i < islandIDXLength;i++) {
        done = 0;

        if ((M->data[island->data[i][0]-1][island->data[i][1]] == 1) && isElementInIslandIDXExist(*island, island->data[i][0]-1,island->data[i][1]) == 0) {
            addElemenToIslandIDX(island, island->data[i][0]-1, island->data[i][1]);
            add();
        }
        else {
            done += 1;
        }

        if ((M->data[island->data[i][0]][island->data[i][1]-1] == 1) && isElementInIslandIDXExist(*island, island->data[i][0],island->data[i][1]-1) == 0) {
            addElemenToIslandIDX(island, island->data[i][0], island->data[i][1]-1);
            add();
        }
        else {
            done += 1;
        }

        if ((M->data[island->data[i][0]][island->data[i][1]+1] == 1) && isElementInIslandIDXExist(*island, island->data[i][0],island->data[i][1]+1) == 0) {
            addElemenToIslandIDX(island, island->data[i][0], island->data[i][1]+1);
            add();
        }
        else {
            done += 1;
        }

        if ((M->data[island->data[i][0]+1][island->data[i][1]] == 1) && isElementInIslandIDXExist(*island, island->data[i][0]+1,island->data[i][1]) == 0) {
            addElemenToIslandIDX(island, island->data[i][0]+1, island->data[i][1]);
            add();
        }
        else {
            done += 1;
        }
    }

    if (done < 4) {
        return findAllRelated(M, island);
    }
    else {  
        return island;
    }
}


int main() {
    //-----------------
    Matrix2D M;
    int row;
    int col;

    printf("\n");
    printf("Masukkan dimensi Matrix!\n");\

    printf("Masukkan jumlah baris: ");
    scanf("%d", &row);
    while (row < 1 || row > 9) {
        printf("Jumlah baris tidak boleh kurang dari 1 dan tidak boleh lebih dari 9!\n");
        printf("Masukkan jumlah baris: ");
        scanf("%d", &row);
    }

    printf("Masukkan jumlah kolom: ");
    scanf("%d", &col);
    while (col < 1 || col > 9) {
        printf("Jumlah baris tidak boleh kurang dari 1 dan tidak boleh lebih dari 9!");
        printf("Masukkan jumlah kolom: ");
        scanf("%d", &col);
    }

    createMatrix2D(&M, row+2,col+2);

    for (int j = 0;j <= col+1;j++) {
        M.data[0][j] = 0;
    }

    for (int i = 0;i <= row+1;i++) {
        M.data[i][0] = 0;
        M.data[i][col+1] = 0;
    }
    for (int j = 0;j <= col+1;j++) {
        M.data[row+1][j] = 0;
    }

    int value;
    for (int i = 1;i <= row;i++) {
        for (int j = 1;j <= col;j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &value);

            while (!(value == 1 || value == 0)) {
                printf("Nilai tiap elemen harZus bernilai 0 atau 1!\n");
                printf("Elemen [%d][%d]: ", i, j);
                scanf("%d", &value);    
            }

            M.data[i][j] = value;
        }
    }
    
    printf("Berikut adalah tampilan pulau dan laut\n");
        for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            printf("%d ", M.data[i][j]);
        }
        printf("\n");
    }
  
    Matrix2D islandIDX;
    createMatrix2D(&islandIDX, 1000, 2);

    int countIsland = 0;
    for (int i = 1;i <= row;i++) { 
        for (int j = 1;j <= col;j++) {
            if ((M.data[i][j] == 1) && (isElementInIslandIDXExist(islandIDX, i, j) == 0) ) {
                addElemenToIslandIDX(&islandIDX, i, j); 
                add();
                findAllRelated(&M, &islandIDX);
                countIsland += 1;
            }
            
        }
    }


    printf("Total semua pulau adalah %d", countIsland);
    
}