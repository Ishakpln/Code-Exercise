    #include <stdio.h>

    int absolut(int x) {
        if (x < 0) {
            x = x*(-1);
        }
        else {
            x = x;
        }

        return x;
    }


    int main() {
        int N;
        printf("Masukkan jumlah elemen: ");
        scanf("%d", &N);
        while (N < 2) {
            printf("Jumlah elemen tidak bole kurang dari 2\n");
            printf("Masukkan jumlah elemen: ");
            scanf("%d", &N);
        }

        int arr[100];
        for (int i = 0;i<N;i++) {
            printf("Masukkan elemen ke-%d: ", i+1);
            scanf("%d", &arr[i]);
        }

        int min = absolut(arr[0] - arr[1]);
        for (int i = 0;i < N-1;i++) {
            for (int j = i+1; j < N;j++) {
                if (absolut(arr[i] - arr[j]) < min) {
                    min = absolut(arr[i] - arr[j]);
                }
            }
        }

        for (int i = 0;i < N-1;i++) {
            for (int j = i+1; j < N;j++) {
                if (absolut(arr[i] - arr[j]) == min) {
                    printf("Pasangan dengan selisih terkecil: (%d, %d)", arr[i], arr[j]);
                    break;
                }
            }
        }
    }