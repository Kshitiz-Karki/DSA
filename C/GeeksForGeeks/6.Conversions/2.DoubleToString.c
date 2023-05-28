#include <stdio.h>

int main (void)
{
  double n = 456321.7651234;
  char buffer[100];

  sprintf(buffer, "%.7f", n);
  printf("%s\n", buffer);
  
  return 0;
}