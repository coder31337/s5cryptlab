#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "hello world";
    int len = strlen(string);
    char xor_string[len];
    int i;

    for (i = 0; i < len; i++)
        xor_string[i] = string[i] ^ 0;
    for (i = 0; i < len; i++)
        printf("%c", xor_string[i]);
    printf("\n");

    return 0;
}
