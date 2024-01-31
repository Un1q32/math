#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
	if (argc < 3) {
		printf("Usage: %s <num1> <num2>\n", argv[0]);
		return EXIT_FAILURE;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int ac = a;
	int bc = b;

	if (b == 0) {
		puts("cannot divide by zero");
		return EXIT_FAILURE;
	}

	int quotent = 0;
	while (a >= b) {
		a -= b;
		quotent++;
	}

	printf("%d / %d = %d", ac, bc, quotent);
	if (a > 0)
		printf(" R%d", a);
	putchar('\n');
	return EXIT_SUCCESS;
}
