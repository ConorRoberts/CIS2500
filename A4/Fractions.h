#ifndef _FRACTIONS_
#define _FRACTIONS_

#define FALSE 0
#define TRUE 1

#define SIMPLE 0
#define MIXED 1

typedef struct{
  long long num;
  long long denom;
}Fraction;

int set_fraction(Fraction *, long long, long long);

void print_fract (Fraction *, int);

void simplify(Fraction *);

int add_fract(Fraction *, Fraction *, Fraction *);

#endif
