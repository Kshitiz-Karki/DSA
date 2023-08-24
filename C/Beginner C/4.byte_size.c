#include <stdio.h>


int main(void)
{
  printf("Size of int - %zd bytes\n", sizeof(int));
  printf("Size of char - %zd bytes\n", sizeof(char));
  printf("Size of long - %zd bytes\n", sizeof(long));
  printf("Size of long long - %zd bytes\n", sizeof(long long));
  printf("Size of double - %zd bytes\n", sizeof(double));
  printf("Size of long double - %zd bytes\n", sizeof(long double));
  return 0;
}