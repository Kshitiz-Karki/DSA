#include <stdio.h>
// #include <stdint.h>

typedef enum {
   PERFECT_NUMBER = 1,
   ABUNDANT_NUMBER = 2,
   DEFICIENT_NUMBER = 3,
   ERROR = -1
} kind;

kind classify_number(int n);
int main(void)
{
  kind result = classify_number(28);
  printf("result - %d\n", result);
  return 0;
}

kind classify_number(int n)
{
  if (n <= 0) return ERROR;
  int aliquot_sum = 0;
  for(int i=1; i<=n/2; i++)
  {
    if(n % i == 0)
      aliquot_sum += i;
  }
  if (aliquot_sum == n) return PERFECT_NUMBER;
  else if (aliquot_sum > n) return ABUNDANT_NUMBER;
  else return DEFICIENT_NUMBER;
}