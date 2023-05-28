#include <stdio.h>
#include <math.h>
// int main (void)
// {
//   int decimal = 55;
//   int octal = decimal;
//   printf("%o\n", octal);
//   return 0; 
// }

int main (void)
{
  int decimal = 55;
  int octal = 0;
  int power = 0;
  
  while(decimal >= 1)
  {
    octal += (decimal % 8) * pow(10, power++);
    decimal = decimal / 8;
  }
  printf("%d\n", octal);



  return 0;
}