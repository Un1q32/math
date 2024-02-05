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
    return 1;
  }

  if (!isvalidnum(argv[1])) {
    printf("Invalid number: %s\n", argv[1]);
    return 1;
  }

  int n = atoi(argv[1]);
  int fib[n];
  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i < n; i++)
    fib[i] = fib[i - 1] + fib[i - 2];
  printf("fib(%d) = %d\n", n, fib[n - 1]);
  return 0;
}
