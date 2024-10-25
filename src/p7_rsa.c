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

int power_mod(int b, int e, int m) {
    int i, result;

    result = 1;
    for (i = 0; i < e; i++)
        result = (result * b) % m;
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
    ci = power_mod(m, e, n);
    printf("Ciphertext is %d\n", ci);

    printf("After decryption\n");
    pi = power_mod(ci, d, n);
    printf("Plaintext is %d\n", pi);

    return 0;
}
