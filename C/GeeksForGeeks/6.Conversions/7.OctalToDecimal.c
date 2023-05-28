#include <stdio.h>
#include <math.h>
//using format specifier
// int main(void)
// {
//   int octal;
//   printf("Enter an octal number: ");
//   scanf("%o", &octal);

//   int decimal = octal;
//   printf("Decimal number of %o is %d\n", octal, decimal);
//   return 0;
// }

int main (void)
{
  int octal = 67;
  int decimal = 0;
  int power=0;

  while(octal != 0)
  {
    decimal += (octal % 10) * pow(8, power++);
    octal = octal / 10;
  }
  printf("%d\n", decimal);
  return 0;
}