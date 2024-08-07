#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 100

int main() {
    char message[BUF], plaintext[BUF], ciphertext[BUF], key[BUF];
    int len, i, pi, ki, ci;

    printf("Enter a message: ");
    fgets(message, BUF, stdin);

    len = 0;
    for (i = 0; i < strlen(message) - 1; i++) {
        if (isalpha(message[i]))
            plaintext[len++] = (char)toupper(message[i]);
    }
    plaintext[len] = '\0';

    srand(time(NULL));
    for (i = 0; i < len; i++) {
        pi = plaintext[i] - 'A';
        ki = rand() % 26;
        ci = pi ^ ki;
        if (ci > 25) ci -= 26;
        ciphertext[i] = (char)ci + 'A';
        key[i] = (char)ki + 'A';
    }
    ciphertext[len] = '\0';
    key[len] = '\0';

    printf("Ciphertext is %s\n", ciphertext);
    printf("Key is %s\n", key);
    return 0;
}
