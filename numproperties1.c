#include <stdio.h>


int countfac(int x) {
    int count = 0;
    for (int i = 1;i <= x;i++) {
        if (x % i == 0) {
            count += 1;
        } 
    }

    return count;
}

int countprimefac(int x) {
    int count = 0;
    int divisor = 2;
    int oldDivisor = 1;

    while (x != 1) {
        if (x % divisor == 0) {
            x = x/divisor;
            if (divisor != oldDivisor) {
                count += 1;
                oldDivisor = divisor;
            }                    
        }
        else {
            divisor++;
        }
    }

    return count;
}


int isprime(int x) {
    int prime = 1;
    if (x <= 1) {
        prime = 0;
    }
    else {
        for (int i = 2;i < x;i++) {
            if (x % i == 0) {
                prime = 0;
                break;
            }
        }
    }
    

    return prime;
}

int nextprime(int x) {
    int nextnum = x + 1;  

    while(1) {
        if (isprime(nextnum) != 1) {
            nextnum++;
        }
        else {
            return nextnum;
        }
    }
    
}



int main() {
    int N;
    printf("Masukkan bilangan: ");
    scanf("%d", &N);

    printf("Jumlah faktor: %d\n", countfac(N));
    printf("Jumlah faktor prima: %d\n", countprimefac(N));
    if (isprime(N) == 1) {
        printf("%d adalah bilangan prima\n", N);
    }
    else {
        printf("%d bukan bukan bilangan prima\n", N);
        printf("Bilangan prima setelah %d: %d\n",N, nextprime(N));
    }
}