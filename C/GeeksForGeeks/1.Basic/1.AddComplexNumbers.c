#include <stdio.h>

typedef struct complexNumbers
  {
    int real;
    int img;
  }complex;

complex add(complex a, complex b)
{
  complex s;
  s.real = a.real + b.real;
  s.img = a.img + b.img;
  return s;
}

int main (void)
{ 
  complex x;
  complex y;
  complex sum;

  printf("Enter 1st complex number (real part): ");
  scanf("%d", &x.real);

  printf("Enter 1st complex number (imaginary part): ");
  scanf("%d", &x.img);

  printf("Enter 2nd complex number (real part): ");
  scanf("%d", &y.real);

  printf("Enter 2nd complex number (imaginary part): ");
  scanf("%d", &y.img);

  sum = add(x, y);
  printf("Sum : %d + %di\n", sum.real, sum.img);
  
  return 0;
}