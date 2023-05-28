#include <stdio.h>

int main (void)
{
  int decimal = 10;
  char binary[10];
  int i=0;

  while(decimal != 0)
  {
    binary[i++] = (decimal % 2) + 48;
    decimal = decimal / 2;
  }

  binary[i] = '\0';

  for(int j=i-1; j>=0; j--)
    printf("%c", binary[j]);
  printf("\n");
  return 0; 
}