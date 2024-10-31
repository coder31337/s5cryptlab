#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int power_mod(int b, int e, int m) {
    int i, result = 1;
    for (i = 0; i < e; i++)
        result = (result * b) % m;
    return result;
}

int is_prime(int n) {
    int i;
    if (n <= 1)
        return 0;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int get_primitive_root(int p) {
    int g, is_primitive, i;
    for (g = 2; g < p; g++) {
        is_primitive = 1;
        for (i = 1; i < p - 1; i++) {
            if (power_mod(g, i, p) == 1) {
                is_primitive = 0;
                break;
            }
        }
        if (is_primitive)
            return g;
    }
    return -1;
}

int main() {
    int p, g, a, b, A, B, s_a, s_b;

    printf("Enter a prime modulus p: ");
    scanf("%d", &p);
    if (!is_prime(p)) {
        printf("Error! Invalid prime number\n");
        return 1;
    }

    g = get_primitive_root(p);
    if (g == -1) {
        printf("Error! Could not find a primitive root for p\n");
        return 1;
    }
    printf("Using base g = %d\n", g);

    srand(time(NULL));

    printf("\n--- Alice ---\n");
    a = rand() % (p - 2) + 1;
    A = power_mod(g, a, p);
    printf("Secret key is %d\n", a);
    printf("Public key is %d\n", A);

    printf("\n--- Bob ---\n");
    b = rand() % (p - 2) + 1;
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
