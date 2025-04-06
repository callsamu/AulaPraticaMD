#include <stdio.h>
static inline int test_prime(int p) {
    for (int d = 2; d * d <= p; d++) {
        if (p % d == 0) return 0;
    }
    
    return 1;
}

int main() {
	int n;

	puts("Digite um número para verificar se é primo: ");
	scanf("%d", &n);

	if (test_prime(n))
		printf("%d é primo\n", n);
	else
		printf("%d não é primo\n", n);
	return 0;
}
