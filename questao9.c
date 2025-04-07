#include <stdio.h>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int extended_gcd(int a, int b, int *s, int *t) {
	int x0 = 1;
	int y0 = 0;

	int x1 = 0;
	int y1 = 1;

	putchar('\n');

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

int main() {
	int a1, a2, a3;
	int m1, m2, m3;

	puts("Insira os valores de a e m para as três congruências:");
	scanf("%d %d", &a1, &m1);
	scanf("%d %d", &a2, &m2);
	scanf("%d %d", &a3, &m3);

	int modulus_gcd = gcd(gcd(m1, m2), m3);
	if (modulus_gcd != 1) {
		printf("Os módulos %d, %d e %d não são coprimos\n", m1, m2, m3);
		return 1;
	}

	int M = m1 * m2 * m3;
	int b1 = M / m1;
	int b1_ = modular_inverse(b1, m1);

	int b2 = M / m2;
	int b2_ = modular_inverse(b2, m2);

	int b3 = M / m3;
	int b3_ = modular_inverse(b3, m3);

	int x = (a1 * b1 * b1_ + a2 * b2 * b2_ + a3 * b3 * b3_) % M;

	puts("Se...");

	printf("x _= %d mod %d\n", a1, m1);
	printf("x _= %d mod %d\n", a2, m2);
	printf("x _= %d mod %d\n", a3, m3);

	puts("\nEntão...");
	printf("x _= %d mod %d\n", x, M);

}
