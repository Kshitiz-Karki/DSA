#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 16  //longest roman number = MMMDCCCLXXXVIII + 1 (for '\0')

char *to_roman_numeral(unsigned int number)
{
  char *roman_numbers[][10] = {
    {"", "M", "MM", "MMM", "", "", "", "", "", ""},
    {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
    {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
    {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
  };
  char *result = (char *)calloc(MAX_SIZE, sizeof(char));
  int i=3, j=0, quotient, divisor;
  
  while (number > 0)
  {
    divisor = pow(10, i--); 
    quotient = number / divisor;
    if(quotient == 0)
    {
      j++;
      continue;
    }
    strcat(result, roman_numbers[j++][quotient]);
    number = number - (divisor * quotient);
  }
  return result;
}


int main (void)
{
  int num1 = 402;
  int num2 = 163;
  char *roman1 = to_roman_numeral(num1);
  char *roman2 = to_roman_numeral(num2);
  // to_roman_numeral(num);
  printf("!!!!%s!!!!!!!\n", roman1);
  printf("!!!!%s!!!!!!!\n", roman2);
  return 0;
}