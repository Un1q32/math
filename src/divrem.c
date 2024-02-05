#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern int __divmodsi4(int a, int b, int *rem);

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
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int ac = a;
  int bc = b;

  if (b == 0) {
    puts("cannot divide by zero");
    return EXIT_FAILURE;
  }

  int rem;
  int quotent = __divmodsi4(a, b, &rem);

  printf("%d / %d = %d", ac, bc, quotent);
  if (rem > 0)
    printf(" R%d", rem);
  putchar('\n');
  return EXIT_SUCCESS;
}
