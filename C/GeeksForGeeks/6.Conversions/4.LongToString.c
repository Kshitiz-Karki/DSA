#include <stdio.h>

int main (void)
{
  long integer = 1255;
  char s[10];
  int i=0;

  while(integer != 0)
  {
    s[i++] = 48 + (integer % 10);
    integer = integer / 10;
  }
  s[i] = '\0';

  int left = 0;
  int right = i-1;
  while(left < right)
  {
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    left++; right--;
  }
  printf("%s\n", s);
  return 0;
}

//using sprintf()

// #include <stdio.h>

// int main (void)
// {
//   long integer = 1234;
//   char s[10];
//   sprintf(s, "%li", integer);
//   printf("%s\n", s);
//   return 0;
// }