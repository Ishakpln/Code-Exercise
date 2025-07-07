#include <stdio.h>
#include "ADT/stackstring.h"

int main() {
    char exprc[300];
    printf("Masukkan ekspresi: ");
    fgets(exprc, sizeof(exprc), stdin);

    int neutral = 0; //valid jika pada akhirnya nilai neutral 0 && nilai neutral tidak pernah > 0
    char value;
    int valid = 1;

    char ch = exprc[0];
    int i = 0;
    int length = 0;

    while (ch != '\0') {
        ch = exprc[i];  
        length += 1;
        i++;
    }

    length--;

    Stack expr;
    createStackString(&expr);

    for (int i = 0;i < length;i++) {
        pushStackString(&expr, exprc[i]);
    }

    while (!(isStackStringEmpty(&expr))) {
        popStackString(&expr, &value);
        if (value == ')') {
            neutral--;
        }
        else if (value == '(') {
            neutral++;
        }
        
        if (neutral > 0) {
            valid = 0;
            break;
        }
    }

    if (neutral != 0) {
        valid = 0;
    }

    if (valid == 1) {
        printf("Valid");
    }
    else {
        printf("Tidak Valid");
    }
}