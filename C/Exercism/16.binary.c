#include <stdio.h>
#include <string.h>
#include <math.h>

#define INVALID -1

int convert(const char *input)
{
  int sum=0;
  int power = strlen(input)-1;
  int length = strlen(input);
  int currentBit = 0;

  for(int i=0; i<length; i++)
  {
    currentBit = input[i] - '0';
    if(currentBit < 0 || currentBit > 1)
      return INVALID;
    sum += currentBit * (int) pow(2, power);
    power--;
  }
  return sum;
}

int main (void)
{
  const char *binary = "10111";
  printf("Decimal - %d\n", convert(binary));
}
