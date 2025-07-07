#ifndef NUM_H
#define NUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPrime(int x);
int countFactor(int x);
int countPrimeFactor(int x);
char* exprPrimefactor(int x);
int* PrimeFactor(int x);
int FPB(int x, int y);
int KPK(int x, int y);
int power(int x, int y);
int isDivisible(int x, int y);
int isPerfectSquare(int x);
int nthPrime(int x);

#endif