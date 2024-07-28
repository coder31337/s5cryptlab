#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "hello world";
    int len = strlen(string);
    char xor_string[len];
    char and_string[len];

    for (int i = 0; i < len; i++) {
        xor_string[i] = string[i] ^ 127;
        and_string[i] = string[i] & 127;
    }
    printf("XOR - ");
    for (int i = 0; i < len; i++)
        printf("%d ", xor_string[i]);
    printf("\n");
    printf("AND - ");
    for (int i = 0; i < len; i++)
        printf("%d ", and_string[i]);
    printf("\n");

    return 0;
}
