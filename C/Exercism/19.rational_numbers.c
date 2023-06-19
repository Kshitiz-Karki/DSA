#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef struct {
   int numerator;
   int denominator;
} rational_t;

int gcd(int x, int y)
{
  while(x > 0 && y > 0)
  {
    if(x>y) x=x%y; else y=y%x;
  }
  if(x==0) return y;
  return x;
}

rational_t reduce(rational_t r)
{
  int divisor = gcd ( abs(r.numerator), abs(r.denominator) );
  r.numerator = r.numerator/divisor;
  r.denominator = r.denominator/divisor;
  r.numerator = r.denominator < 0 ? -1 * r.numerator : r.numerator;
  r.denominator = r.denominator < 0 ? -1 * r.denominator : r.denominator;
  return r;
}

rational_t add(rational_t x, rational_t y)
{
  rational_t sum;
  sum.numerator = x.numerator * y.denominator + y.numerator * x.denominator;
  sum.denominator = x.denominator * y.denominator;
  rational_t result = reduce(sum);
  return result;
}

rational_t subtract(rational_t x, rational_t y)
{
  rational_t diff;
  diff.numerator = x.numerator * y.denominator - y.numerator * x.denominator;
  diff.denominator = x.denominator * y.denominator;
  rational_t result = reduce(diff);
  return result;
}

rational_t multiply(rational_t x, rational_t y)
{
  rational_t product;
  product.numerator = x.numerator * y.numerator;
  product.denominator = x.denominator * y.denominator;
  rational_t result = reduce(product);
  return result;
}

rational_t divide(rational_t x, rational_t y)
{
  rational_t quotient;
  quotient.numerator = x.numerator * y.denominator;
  quotient.denominator = y.numerator * x.denominator;
  rational_t result = reduce(quotient);
  return result;
}

rational_t absolute(rational_t x)
{
  rational_t absolute;
  int numerator = abs(x.numerator);
  int denominator = abs(x.denominator);
  
  int divisor = gcd ( abs(numerator), abs(denominator) );
  absolute.numerator = numerator/divisor;
  absolute.denominator = denominator/divisor;

  return absolute;
}

rational_t exp_rational(rational_t x, int n)
{
  rational_t exp;
  int temp;

  int numerator = pow(x.numerator, abs(n));
  int denominator = pow(x.denominator, abs(n));

  int divisor = gcd ( abs(numerator), abs(denominator) );
  exp.numerator = numerator/divisor;
  exp.denominator = denominator/divisor;
  
  if(n < 0)
  {
    temp = exp.numerator;
    exp.numerator = exp.denominator;
    exp.denominator = temp;
  }
  
  exp.numerator = exp.denominator < 0 ? -1 * exp.numerator : exp.numerator;
  exp.denominator = exp.denominator < 0 ? -1 * exp.denominator : exp.denominator;
  return exp;
}

float exp_real(uint16_t x, rational_t r)
{
  float quo =  (float)r.numerator/ r.denominator;
  float y = pow(x, quo);
  return y;
}

int main(void)
{
  rational_t r1 = { -3, 5 };
  rational_t r2 = { -1, 2 };
  rational_t sum = add(r1, r2);
  rational_t diff = subtract(r1, r2);
  rational_t product = multiply(r1, r2);
  rational_t quo = divide(r1, r2);
  rational_t abs = absolute(r1);
  rational_t exp = exp_rational(r1, -3 );
  float real = exp_real(9, r1);
  rational_t x = reduce(r1);
  printf("Add - {%d, %d}\n", sum.numerator, sum.denominator);
  printf("Subtract - {%d, %d}\n", diff.numerator, diff.denominator);
  printf("Multiply - {%d, %d}\n", product.numerator, product.denominator);
  printf("Divide - {%d, %d}\n", quo.numerator, quo.denominator);
  printf("Absolute - {%d, %d}\n", abs.numerator, abs.denominator);
  printf("Exponential  - {%d, %d}\n", exp.numerator, exp.denominator);
  printf("Exp real  - %0.1f\n", real);
  printf("Reduce  - {%d, %d}\n", x.numerator, x.denominator);
  return 0;
}