#include <ctype.h>
#include <stdio.h>
#include <string.h>
#define BUF 100

int main() {
    char input_string[BUF], plaintext[BUF], ciphertext[BUF];
    int key, len, i;

    printf("Enter a string: ");
    fgets(input_string, BUF, stdin);
    printf("Enter a key: ");
    scanf("%d", &key);

    len = 0;
    for (i = 0; i < strlen(input_string) - 1; i++) {
        if (isalpha(input_string[i]))
            plaintext[len++] = (char)toupper(input_string[i]);
    }
    plaintext[len] = '\0';

    for (i = 0; i < len; i++)
        ciphertext[i] = (char)((plaintext[i] - 'A' + key) % 26) + 'A';
    ciphertext[len] = '\0';

    printf("Cipher is %s\n", ciphertext);
    return 0;
}
