#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUF 100

int main() {
    char message[BUF], ciphertext[BUF];
    int key, len, i, pi, ci;

    printf("Enter a message: ");
    fgets(message, BUF, stdin);
    message[strlen(message) - 1] = '\0';
    len = strlen(message);

    printf("Enter a key: ");
    scanf("%d", &key);

    for (i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            pi = toupper(message[i]) - 'A';
            ci = (pi + key) % 26;
            ciphertext[i] = (char)ci + 'A';
        } else {
            ciphertext[i] = message[i];
        }
    }
    ciphertext[len] = '\0';
    printf("Ciphertext is %s\n", ciphertext);

    return 0;
}
