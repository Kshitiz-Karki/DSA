#include <stdio.h>
#include <math.h>
#include <string.h>

int main (void)
{
  char hexanumber[] = "2D";
  int decimal = 0;
  int power = strlen(hexanumber)-1;
  int digit;

  for(int i=0; hexanumber[i] != '\0'; i++)
  {
    switch (hexanumber[i])
    {
    case 'A':
      digit = 10;
      break;
    case 'B':
      digit = 11;
      break;
    case 'C':
      digit = 12;
      break;
    case 'D':
      digit = 13;
      break;
    case 'E':
      digit = 14;
      break;
    case 'F':
      digit = 15;
      break;
    default:
      digit = hexanumber[i] - '0';
    }
    decimal += digit * pow(16, power--);
  }
  printf("%d\n", decimal);
  return 0;
}