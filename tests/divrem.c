#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <owomath.h>

extern long long __divmodsi4(long long a, long long b, long long *rem);

int main(int argc, const char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <num1> <num2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (!isvalidnum(argv[1])) {
    puts("first arguement is invalid");
    return EXIT_FAILURE;
  }
  if (!isvalidnum(argv[2])) {
    puts("second arguement is invalid");
    return EXIT_FAILURE;
  }
  long long a = atoll(argv[1]);
  long long b = atoll(argv[2]);
  long long ac = a;
  long long bc = b;

  if (b == 0) {
    puts("cannot divide by zero");
    return EXIT_FAILURE;
  }

  long long rem;
  long long quotent = __divmodsi4(a, b, &rem);

  printf("%lld / %lld = %lld", ac, bc, quotent);
  if (rem > 0)
    printf(" R%lld", rem);
  putchar('\n');
  return EXIT_SUCCESS;
}
