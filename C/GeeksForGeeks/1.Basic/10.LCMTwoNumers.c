#include <stdio.h>

int gcd(int a, int b)
{
  while(a > 0 && b > 0)
  {
    if(a > b)
      a = a % b;
    else
      b = b % a;
  }

  if(a == 0)
    return b;
  
  return a;
}

int main(void)
{
  int num1;
  int num2;

  printf("Enter 1st number: ");
  scanf("%d", &num1);

  printf("Enter 2nd number: ");
  scanf("%d", &num2);

  printf("GCD - %d\n", gcd(num1, num2) );
  printf("LCM - %d\n", (num1 * num2) / gcd(num1, num2) );

  return 0;
}