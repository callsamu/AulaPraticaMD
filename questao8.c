#include <stdio.h>

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

// Retorna -1 se não houver solução
int solve_congruence(int a, int b, int m) {
	int s, t;

	int gcd = extended_gcd(a, m, &s, &t);
	s = (s + m) % m;

	if (gcd == 1) {
		return (b * s) % m;
	} 

	if (b % gcd != 0) {
		return -1;
	}

	return solve_congruence(a / gcd, b / gcd, m / gcd);
}

int main() {
	puts("Insira três inteiros a, b e m: ");

	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);

	int solution = solve_congruence(a, b, m);

	printf("Se %dx é congruente a %d módulo %d...\n", a, b, m);

	if (solution < 0) {
		printf("Não existe solução para x.\n");
		return 0;
	}

	printf("Então x = %d .\n", solution);

	return 0;
}
