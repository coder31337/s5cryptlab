#include <ctype.h>
#include <stdio.h>

#define BUF 100

int main() {
    char key_string[BUF], message[BUF], ki;
    int key[3][3], pvector[3], cvector[3];
    int i, j, k;

    printf("Enter the key (9 chars): ");
    fgets(key_string, BUF, stdin);
    k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            key[i][j] = toupper(key_string[k++]) - 'A';
        }
    }

    printf("Enter the message (3 chars): ");
    fgets(message, BUF, stdin);
    for (i = 0; i < 3; i++)
        pvector[i] = toupper(message[i]) - 'A';

    for (i = 0; i < 3; i++) {
        cvector[i] = 0;
        for (k = 0; k < 3; k++)
            cvector[i] += key[i][k] * pvector[k];
        cvector[i] %= 26;
    }

    printf("Ciphertext is ");
    for (i = 0; i < 3; i++)
        printf("%c", (char)cvector[i] + 'A');
    printf("\n");

    return 0;
}
