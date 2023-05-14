#include <stdio.h>

int main (void)
{
  int num;
  printf("Enter a number - ");
  scanf("%d", &num);

  int fib[2*num];
  fib[0] = 0;
  fib[1] = 1;

  int sum = 0;

  for(int i=2; i<=2*num; i++)
  {
    fib[i] = fib[i-1] + fib[i-2];
    if(i%2 == 0)
      sum += fib[i];
  }
  printf("Sum - %d\n", sum);
  return 0;
}