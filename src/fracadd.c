#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  if (argc < 3) {
    printf("Usage: %s <fraction 1> <fraction 2>\n", argv[0]);
    return EXIT_FAILURE;
  }
  char arg1[strlen(argv[1]) + 1];
  char arg2[strlen(argv[2]) + 1];
  strcpy(arg1, argv[1]);
  strcpy(arg2, argv[2]);
  char *ptr1 = strchr(arg1, '/');
  char *ptr2 = strchr(arg2, '/');
  if (ptr1 == NULL || ptr2 == NULL) {
    printf("Invalid fraction format\n");
    return EXIT_FAILURE;
  }
  *ptr1 = '\0';
  *ptr2 = '\0';
  if (!isvalidnum(arg1) || !isvalidnum(ptr1 + 1)) {
    printf("Invalid fraction: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (!isvalidnum(arg2) || !isvalidnum(ptr2 + 1)) {
    printf("Invalid fraction: %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  long long num1 = atoll(arg1);
  long long den1 = atoll(ptr1 + 1);
  long long num2 = atoll(arg2);
  long long den2 = atoll(ptr2 + 1);
  long long num = num1 * den2 + num2 * den1;
  long long den = den1 * den2;
  long long gcd = 1;
  for (long long i = 1; i <= num && i <= den; i++)
    if (num % i == 0 && den % i == 0)
      gcd = i;
  num /= gcd;
  den /= gcd;
  printf("%lld/%lld\n", num, den);
  return EXIT_SUCCESS;
}
