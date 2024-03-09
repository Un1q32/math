#include <stdbool.h>
#include <stdio.h>

#include <uniqmath.h>

struct fraction fracadd(struct fraction f1, struct fraction f2) {
  struct fraction f;
  f.num = f1.num * f2.den + f2.num * f1.den;
  f.den = f1.den * f2.den;
  return f;
}

struct fraction fracsub(struct fraction f1, struct fraction f2) {
  struct fraction f;
  f.num = f1.num * f2.den - f2.num * f1.den;
  f.den = f1.den * f2.den;
  return f;
}

struct fraction fracmul(struct fraction f1, struct fraction f2) {
  struct fraction f;
  f.num = f1.num * f2.num;
  f.den = f1.den * f2.den;
  return f;
}

struct fraction fracdiv(struct fraction f1, struct fraction f2) {
  struct fraction f;
  f.num = f1.num * f2.den;
  f.den = f1.den * f2.num;
  return f;
}

bool fraceq(struct fraction f1, struct fraction f2) {
  return f1.num * f2.den == f2.num * f1.den;
}

bool fraclt(struct fraction f1, struct fraction f2) {
  return f1.num * f2.den < f2.num * f1.den;
}

bool fracgt(struct fraction f1, struct fraction f2) {
  return f1.num * f2.den > f2.num * f1.den;
}

bool fracle(struct fraction f1, struct fraction f2) {
  return f1.num * f2.den <= f2.num * f1.den;
}

bool fracge(struct fraction f1, struct fraction f2) {
  return f1.num * f2.den >= f2.num * f1.den;
}

void printfraction(struct fraction f) {
  long long gcd = 1;
  long long i;
  for (i = 1; i <= f.num && i <= f.den; i++)
    if (f.num % i == 0 && f.den % i == 0)
      gcd = i;
  f.num /= gcd;
  f.den /= gcd;
  if (f.num < f.den)
    printf("%lld/%lld\n", f.num, f.den);
  else {
    long long oldnum = f.num;
    long long oldden = f.den;
    long long whole = f.num / f.den;
    f.num %= f.den;
    if (f.num)
      printf("%lld %lld/%lld\n", whole, f.num, f.den);
    else
      printf("%lld\n", whole);
    printf("Improper fraction: %lld/%lld\n", oldnum, oldden);
  }
}
