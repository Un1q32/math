#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isvalidnum(const char *str) {
  bool dot = false;
  switch (*str++) {
  case '-':
    if (!isdigit(*str))
      return false;
    break;
  case '+':
    if (!isdigit(*str))
      return false;
    break;
  case '.':
    if (!isdigit(*str))
      return false;
    dot = true;
    break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
    break;
  default:
    return false;
  }
  while (*str) {
    switch (*str++) {
    case '.':
      if (dot)
        return false;
      dot = true;
      break;
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      break;
    default:
      return false;
    }
  }
  return true;
}

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
  for (unsigned long long i = 2; i < n; i++) {
    unsigned long long tmp = fib[1];
    fib[1] = fib[0] + fib[1];
    fib[0] = tmp;
  }
  printf("fib(%llu) = %llu\n", n, fib[1]);
  return EXIT_SUCCESS;
}
