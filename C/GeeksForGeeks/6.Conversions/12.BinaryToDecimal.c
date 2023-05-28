#include <stdio.h>
#include <math.h>

int main (void)
{
  int binary = 1000;
  int decimal = 0;
  int power = 0;

  while(binary != 0)
  {
    decimal += (binary % 10) * pow(2, power++);
    binary = binary / 10;
  }
  printf("%d\n", decimal);
  return 0;
}