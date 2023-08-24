#include <stdio.h>

void print_binary(int n)
{
  if(n == 1)
    printf("%d", 1);
  else
  {
    print_binary(n/2);
    printf("%d", n%2);
  }
}

int main(void)
{
  print_binary(12); //100
  return 0;
}