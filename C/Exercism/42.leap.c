#include <stdbool.h>
#include <stdio.h>

bool leap_year(int year)
{
  return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main (void)
{
  printf("Is leap year - %d\n", leap_year(2015));
  return 0;
}