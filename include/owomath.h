#ifndef _OWOMATH_H_
#define _OWOMATH_H_

#include <stdbool.h>

struct fraction {
  long long num, den;
};

struct divresult {
  long long quot, rem;
};

extern bool isvalidnum(const char *);

extern struct divresult divrem(long long, long long);

extern struct fraction fracadd(struct fraction, struct fraction);
extern struct fraction fracsub(struct fraction, struct fraction);
extern struct fraction fracmul(struct fraction, struct fraction);
extern struct fraction fracdiv(struct fraction, struct fraction);

extern void printfraction(struct fraction);

#endif
