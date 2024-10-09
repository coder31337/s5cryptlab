#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gcd(int a, int b) {
	int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int modular_exponentiation(int b, int e, int m) {
    int result = 1;
	b = b % m;
    while (e > 0) {
        if (e % 2 == 1)
            result = (result * b) % m;
        b = (b * b) % m;
        e /= 2;
    }
    return result;
}

int main() {
    int p, q, n, phi_n, e, i, d, m, ci, pi;

    printf("Enter prime number p: ");
    scanf("%d", &p);
    printf("Enter prime number q: ");
    scanf("%d", &q);

    n = p * q;
    phi_n = (p - 1) * (q - 1);

    srand(time(NULL));
    while (1) {
        e = rand() % (phi_n - 1) + 2;
        if (gcd(e, phi_n) == 1)
			break;
    }
    
	for (i = 1; i <= phi_n; i++) {
        if ((e * i) % phi_n == 1)
			d = i;
    }

    printf("n = %d\n", n);
    printf("e = %d\n", e);
    printf("d = %d\n", d);

    printf("Enter message (< %d): ", n);
    scanf("%d", &m);

    printf("After encryption\n");
    ci = modular_exponentiation(m, e, n);
    printf("Ciphertext is %d\n", ci);

    printf("After decryption\n");
    pi = modular_exponentiation(ci, d, n);
    printf("Plaintext is %d\n", pi);

    return 0;
}
