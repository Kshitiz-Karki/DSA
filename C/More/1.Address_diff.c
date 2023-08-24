#include <stdio.h>

int main (void)
{
  int age[] = {10, 32, 27, 50};

  printf("Address of age[0] - %p\n", age);
  printf("Address of age[1] - %p\n", age+1);
  printf("&age[0] - &age[1] = %ld\n", (age+2) - age);
  return 0;
}