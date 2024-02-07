#include <stdio.h>
#include <stdlib.h>

long long divrem(long long dividend, long long divisor, long long *rem) {
    if (divisor == 0) {
        puts("Cannot divide by zero");
        return EXIT_FAILURE;
    }
    long long quotient = dividend / divisor;
    *rem = dividend % divisor;
    return quotient;
}
