#include <stdio.h>
#include <math.h>

typedef struct {
   double real;
   double imag;
} complex_t;

complex_t c_add(complex_t a, complex_t b)
{
  complex_t sum;
  sum.real = a.real + b.real;
  sum.imag = a.imag + b.imag;
  return sum;
}
complex_t c_sub(complex_t a, complex_t b)
{
  complex_t diff;
  diff.real = a.real - b.real;
  diff.imag = a.imag - b.imag;
  return diff;
}
complex_t c_mul(complex_t a, complex_t b)
{
  //(a + i * b) * (c + i * d) = (a * c - b * d) + (b * c + a * d) * i
  complex_t product;
  product.real = a.real * b.real - a.imag * b.imag;
  product.imag = a.imag * b.real + a.real * b.imag;
  return product;
}
complex_t c_div(complex_t a, complex_t b)
{
  //(a + i * b) / (c + i * d) = (a * c + b * d)/(c^2 + d^2) + (b * c - a * d)/(c^2 + d^2) * i
  complex_t quotient;
  quotient.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
  quotient.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
  return quotient;
}
double c_abs(complex_t x)
{
  double abs;
  abs = sqrt(x.real * x.real + x.imag * x.imag);
  return abs;
}
complex_t c_conjugate(complex_t x)
{
  complex_t conjugate;
  conjugate.real = x.real;
  conjugate.imag = -x.imag;
  return conjugate;
}

double c_real(complex_t x)
{
  return x.real;
}
double c_imag(complex_t x)
{
  return x.imag;
}
complex_t c_exp(complex_t x)
{
  //e^(a + i * b) = e^a * e^(i * b) where Euler's formula e^(i * b) = cos(b) + i * sin(b)
  //therefore, e^(a + i * b) =  e^a * cos(b) + e^a * i * sin(b)
  complex_t exponent;
  exponent.real = exp(x.real) * cos(x.imag);
  exponent.imag = exp(x.real) * sin(x.imag);
  return exponent;
}

int main(void)
{

  return 0;
}