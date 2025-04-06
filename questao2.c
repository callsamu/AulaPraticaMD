#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ll long long
#define ITERATIONS 50
#define FERMAT_START ITERATIONS * ITERATIONS

static inline int modular_exp(ll base, ll exp, ll mod) {
    ll i = exp;
    ll result = 1;
    
    while (i > 0) {
        if (i % 2 == 0) {
            base = (base * base) % mod;
            i >>= 1;
        } 
            
        result = (result * base) % mod;
        i--;
    }
    
    return result;
}

static inline int fermat(ll p) {
    if (p == 1) return 0;
    
    for (int i = 0; i < ITERATIONS; i++) {
        ll a = rand() % (p - 2) + 2;
        if (modular_exp(a, p - 1, p) != 1) {
            return 0;
        }
    }
    
    return 1;
}

static inline int test_prime(ll p) {
    for (ll d = 5; d * d <= p; d += 4) {
        if (p % d == 0 || p % (d + 2) == 0) return 0;
    }
    
    return 1;
}

void check_primes() {
    time_t start = time(NULL);
    
    ll i = 2;
    ll largest_prime = i;

	printf("PRIMO: %lld\n", i);

	i = 3;
	printf("PRIMO: %lld\n", i);

	i = 5;
	printf("PRIMO: %lld\n", i);
    
    while (time(NULL) - start < 60) {
        if (i >= FERMAT_START) {
            if (fermat(i)) {
				if (test_prime(i)) {
					printf("PRIMO: %lld\n", i);
					largest_prime = i;
				}
            }
        } else {
            if (test_prime(i)) {
				printf("PRIMO: %lld\n", i);
                largest_prime = i;
            }
        }
        
        i += 2;
    }
    
    
    printf("MAIOR PRIMO ENCONTRADO: %lld\n", largest_prime);
}

int main() {
    // int base, exp, mod;
    // scanf("%d %d %d", &base, &exp, &mod);
    check_primes();
}
