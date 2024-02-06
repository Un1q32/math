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

void fracadd(long long num1, long long den1, long long num2, long long den2) {
  long long num = num1 * den2 + num2 * den1;
  long long den = den1 * den2;
  long long gcd = 1;
  for (long long i = 1; i <= num && i <= den; i++)
    if (num % i == 0 && den % i == 0)
      gcd = i;
  num /= gcd;
  den /= gcd;
  if (num < den)
    printf("%lld/%lld\n", num, den);
  else {
    long long oldnum = num;
    long long oldden = den;
    long long whole = num / den;
    num %= den;
    if (num)
      printf("%lld %lld/%lld\n", whole, num, den);
    else
      printf("%lld\n", whole);
    printf("Improper fraction: %lld/%lld\n", oldnum, oldden);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <fraction 1> <operation> <fraction 2>\n", argv[0]);
    return EXIT_FAILURE;
  }
  char arg1[strlen(argv[1]) + 1];
  char arg2[strlen(argv[3]) + 1];
  strcpy(arg1, argv[1]);
  strcpy(arg2, argv[3]);
  char *ptr1 = strchr(arg1, '/');
  char *ptr2 = strchr(arg2, '/');
  if (ptr1 == NULL) {
    printf("Invalid fraction: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (ptr2 == NULL) {
    printf("Invalid fraction: %s\n", argv[3]);
    return EXIT_FAILURE;
  }
  *ptr1 = '\0';
  *ptr2 = '\0';
  if (!isvalidnum(arg1) || !isvalidnum(ptr1 + 1)) {
    printf("Invalid fraction: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (!isvalidnum(arg2) || !isvalidnum(ptr2 + 1)) {
    printf("Invalid fraction: %s\n", argv[3]);
    return EXIT_FAILURE;
  }

  long long num1 = atoll(arg1);
  long long den1 = atoll(ptr1 + 1);
  long long num2 = atoll(arg2);
  long long den2 = atoll(ptr2 + 1);
  char operation = argv[2][0];
  switch (operation) {
  case '+':
    fracadd(num1, den1, num2, den2);
    break;
  case '-':
    // fracsub(num1, den1, num2, den2);
    // break;
  case '*':
    // fracmul(num1, den1, num2, den2);
    // break;
  case '/':
    // fracdiv(num1, den1, num2, den2);
    // break;
  default:
    printf("Invalid operation: %c\n", operation);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
