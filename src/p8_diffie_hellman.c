#include <stdio.h>

int power_mod(int b, int e, int m) {
    int i, result;

    result = 1;
    for (i = 0; i < e; i++)
        result = (result * b) % m;
    return result;
}

int main() {
    int p, g, a, b, A, B, s_a, s_b;

    p = 23;
    g = 5;
    printf("Let modulus p = %d and base g = %d\n", p, g);

    printf("\n--- Alice ---\n");
    a = 5;
    A = power_mod(g, a, p);
    printf("Secret key is %d\n", a);
    printf("Public key is %d\n", A);

    printf("\n--- Bob ---\n");
    b = 3;
    B = power_mod(g, b, p);
    printf("Secret key is %d\n", b);
    printf("Public key is %d\n", B);

    printf("\nShared secret as calculated by\n");
    s_a = power_mod(B, a, p);
    printf("Alice = %d\n", s_a);
    s_b = power_mod(A, b, p);
    printf("Bob = %d\n", s_b);

    return 0;
}