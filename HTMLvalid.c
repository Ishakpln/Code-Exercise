#include <stdio.h>
#include <string.h>
#include "ADT/stackstring.h"

int valid(char open, char close) {

}

int main() {
    char html[300];
    char elmnt[100];

    printf("Masukkan kode HTML: ");
    fgets(html, sizeof(html), stdin);
    
    Stack expr;
    createStackString(&expr);

    int length = strlen(html);

    int i = 0;
    html[-1] = '-1';

    printf("hai");
    while (i != length) {
        int j = 0;
        if (html[i] == '<') {
            while (html[i-1] != '>') {
                elmnt[j] = html[i];
                i++;
                j++;
            }
            pushStackString(&expr, elmnt);
        }
    }

    displayStackString(&expr);
}