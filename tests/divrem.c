#include <stdbool.h>
#include <stdio.h>
#undef __DARWIN_NO_LONG_LONG
#include <stdlib.h>

#include <uniqmath.h>

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

  struct divresult result = divrem(a, b);

  printf("%lld / %lld = %lld", ac, bc, result.quot);
  if (result.rem > 0)
    printf(" R%lld", result.rem);
  putchar('\n');
  return EXIT_SUCCESS;
}
