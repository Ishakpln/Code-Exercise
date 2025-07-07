#include <stdio.h>

int main() {
    int n;
    int result;
    
    printf("Masukkan jumlah gladiator: ");
    scanf("%d", &n);

    while (n < 2) {
        printf("Jumlah gladiator tidak boleh kurang dari 2!\n");
        printf("Masukkan jumlah gladiator: ");
        scanf("%d", &n);
    }

    int arena[1000];
    for (int i = 0;i < n;i++) {
        printf("Masukkan kekuatan gladiator ke-%d: ", i+1);
        scanf("%d", &arena[i]);
        while (arena[i] < 0) {
            printf("Kekuatan tidak boleh kurang dari 0!\n");
            printf("Masukkan kekuatan gladiator ke-%d: ", i+1);
            scanf("%d", &arena[i]);
            }
    }



    for(;;) {
        int max = arena[0];

        for (int i = 0;i < n-1;i++) {
            if (arena[i+1] > arena[i]) {
                max = arena[i+1];
            }
        }



            int max2 = 0;
            for (int i = 0;i < n-1;i++) {
                if ((arena[i+1] > arena[i]) && (arena[i+1] == max)) {
                    max2 = max2;
                }
                else if (arena[i+1] > arena[i]) {
                    max2 = arena[i+1];
                }
            }


        int idxmax;
        for (int i = 0;i < n;i++) {
            if (arena[i] == max) {
                idxmax = i;

            }
        }

        int idxmax2;
        for (int i = 0;i < n;i++) {
            if (arena[i] == max2) {
                idxmax2 = i;
            }
        }


        int checktemp = arena[idxmax];
        arena[idxmax] = arena[idxmax] - arena[idxmax2];
        arena[idxmax2] = arena[idxmax2] - arena[idxmax2];
        if (arena[idxmax] == checktemp) {
            break;
        }
        int result = arena[idxmax];
        
    }

    printf("%d", result);
}