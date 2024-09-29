#include <stdio.h>

unsigned long long power(int x, int y) {
    if (y == 0)
        return 1;
    return x * power(x, y - 1);
}

int main() {
    int p, g, a, b, A, B, s_a, s_b;

    p = 23;
    g = 5;
    printf("Let modulus p = %d and base g = %d\n", p, g);

    printf("\n--- Alice ---\n");
    a = 5;
    A = power(g, a) % p;
    printf("Secret key is %d\n", a);
    printf("Public key is %d\n", A);

    printf("\n--- Bob ---\n");
    b = 3;
    B = power(g, b) % p;
    printf("Secret key is %d\n", b);
    printf("Public key is %d\n", B);

    printf("\nShared secret as calculated by\n");
    s_a = power(B, a) % p;
    printf("Alice = %d\n", s_a);
    s_b = power(A, b) % p;
    printf("Bob = %d\n", s_b);

    return 0;
}