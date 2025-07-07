#include <stdio.h>
#include "num.h"
#include <string.h>
#include "liststatik.h"

int isPrime(int x) {
    int prime = 1;
    if ((x < 1) || (x == 1)) {
        return 0;
    }
    else if ((x == 2)) {
        return 1;
    }
    else {
        for (int i = 2;i < x;i++) {
            if (x % i == 0) {
                prime = 0;
                break;
            }
        }
    }

    if (prime == 1) {
        return 1;
    }
    else {
        return 0;
    }
}
int countFactor(int x) {
    int count = 0;
    for (int i = 1;i <= x;i++) {
        if (x % i == 0) {
            count += 1;
        }
    }

    return count;
}
int countPrimeFactor(int x) {
    int count = 0;
    for (int i = 2;i <= x;i++) {
        if ((x % i == 0) && isPrime(i)) {
            count += 1;
        }
    }

    return count;    
}
char* exprPrimefactor(int x) {
    static char exp[1000];
    int index = 0;
    int divisor = 2;
    char expTemp[100];
    exp[0] = '\0';
    
    while (x != 1) {
        int power = 0;
        if (x % divisor == 0 && !(exp[0] != '\0')) {
            while (x % divisor == 0) {
                power += 1;
                x /= divisor;
            }
            if (power > 1) {
                sprintf(expTemp,"%d^%d ", divisor, power);
                strcat(exp, expTemp);   
            }

            else {
                sprintf(expTemp, "%d ", divisor);
                strcat(exp, expTemp);
            }

        }

        else if  ((x % divisor == 0) && (exp[0] != '\0')) {
            strcat(exp, "* ");
            while (x % divisor == 0) {
                power += 1;
                x /= divisor;
            }
            if (power > 1) {
                sprintf(expTemp,"%d^%d ", divisor, power);
                strcat(exp, expTemp);
            }
            else {
                sprintf(expTemp, "%d ", divisor);
                strcat(exp, expTemp);
            }
        }

        else if (x % divisor != 0) {
            divisor += 1;
        }
    }    

    return exp;
}
ListStatik PrimeFactor(int x) {
    ListStatik prime;
    createListStatik(&prime);

    for (int i = 2;i <= x;i++) {
        if ((x % i == 0) && isPrime(i)) {
            insertLast(&prime, i);
        }
    }

    return prime;
}
int FPB(int x, int y) {
    if ((x < 1)) {
        printf("nilai x kurang dari 1!\n");
        return -1;
    }
    else if (y < 1) {
        printf("nilai y kurang dari 1!\n");
        return -1;
    }
    else {
        for (int i = x;i >= 1;i--) {
            if ((x % i == 0) && (y % i == 0)) {
                return i;
            }
        }
    }
}
int KPK(int x, int y) {
    return (x*y)/FPB(x,y);
}

int power(int x, int y) {
    if ((x == 0) && (y == 0)) {
        printf("0^0 terdeteksi, nilai diasumsikan 1\n");
        return 1;
    }
    else if (x == 0) {
        return 0;
    }
    else if (y == 0) {
        return 1;
    }

    else {
    int result = x;
        for (int i = 1;i <= y-1;i++) {
            result *= x; 
        }
        return result;
    }

}

int isPerfectSquare(int x) {
    if (x < 0) {
        printf("nilai x negatif!\n");
        return 0;
    } 
    for (int i = 0; i <= x;i++) {
        if ((long long)i*i == x) {
            return 1;
        }
    }
    return 0;
}

int perfectSquare(int x) {
    if (!(isPerfectSquare(x))) {
        printf("Bukan bilangan kuadrat sempurna\n");
        return -1;
    }
    else {
        for (int i = 0; i <= x;i++) {
            if ((long long)i*i == x) {
                return i;
            }
        }       
    }

}
int nthPrime(int x) {
    if (!(isPrime(x))) {
        printf("Bukan bilangan prima!\n");
        return -1;
    }
    else {
        int index = 0;
        for (int i = 2;i <= x;i++) {
            if (isPrime(i)) {
                index += 1;
            }
        }
        return index;
    }
}