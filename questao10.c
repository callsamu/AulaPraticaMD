#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int extended_gcd(int a, int b, int *s, int *t) {
	int x0 = 1;
	int y0 = 0;

	int x1 = 0;
	int y1 = 1;

	while (b != 0) {
		int r = a % b;
		int q = (a - r) / b;

		int tmp_x1 = x1;
		int tmp_y1 = y1;

		x1 = x0 - q * x1;
		y1 = y0 - q * y1;

		x0 = tmp_x1;
		y0 = tmp_y1;

		a = b;
		b = r;
	}

	*s = x0;
	*t = y0;

	return a;
}

// Retorna -1 se a e m não forem coprimos,
// pois nesse caso não existe um inverso modular
int modular_inverse(int a, int m) {
	int s, t;

	int gcd = extended_gcd(a, m, &s, &t);

	if (gcd != 1) {
		return -1;
	}

	return (s + m) % m;
}

typedef struct Congruences {
	int *a;
	int *m;
	int size;
	int M;
} Congruences;

void read_congruences(Congruences *c) {
	c->M = 1;
	c->a = malloc(c->size * sizeof(int));
	c->m = malloc(c->size * sizeof(int));

	for (int i = 0; i < c->size; i++) {
		scanf("%d %d", &c->a[i], &c->m[i]);
		c->M *= c->m[i];
	}
}

int solve_congruences(Congruences *c) {
	if (c->size == 1) {
		int x = modular_inverse(c->a[0], c->m[0]);
		return x;
	}

	int x = 0;
	for (int i = 0; i < c->size; i++) {
		int b = c->M / c->m[i];
		int b_ = modular_inverse(b, c->m[i]);

		x += c->a[i] * b * b_;
	}

	return x % c->M;
}

int main() {
	int n;
	Congruences c;

	puts("Insira a quantidade de congruências: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("Quantidade de congruências inválida\n");
		return 1;
	}

	c.size = n;

	puts("Insira os valores de a e m para as congruências:");

	read_congruences(&c);

	int modulus_gcd = gcd(c.m[0], c.m[1]);
	for (int i = 2; i < c.size; i++) {
		modulus_gcd = gcd(modulus_gcd, c.m[i]);
	}

	if (modulus_gcd != 1) {
		printf("Os módulos não são todos coprimos\n");
		return 1;
	}


	int x = solve_congruences(&c);

	putchar('\n');
	for (int i = 0; i < c.size; i++) {
		printf("x _= %d (mod %d)\n", c.a[i], c.m[i]);
	}
	printf("\nSOLUÇÃO: x = %d (mod %d)\n", x, c.M);
}
