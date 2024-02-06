#ifndef _OWOMATH_H_
#define _OWOMATH_H_

#include <stdbool.h>

struct fraction {
  long long num, den;
};

extern bool isvalidnum(const char *str);

extern struct fraction fracadd(struct fraction a, struct fraction b);
extern struct fraction fracsub(struct fraction a, struct fraction b);
extern struct fraction fracmul(struct fraction a, struct fraction b);
extern struct fraction fracdiv(struct fraction a, struct fraction b);

extern void printfraction(struct fraction a);

#endif
