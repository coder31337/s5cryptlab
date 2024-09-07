#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define BUF 1000

int main() {
    int key[MAX_SIZE][MAX_SIZE], pvector[MAX_SIZE], cvector[MAX_SIZE];
    char key_string[BUF], message[BUF], plaintext[BUF], ciphertext[BUF], ki;
    int n, i, j, k, len, pad_len, c;

    printf("Enter the key matrix size: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the key (%d chars): ", n * n);
    fgets(key_string, BUF, stdin);
    k = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            key[i][j] = toupper(key_string[k++]) - 'A';
        }
    }

    printf("Enter message to encrypt: ");
    fgets(message, BUF, stdin);

    len = 0;
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i]))
            plaintext[len++] = toupper(message[i]);
    }
    if (len % n != 0) {
        pad_len = len % n;
        for (i = len; i < len + pad_len; i++)
            plaintext[i] = 'X';
        len += pad_len;
    }
    plaintext[len] = '\0';

    for (i = 0; i < len; i += n) {
        for (j = 0; j < n; j++)
            pvector[j] = plaintext[i + j] - 'A';

        for (j = 0; j < n; j++) {
            cvector[j] = 0;
            for (k = 0; k < n; k++)
                cvector[j] += key[j][k] * pvector[k];
            cvector[j] %= 26;
        }
        for (j = 0; j < n; j++)
            ciphertext[i + j] = (char)cvector[j] + 'A';
    }
    ciphertext[len] = '\0';

    printf("Ciphertext is %s\n", ciphertext);

    return 0;
}
