#include <stddef.h>
#include <stdio.h>

int is_factor(int num, const unsigned int *factors, const size_t number_of_factors)
{
  for(size_t i=0; i<number_of_factors; i++)
  {
    if(factors[i] == 0)
      return 0;
    if(num % factors[i] == 0)
      return 1;
  } 
  return 0;
}

unsigned int sum(const unsigned int *factors, const size_t number_of_factors, const unsigned int limit)
{
  unsigned int sum_of_multiples = 0;
  for(unsigned int i=1; i<limit; i++)
  {
    if(is_factor(i, factors, number_of_factors))
      sum_of_multiples += i;
  }
  return sum_of_multiples;
}

int main(void)
{
  const unsigned int factors[1] = {  0 };
  size_t number_of_factors = 1;
  const unsigned int limit = 1;
  printf("Sum of multiples - %u\n", sum(factors, number_of_factors, limit));
  return 0;
}
