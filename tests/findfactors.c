#include <stdio.h>
#undef __DARWIN_NO_LONG_LONG
#include <stdlib.h>

#include <uniqmath.h>

void findfactors(long long num) {
    long long i;
    for (i = 1; i <= num; i++)
        if (num % i == 0)
            printf("%lld ", i);
    putchar('\n');
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!isvalidnum(argv[1])) {
        printf("Invalid number: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    long long num = atoll(argv[1]);
    printf("Factors of %lld: ", num);
    findfactors(num);
    return EXIT_SUCCESS;
}
