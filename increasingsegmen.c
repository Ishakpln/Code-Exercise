#include <stdio.h>

int main() {
    printf("Masukkan jumlah elemen: ");
    
    int N;
    scanf("%d", &N);

    while (N < 1) {
        printf("Input tidak valid");
        printf("Masukkan jumlah elemen: ");
        scanf("%d", &N);
    }

    printf("Masukkan elemen: ");

    int arr[100];
    for (int i = 0;i < N;i++) {
        scanf("%d", &arr[i]);
    }

    int count = 1;
    int num[100];
    int max;

    if (N == 1) {
        max = 1;
    }
    else {
        int element = 0;
        for (int i = 0;i < N-1;i++) {
            if (arr[i] <= arr[i+1]) {
                count += 1;
            }
            else if ((arr[i] > arr[i+1])) {
                num[element] = count;
                count = 1;
                element += 1;           
            }

            if (i == N-2) {
                num[element] = count;
            }
        }

        max = num[0];

        for (int i = 0;i < element;i++) {
            if (num[i] < num[i+1]) {
                max = num[i+1];
            }
        } 
    }

    printf("Panjang segmen naik terpanjang: %d", max);

}