#include <stdio.h>


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

int samealphabetcl(char arr1[], char arr2[]) {
    int same = 1;
    if (length(arr1) != length(arr2)) {
        same = 0;
    }
    else {
        for (int i = 0;i < length(arr1);i++) {
            for (int j = 0;j < length(arr2);j++) {
                if (arr1[i] == arr2[j]) {
                    break;
                }
                if ((j == length(arr2)-1) && (arr1[i] != arr2[j])) {
                    same = 0;
                    break;
                }
            }
            if (same == 0) {
                break;
            }
        }
    }

    return same;

}


int main() {
    char mess1[100];
    char mess2[100];

    printf("Masukkan pesan 1: ");
    scanf("%s", &mess1);
    printf("Masukkan pesan 2: ");
    scanf("%s", &mess2);   

    int num1[100];
    int num2[100];

    int length1 = length(mess1); 
    int length2 = length(mess2);

    char* mess1cl = unique(mess1, length1);
    char* mess2cl = unique(mess2, length2);

    int length1cl = length(mess1cl);
    int length2cl = length(mess2cl);



    for (int i = 0;i < (length1cl);i++) {
        int count = 0;
        for (int j = 0;j < (length(mess1));j++) {
            if (mess1cl[i] == mess1[j]) {
                count += 1;
            }
        }
        num1[i] = count;
    }

    for (int i = 0;i < (length2cl);i++) {
        int count = 0;
        for (int j = 0;j < (length(mess2));j++) {
            if (mess2cl[i] == mess2[j]) {
                count += 1;
            }
        }
        num2[i] = count;
    }

    int anagram = 1;
    
    if (length1cl != length2cl) {
        anagram = 0;
    }
    else if (samealphabetcl(mess1cl, mess2cl) == 0) {
        anagram = 0;
    }
    else if (samealphabetcl(mess1cl, mess2cl) == 1) {
        for (int i = 0;i < (length1cl);i++) {
            for (int j = 0;j < (length2cl);j++) {
                if ((mess1cl[i] == mess2cl[j]) && (num1[i] != num2[j])) {
                    anagram = 0;
                    break;
                }
            }
            if (anagram == 0) {
                break;
            }
        }
    }

    if (anagram == 1) {
        printf("Kedua string adalah anagram.");
    }
    else {
        printf("Kedua string bukan anagram.");
    }
}