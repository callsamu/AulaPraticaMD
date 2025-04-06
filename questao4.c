#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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
	puts("Enter two integers A and B:");
	int a, b;
	scanf("%d %d", &a, &b);

	int copy_a = a;
	int copy_b = b;

	if (test_prime(a) && test_prime(b)) {
		printf("GCD(%d, %d) = %d\n", a, b, 1);
		printf("LCM(%d, %d) = %d\n", a, b, a * b);
		return 0;
	}

	int primes;
	int *sieve = generate_sieve(MAX(a, b), &primes);

	int i = 0;

	int gcd = 1;
	int lcm = 1;

	while ((a > 1 || b > 1) && i < primes) {
		int p = sieve[i];

		int a_factors = 0;
		int b_factors = 0;

		while (a % p == 0) {
			a /= p;
			a_factors++;
		}

		while (b % p == 0) {
			b /= p;
			b_factors++;
		}

		gcd *= pow(p, MIN(a_factors, b_factors));
		lcm *= pow(p, MAX(a_factors, b_factors));

		i++;
	}

	printf("\nMDC(%d, %d) = %d\n", copy_a, copy_b, gcd);
	printf("MMC(%d, %d) = %d\n", copy_a, copy_b, lcm);

	free(sieve);

	return 0;
}
