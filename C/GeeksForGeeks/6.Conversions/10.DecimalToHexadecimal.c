#include <stdio.h>

// int digitCount(int decimal)
// {
//   int i=0;
//   while (decimal != 0)
//   {
//     decimal = decimal / 16;
//     i++;
//   }
//   return i;
// }

// int main (void)
// {
//   int decimal = 45;
//   char hexadecimal[10];
//   int remainder = 0;
//   int i= digitCount(decimal)-1;
//   int j=0;

//   while(decimal != 0)
//   { 
//     remainder = decimal % 16;
//     if(remainder > 9)
//       hexadecimal[i--] = 55 + remainder;
//     else
//       hexadecimal[i--] = 48 + remainder ;
//     decimal = decimal / 16;
//     j++;
//   }
//   hexadecimal[j] = '\0';
//   printf("%s\n", hexadecimal);
//   return 0;
// }

int main (void)
{
  int decimal = 45;
  printf("%x\n", decimal);
  return 0;
}