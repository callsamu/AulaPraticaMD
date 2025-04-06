#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *generate_sieve(int n, int *size) {
	int *sieve = malloc(n * sizeof(int));
	memset(sieve, 1, n * sizeof(int));

	int i = 2;
	int prime_count = 1;
	sieve[0] = i;

	while (i < n) {
		for (int j = i; j < n; j += i) {
			sieve[j] = 0;
		}

		while (i < n && sieve[i] == 0) {
			i++;
		}

		if (i < n) {
			sieve[prime_count] = i;
			prime_count++;
		}
	}

	*size = prime_count;
	return sieve;
}

int test_prime(int p) {
    for (int d = 2; d * d <= p; d++) {
        if (p % d == 0) return 0;
    }
    
    return 1;
}


int main() {
	int n;
	scanf("%d", &n);

	printf("\nVerificando se %d é primo...\n", n);

	if (test_prime(n)) {
		printf("%d is prime.\n\n", n);
		return 0;
	}
	printf("> %d não é primo, então pode ser fatorizado.\n\n", n);

	printf("Gerando uma lista de primos até %d...\n", n);
	printf("> Feito. Encontrando quais dividem %d...\n\n", n);
	int primes;
	int *sieve = generate_sieve(n, &primes);

	printf("%d = ", n);

	int i = 0;

	while (n > 1 && i < primes) {
		int p = sieve[i];

		while (n % p == 0) {
			if (n == p) {
				printf("%d\n", p);
			} else {
				printf("%d * ", p);
			}

			n /= p;
		}

		i++;
	}

	free(sieve);

	return 0;
}
