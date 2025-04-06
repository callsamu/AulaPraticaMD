#include <stdio.h>

int extended_gcd(int a, int b, int *s, int *t) {
	int x0 = 1;
	int y0 = 0;

	int x1 = 0;
	int y1 = 1;

	putchar('\n');

	while (b > 0) {
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
		printf("%da + %db\n", x1, y1);
	}

	*s = x0;
	*t = y0;

	return a;
}

int main() {
	puts("Insira dois inteiros: ");
	int a, b;
	scanf("%d %d", &a, &b);

	int s, t;
	extended_gcd(a, b, &s, &t);

	putchar('\n');

	if (t < 0) {
		printf("MDC(%d, %d) = %da - %db\n", a, b, s, -t);
	} else {
		printf("MDC(%d, %d) = %da + %db\n", a, b, s, t);
	}

	return 0;
}
