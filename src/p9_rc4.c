#include <stdio.h>
#include <string.h>

#define BUF 100

void swap(unsigned char *a, unsigned char *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int KSA(char *key, unsigned char *S) {
    int i, j, len;

    for (i = 0; i < 256; i++)
        S[i] = i;
    
    j = 0;
    len = strlen(key);
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % len]) % 256;
        swap(&S[i], &S[j]);
    }
    return 0;
}

void PRGA(unsigned char *S, char *input, unsigned char *output) {
    int n, i, j, len;
    unsigned char rand_byte;

    i = 0;
    j = 0;
    len = strlen(input);
    for (n = 0; n < len; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        swap(&S[i], &S[j]);
        rand_byte = S[(S[i] + S[j]) % 256];

        output[n] = rand_byte ^ input[n];
    }
    output[len] = '\0';
}


int main() {
    char key[BUF], message[BUF], plaintext[BUF];
    unsigned char S[256], ciphertext[BUF];
    int i;

    printf("Enter key: ");
    fgets(key, BUF, stdin);
    key[strlen(key) - 1] = '\0';
    
    printf("Enter message: ");
    fgets(message, BUF, stdin);
    message[strlen(message) - 1] = '\0';

    KSA(key, S);
    PRGA(S, message, ciphertext);
    printf("After encryption\n");
    printf("Ciphertext is ");
    for (i = 0; i < strlen(message); i++)
        printf("%x", ciphertext[i]);
    printf("\n");

    KSA(key, S);
    PRGA(S, ciphertext, plaintext);
    printf("After decryption\n");
    printf("Plaintext is %s\n", plaintext);

    return 0;
}
