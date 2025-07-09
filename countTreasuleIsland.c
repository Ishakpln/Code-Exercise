#include <stdio.h>

#define MAX 1000

char M[MAX][MAX];
int visited[MAX][MAX];
int treasure[MAX][MAX];
int row;
int col;
int elementOfTreasure = 0;
int elementOfIslandLiST = 0;
int elementOfTreasureList = 0;
int countTreasure;

typedef struct 
{
int contents[MAX][2];
} ListOfTreasureIndex; 

typedef struct 
{
ListOfTreasureIndex contents[MAX];
} ListOfIsland;

ListOfIsland listOfIsland;

void DFS(int x, int y) {
    if ((x < 0) || (x >= row) || (y < 0) || (y >= col)) {
        return;
    }
    
    if (((M[x][y] == '1') || (M[x][y] == 'T')) && (visited[x][y] == 0)) {
        if ((M[x][y] == 'T')) {
            countTreasure += 1;
            listOfIsland.contents[elementOfIslandLiST].contents[elementOfTreasureList][0] = x;
            listOfIsland.contents[elementOfIslandLiST].contents[elementOfTreasureList][1] = y; 
            elementOfTreasureList += 1;
        }
        visited[x][y] = 1;
        DFS(x-1, y);
        DFS(x+1, y);
        DFS(x, y-1);
        DFS(x, y+1);
    }
}

int TIsValid() {
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            if (M[i][j] == 'T') {
                if ((i-1 < 0) && (j-1 < 0)) {
                    if ((M[i+1][j] == '0') && (M[i][j+1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;                      
                    }
                }
                else if ((i-1 < 0) && (j+1 >= col)) {
                    if ((M[i+1][j] == '0') && (M[i][j-1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((i+1 >= row) && (j-1 < 0)) {
                    if ((M[i-1][j] == '0') && (M[i][j+1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((i+1 >= row) && (j+1 >= col)) {
                    if ((M[i-1][j] == '0') && (M[i][j-1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((i-1 < 0)) {
                    if ((M[i+1][j] == '0') && (M[i][j-1] == '0') && (M[i][j+1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((i+1 >= row)) {
                    if ((M[i-1][j] == '0') && (M[i][j-1] == '0') && (M[i][j+1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((j+1 >= col)) {
                    if ((M[i+1][j] == '0') && (M[i][j-1] == '0') && (M[i-1][j] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else if ((j-1 < 0)) {
                    if ((M[i+1][j] == '0') && (M[i][j+1] == '0') && (M[i-1][j] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }
                }
                else {
                    if ((M[i+1][j] == '0') && (M[i][j-1] == '0') && (M[i-1][j] == '0') && (M[i][j+1] == '0')) {
                        printf("Input TIDAK VALID, T tidak boleh di tengah lautan, kesalahan di index (%d, %d)!\n", j,i);
                        return 0;
                    }                    
                }
            }
        }
    }
    return 1;
}

void fillingMatrix() {
    char val;
    for (int i = 0;i < row;i++) {
        for (int j = 0;j < col;j++) {
            printf("Masukkan elemen ke [%d][%d]: ", i, j);
            scanf(" %c", &val);
            while ((val != '1') && (val != '0') && (val != 'T')) {
                printf("Input tidak valid, input hanya bisa bernilai 1,0, atau T!\n");
                printf("Masukkan elemen ke [%d][%d]: ", i, j);
                scanf(" %c", &val);
            }
            M[i][j] = val;
            visited[i][j] = 0;             
        }
    }
}

int main() {

    printf("Masukkan dimensi Matrix!\n");

    printf("Masukkan jumlah baris: ");
    scanf("%d", &row);
    while (row < 1) {
        printf("Jumlah baris tidak boleh kurang dari 1!\n");
        printf("Masukkan jumlah baris: ");
        scanf("%d", &row);    
    }

    printf("Masukkan jumlah kolom: ");
    scanf("%d", &col);
    while (col < 1) {
        printf("Jumlah kolom tidak boleh kurang dari 1!\n");
        printf("Masukkan jumlah kolom: ");
        scanf("%d", &col);    
    }

    fillingMatrix();

    while (TIsValid() == 0) {
        printf("Berikut adalah tampilan layout yang salah!\n");
        
        for (int i = 0;i < row;i++) {
            for  (int j = 0;j < col;j++) {
                printf(" %c", M[i][j]);
            }
            printf("\n");
        }

        printf("Masukkan input ulang!\n");
        fillingMatrix();
    }

    printf("Berikut adalah tampilan layout!\n");
    
    for (int i = 0;i < row;i++) {
        for  (int j = 0;j < col;j++) {
            printf(" %c", M[i][j]);
        }
        printf("\n");
    }

    int countIsland = 0;
    int treasure[MAX];
    int elementOfTreasure = 0;

    for (int i = 0;i < row;i++) {
        for  (int j = 0;j < col;j++) {
            countTreasure = 0;
            if ((M[i][j] == '1') && (visited[i][j] == 0)) {
                elementOfTreasureList = 0;        
                DFS(i, j);
                countIsland += 1;
                treasure[elementOfTreasure] = countTreasure;  
                elementOfTreasure += 1;  
                elementOfIslandLiST += 1;            
            }
        }
    }

    int max = -1;
    for (int i = 0; i < elementOfTreasure;i++) {
        if (max < treasure[i]) {
            max = treasure[i];
        }
    }

    int richestIsland;
    for (int i = 0;i < elementOfTreasure;i++) {
        if (max == treasure[i]) {
            richestIsland = i;
            break;
        }
    }

    printf("Jumlah pulau sebanyak %d\n", countIsland);
    printf("Jumlah treasure terbanyak dalam satu pulau adalah %d\n", max);
    printf("Daftar koordinat treasure pada pulau terkaya adalah: ");
    printf("[ ");
    for (int i = 0;i < max;i++) {
        printf("(%d, %d) ", listOfIsland.contents[richestIsland].contents[i][1], listOfIsland.contents[richestIsland].contents[i][0]);
    }
    printf("]");
 
}
