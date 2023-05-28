#include <stdio.h>

int main (void)
{
  char s[] = "1234567890";
  long integer = 0;

  for(int i=0; s[i] != '\0'; i++)
    integer = (integer*10) + s[i] - '0' ; //since ASCII value of 0 is 48 and that of 1 is 49 and so on...............
  printf("%li\n", integer);
  return 0;
}