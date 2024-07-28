#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "hello world";
    int len = strlen(string);
    char xor_string[len];

    for (int i = 0; i < len; i++)
        xor_string[i] = string[i] ^ 'o';
    for (int i = 0; i < len; i++)
        printf("%d ", xor_string[i]);
    printf("\n");

    return 0;
}
