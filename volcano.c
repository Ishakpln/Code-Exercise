#include <stdio.h>
#define MAX 1000
#define MAXHOUSESNEARBY 16

typedef struct {
    int housesNearby;
    int listOfCoordinate[MAXHOUSESNEARBY][2];
} Mountain;

typedef struct {
    Mountain mountain[MAX];
} ListOfMountain;


void countHousesNearby(char layout[MAX][MAX], int x, int y, int row, int col, ListOfMountain* listOfMountain, int indexOfMountain) {
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    int  indexOfHouses = 0;
    
    for (int i = 0;i < 8;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col)) {
            if (layout[nx][ny] == 'R') {
                listOfMountain->mountain[indexOfMountain].housesNearby += 1;
                listOfMountain->mountain[indexOfMountain].listOfCoordinate[indexOfHouses][0] = nx;
                listOfMountain->mountain[indexOfMountain].listOfCoordinate[indexOfHouses][1] = ny;
                indexOfHouses += 1;
            }
        }

    }
}

void getElement(char layout[MAX][MAX],  int row, int col) {
    char val;

    printf("Masukkan elemen layout, berupa 0 untuk tanah kosong, R untuk rumah, dan G untuk Gunung Volkano!\n");
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            printf("Masukkan elemen layout[%d][%d]: ", i, j);
            scanf(" %c", &val);
            while (!((val == '0') || (val == 'R') || (val == 'G'))) {
                printf("Input TIDAK VALID, Elemen layout hanya boleh bernilai 0, R, atau G!\n");
                printf("Masukkan elemen layout: ");
                scanf(" %c", &val);
            }
            layout[i][j] = val;
        }
    }
}

int main() {
    int row;
    int col;
    char layout[MAX][MAX];
    
    printf("Masukkan panjang layout: ");
    scanf("%d", &row);
    while (row < 0) {
        printf("Input TIDAK VALID, panjang layout harus lebih dari 0!\n");
        printf("Masukkan panjang layout: ");
        scanf("%d", &row);
    }

    printf("Masukkan lebar layout: ");
    scanf("%d", &col);
    while (col < 0) {
        printf("Input TIDAK VALID, lebar layout harus lebih dari 0!\n");
        printf("Masukkan lebar layout: ");
        scanf("%d", &col);
    }

    getElement(layout, row, col);

    printf("Kondisi layout sebelum gunung meleteus\n");
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            printf("%c ", layout[i][j]);
        }
        printf("\n");
    }

    ListOfMountain listOfMountain;
    int indexOfMountain = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            if (layout[i][j] == 'G') {
                countHousesNearby(layout, i, j, row, col, &listOfMountain, indexOfMountain);
                indexOfMountain += 1;
            }
        }
    }

    for (int i = 0;i < indexOfMountain;i++) {
        for (int j = 0;j < listOfMountain.mountain[i].housesNearby;j++) {
            layout[listOfMountain.mountain[i].listOfCoordinate[j][0]][listOfMountain.mountain[i].listOfCoordinate[j][1]] = 'X';
        }
    }

    int count = 0;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            if (layout[i][j] == 'X') {
                count += 1;
            }
        }
    }
    printf("Jumlah rumah yang hangus sebanyak %d\n", count);

    printf("Kondisi layout setelah gunung meleteus\n");
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            printf("%c ", layout[i][j]);
        }
        printf("\n");
    }



}