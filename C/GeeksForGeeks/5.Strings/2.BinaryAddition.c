#include <stdio.h>
#include <string.h>

int main (void)
{
  char str1[] = "11";    //110
  char str2[] = "1";

  int resultLen = strlen(str1) > strlen(str2) ? strlen(str1)+1 : strlen(str2)+1;
  char result[resultLen];
  result[resultLen] = '\0';

  int k = resultLen-1;
  int i = strlen(str1)-1; 
  int j = strlen(str2)-1;

  int num1;
  int num2;

  int carry = 0;
  int temp;

  while(i >=0 || j>=0)
  {
    num1 = i < 0 ? '0' : str1[i] - '0';
    num2 = j < 0 ? '0' : str2[j] - '0';
    temp = num1 + num2 + carry;

    if(temp > 1)
    {
      carry = 1;
      temp = temp % 2;
    }
    result[k] = temp + '0';
    i--;j--;k--;
  }
  if(carry)
    result[0] = '1';
  else
    result[0] = '0';
  
  printf("Sum - %s\n", result);
  return 0;
}