#include <stdio.h>

int extended_gcd(int a, int b, int *s, int *t) {
	int x0 = 1;
	int y0 = 0;

	int x1 = 0;
	int y1 = 1;

	putchar('\n');

	while (b != 0) {
		printf("%d | %d\n", a, b);

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

int main() {
	puts("Insira dois inteiros coprimos: ");

	int a, b;
	scanf("%d %d", &a, &b);

	int s, t;
	int mdc = extended_gcd(a, b, &s, &t);

	printf("MDC(%d, %d) = %d.\n", a, b, mdc);

	if (mdc != 1) {
		printf("Os inteiros %d e %d não são coprimos, logo, não há inverso modular.\n", a, b);
		return 0;
	}

	putchar('\n');

	s = (b + s) % b;

	printf("%d * %d é congruente a 1 módulo %d\n", s, a, b);
	printf("Assim, a solução é %d.\n", s);


	return 0;
}
