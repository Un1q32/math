#include <stdbool.h>
#include <stdio.h>
#undef __DARWIN_NO_LONG_LONG
#include <stdlib.h>

#include <owomath.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <number>\n", argv[0]);
    return EXIT_FAILURE;
  }

  if (!isvalidnum(argv[1])) {
    printf("Invalid number: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  unsigned long long n = atoll(argv[1]);
  unsigned long long fib[2] = {0, 1};
  unsigned long long i;
  for (i = 2; i < n; i++) {
    unsigned long long tmp = fib[1];
    fib[1] = fib[0] + fib[1];
    fib[0] = tmp;
  }
  printf("fib(%llu) = %llu\n", n, fib[1]);
  return EXIT_SUCCESS;
}
