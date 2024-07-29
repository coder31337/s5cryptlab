#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUF 100

int mod(int x, int y) {
    return (x % y + y) % y;
}

int main() {
    char alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
    char plain[BUF], cipher[BUF];
    int positions[BUF];
    int key, len, i, j;

    printf("Enter a string: ");
    scanf("%[^\n]s", plain);
    printf("Enter a key: ");
    scanf("%d", &key);

    len = strlen(plain);
    for (i = 0; i < len; i++) {
        positions[i] = 26;
        for (j = 0; j < 26; j++) {
            if (toupper(plain[i]) == alphabets[j]) {
                positions[i] = mod(j + key, 26);
                break;
            }
        }
    }
    for (i = 0; i < len; i++) {
        cipher[i] = alphabets[positions[i]];
    }
    cipher[len] = '\0';

    printf("Cipher is %s\n", cipher);
    return 0;
}
