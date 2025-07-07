#include <stdio.h>

int main() {
    int N;
    printf("Masukkan jumlah elemen dalam array: ");
    scanf("%d", &N);
    while (N < 2) {
        printf("Jumlah elemen tidak boleh kurang dari 2!");
        printf("Masukkan jumlah elemen dalam array: ");
        scanf("%d", &N);  
    }
    int arr[100];
    for (int i = 0;i < N;i++) {
        printf("Masukkan elemen ke - %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Masukkan target: ");
    scanf("%d", &x);

    printf("[");
    for (int i = 0;i < N;i++) {
        for (int j = i+1;j < N;j++) {
            if (arr[i] + arr[j] == x) {
                printf("(%d,%d), ",arr[i], arr[j]);
            }

            else if ((i == N-2) && (j == N-1) && (arr[i] + arr[j] == x)) {
                printf("(%d,%d)", arr[i], arr[j]);
            }

            else if ((i == N-2) && (j == N-1) && !(arr[i] + arr[j] == x)) {
                printf("\b\b");
            }
        }
    }
    printf("]");



    
}