#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUF 100

int main() {
    char message[BUF], plaintext[BUF], ciphertext[BUF];
    int key, len, i, pi, ci;

    printf("Enter a message: ");
    fgets(message, BUF, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    len = 0;
    for (i = 0; i < strlen(message) - 1; i++) {
        if (isalpha(message[i]))
            plaintext[len++] = (char)toupper(message[i]);
    }
    plaintext[len] = '\0';

    for (i = 0; i < len; i++) {
        pi = plaintext[i] - 'A';
        ci = (pi + key) % 26;
        ciphertext[i] = (char)ci + 'A';
    }
    ciphertext[len] = '\0';

    printf("Ciphertext is %s\n", ciphertext);
    return 0;
}
