#include <stdbool.h>
#include <stdio.h>
#undef __DARWIN_NO_LONG_LONG
#include <stdlib.h>
#include <string.h>

#include <uniqmath.h>

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

  struct fraction f1 = {atoll(arg1), atoll(ptr1 + 1)};
  struct fraction f2 = {atoll(arg2), atoll(ptr2 + 1)};
  char operation = argv[2][0];
  switch (operation) {
  case '+':
    printfraction(fracadd(f1, f2));
    break;
  case '-':
    printfraction(fracsub(f1, f2));
    break;
  case '*':
    printfraction(fracmul(f1, f2));
    break;
  case '/':
    printfraction(fracdiv(f1, f2));
    break;
  case '>':
    if (argv[2][1] == '=')
      printf("%s\n", fracge(f1, f2) ? "true" : "false");
    else
      printf("%s\n", fracgt(f1, f2) ? "true" : "false");
    break;
  case '<':
    if (argv[2][1] == '=')
      printf("%s\n", fracle(f1, f2) ? "true" : "false");
    else
      printf("%s\n", fraclt(f1, f2) ? "true" : "false");
    break;
  case '=':
    printf("%s\n", fraceq(f1, f2) ? "true" : "false");
    break;
  default:
    printf("Invalid operation: %c\n", operation);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
