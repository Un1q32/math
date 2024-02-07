#include <stdio.h>
#include <stdlib.h>

#include <owomath.h>

struct divresult divrem(long long dividend, long long divisor) {
    struct divresult result;
    if (divisor == 0) {
        puts("Cannot divide by zero");
        exit(EXIT_FAILURE);
    }
    result.quot = dividend / divisor;
    result.rem = dividend % divisor;
    return result;
}
