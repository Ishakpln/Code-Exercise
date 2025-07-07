#include <stdio.h>


int power(int x, int y) { //x^y
    int res = x;

    if (y == 0) {
        return 1;
    }

    else if (y == 1) {
        return x;
    }

    for (int i = 0;i <= y-2;i++) {
        res *= x;
    }

    return res;
}

int main() {
    int N;
    printf("Masukkan angka: ");
    scanf("%d", &N);

    int element = 0;

    while (N > power(2,element)) {
        element += 1;
    }

    printf("\n");

    if (N > 1) {
        printf("%d", 1);
            N -= power(2,element - 1);
    }

    for (int i = element-2;i >= 0;i--) {
        if (N < power(2,i)) {
            printf("%d", 0);
        }
        else {
            printf("%d", 1);
            N -= power(2,i);
        }
    }

}