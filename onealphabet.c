#include <stdio.h>

char* unique(char arr[], int length) {
    static char new[100]; 
    int in;
    new[0] = arr[0];
    int element = 1;
    for (int i = 0;i < length;i++) {
        in = 1;
        for (int j = 0;j <= element-1;j++) {
            if (new[j] == arr[i]) {
                in = 0;
                break;
            }
        }
        if (in == 1) {
            new[element] = arr[i];
            element++;
        }

    }

    return new;
}

int length(char arr[]) {
    int count = 0;

    while (!NULL) {
        if (arr[count] == '\0') {
            break;
        }
        count += 1;
    }

    return (count);
}


int main() {
    char arr[100];
    
    printf("Masukkan pesan: ");
    scanf("%s", &arr);

    int arrlength = length(arr);
    char* arrclear = unique(arr,arrlength); 

    int arrclearlength = length(arrclear);

    int num[100];
    for (int i = 0;i < arrclearlength;i++) {
        int count = 0;
        for (int j = 0;j < arrlength;j++) {
            if (arrclear[i] == arr[j]) {
                count += 1;
            }
        }
        num[i] = count;
    }

    printf("Karakter yang tidak berulang: ");
    for (int i = 0;i < arrclearlength;i++) {
        if (num[i] == 1) {
            printf("%c ", arrclear[i]);
        }
    }
}