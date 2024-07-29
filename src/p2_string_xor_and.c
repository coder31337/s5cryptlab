#include <stdio.h>
#include <string.h>

int main() {
    char string[] = "Hello World";
    int len = strlen(string);
    char xor_string[len], and_string[len];
    int i;

    for (i = 0; i < len; i++) {
        and_string[i] = string[i] & 127;
        xor_string[i] = string[i] ^ 127;
    }
    for (i = 0; i < len; i++)
        printf("%c", and_string[i]);
    printf("\n");
    for (i = 0; i < len; i++)
        printf("%c", xor_string[i]);
    printf("\n");

    return 0;
}
