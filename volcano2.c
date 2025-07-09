#include <stdio.h>

#define MAX 1000

typedef struct {
    int rows;
    int cols;
    char elements[MAX][MAX];
} Matrix;


void findHousesInRange(Matrix *layout, int x, int y, int range) {
    int targetX = x + range;
    int targetY = y + range;
    for (int i = x - range;i <= targetX;i++) {
        for (int j = y - range;j <= targetY;j++) {
            if (i < 0) {
                i = 0;
            }
            if (i >= layout->rows) {
                targetX = layout->rows - 1;
                i = layout->rows - 1;
            }
            if (j < 0) {
                j = 0;
            }
            if (j >= layout->cols) {
                targetY = layout->cols - 1;
                y = layout->cols - 1;
            }
            if (layout->elements[i][j] == 'R') {
                layout->elements[i][j] = 'X'; 
            }

        }
    }
}

void getLayoutElement(Matrix *layout) {
    printf("Masukkan elemen layout, elemen berupa V untuk volcano, R untuk rumah, dan 0 untuk tanah kosong!\n");
    for (int i = 0;i < layout->rows;i++) {
        for (int j = 0;j < layout->cols;j++) {
            printf("Masukkan elemen ke-[%d][%d]: ", i, j);
            scanf(" %c", &layout->elements[i][j]);
            while (!((layout->elements[i][j] == 'R') || (layout->elements[i][j] == '0') || (layout->elements[i][j] == 'V'))) {
                printf("Input TIDAK VALID, elemen hanya bisa bernilai V, R, atau 0\n");
                printf("Masukkan elemen ke-[%d][%d]: ", i, j);
                scanf(" %c", &layout->elements[i][j]);        
            }
        }
    }
}

int main() {
    Matrix layout;

    printf("Masukkan dimensi layout!\n");    
    printf("Masukkan jumlah baris: ");
    scanf("%d", &layout.rows);
    while (layout.rows <= 0 || layout.rows > MAX) {
        printf("Jumlah baris harus bernilai antara 1 sampai 1000");
        printf("Masukkan jumlah baris: ");
        scanf("%d", &layout.rows);
    }
    printf("Masukkan jumlah kolom: ");
    scanf("%d", &layout.cols);
    while (layout.cols <= 0 || layout.cols > MAX) {
        printf("Jumlah kolom harus bernilai antara 1 sampai 1000");
        printf("Masukkan jumlah kolom: ");
        scanf("%d", &layout.cols);
    }

    int range;
    printf("Masukkan range letusan untuk tiap volcano: ");
    scanf("%d", &range);
    while (range < 0) {
        printf("nilai range tidak boleh kurang dari 0\n");
        printf("Masukkan range letusan untuk tiap volcano: ");
        scanf("%d", &range);    
    }

    getLayoutElement(&layout);

    printf("Layout sebelum volcano meletus: \n");
    for (int i = 0;i < layout.rows;i++) {
        for (int j = 0;j < layout.cols;j++) {
            printf("%c ", layout.elements[i][j]);
        }
        printf("\n");
    }

    for (int i = 0;i < layout.rows;i++) {
        for (int j = 0;j < layout.cols;j++) {
            if (layout.elements[i][j] == 'V') {
                findHousesInRange(&layout, i, j, range);
            }
        }
    }

    printf("Layout setelah volcano meletus: \n");
    for (int i = 0;i < layout.rows;i++) {
        for (int j = 0;j < layout.cols;j++) {
            printf("%c ", layout.elements[i][j]);
        }
        printf("\n");
    }

    
}  