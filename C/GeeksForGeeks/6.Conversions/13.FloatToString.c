#include <stdio.h>

int main (void)
{
  float num = 233.007;
  char buffer[50];
  sprintf(buffer, "%.3f", num);
  printf("%s\n", buffer);
  return 0;
}