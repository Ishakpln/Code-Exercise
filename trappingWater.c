#include <stdio.h>
#include "ADT/liststatik.h"

int main() {
    ListStatik L;
    createListStatik(&L);
    
    printf("Masukkan jumlah pilar: ");

    int N;
    scanf("%d", &N);

    while ( N < 1) {
        printf("Input tidak boleh kurang dari 1!\n") ;
        printf("Masukkan jumlah pilar");
        scanf("%d", &N);
        
    }

    printf("Masukkan tinggi tiap pilar!\n");

    int val;
    for (int i = 0;i < N;i++) {
        printf("Pilar ke %d: ", i+1);
        scanf("%d", &val);

        while (val < 0) {
            printf("Tinggi pilar tidak boleh kurang dari 0!\n");
            printf("Pilar ke %d: ", i+1);
            scanf("%d", &val);
        }
        insertAt(&L, val, i);      
    }

    printf("Berikut adalah tinggi tiap pilar!\n");
    printList(L);

    //Algoritma Utama

        ListStatik L1;
        createListStatik(&L1);
        ListStatik L2;
        createListStatik(&L2);


    int waterV = 0;
   
    if ((N == 1) || (N == 2)) {
        waterV = 0;
    }
    else {
        for (int i = 0;i < N;i++) {
            int max = getListElement(L, 0);
            for (int j = 0;j <= i;j++) {
                if (max < getListElement(L,j)) {
                    max = getListElement(L,j);
                }
            }
            insertAt(&L1,max,i);
        }

        for (int i = 0;i < N;i++) {
            int max = getListElement(L, N-1);
            for (int j = i;j <= N-1;j++) {
                if (max < getListElement(L,j)) {
                    max = getListElement(L,j);
                }
            }
            insertAt(&L2,max,i);
        }
    }

    ListStatik water;
    createListStatik(&water);

    for (int i = 0;i < N;i++) {
        if (getListElement(L1,i) < getListElement(L2,i)) {
            insertAt(&water, getListElement(L1,i), i);
        }
        else {
            insertAt(&water, getListElement(L2,i), i);            
        }
    }


    for (int i = 0;i < N;i++) {
        waterV += (getListElement(water,i) - getListElement(L,i));
    }

    printf("Total volume air yang terjebak adalah: %d", waterV);
    
}