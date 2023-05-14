#include <stdio.h>

int power(int base, int exponent)
{
  if(base == 0)
    return 0;
  if(exponent == 0)
    return 1;
  if(exponent % 2 == 0)
    return power(base * base, exponent/2);
  return base * power(base * base, (exponent-1)/2);
}

int main (void)
{
  printf("Power - %d\n", power(2, 0));
  return 0;
}