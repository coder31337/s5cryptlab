#include <stdio.h>
#include <string.h>

#define BUF 100

void swap(unsigned char *a, unsigned char *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void KSA(char *key, unsigned char *S) {
    int i, j, len;

    for (i = 0; i < 256; i++)
        S[i] = i;
    
    j = 0;
    len = strlen(key);
    for (i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % len]) % 256;
        swap(&S[i], &S[j]);
    }
}

void PRGA(unsigned char *S, unsigned char *input, unsigned char *output) {
    int n, i, j, len;
    unsigned char r;

    i = 0;
    j = 0;
    len = strlen(input);
    for (n = 0; n < len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        swap(&S[i], &S[j]);
        r = S[(S[i] + S[j]) % 256];

        output[n] = r ^ input[n];
    }
    output[len] = '\0';
}


int main() {
    char key[BUF], message[BUF], plaintext[BUF];
    unsigned char S[256], ciphertext[BUF];
    int i, len;

    printf("Enter key: ");
    fgets(key, BUF, stdin);
    key[strlen(key) - 1] = '\0';
    
    printf("Enter message: ");
    fgets(message, BUF, stdin);
    message[strlen(message) - 1] = '\0';
    len = strlen(message);

    KSA(key, S);
    PRGA(S, message, ciphertext);
    printf("\nAfter encryption\n");
    printf("Ciphertext is ");
    for (i = 0; i < len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    KSA(key, S);
    PRGA(S, ciphertext, plaintext);
    printf("\nAfter decryption\n");
    printf("Plaintext is %s\n", plaintext);

    return 0;
}
