#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define MAXFACTORS 10

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]);

int main(void)
{
  uint64_t buffer[MAXFACTORS] = {0};
  size_t len = find_factors(93819012551, buffer);

  for(size_t i=0; i<len; i++)
    printf("%ld ", buffer[i]);
  return 0;
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS])
{
  int prime = 2;
  size_t j=0;
  while(n > 1)
  {
    if(n % prime == 0) // if n is divisible cleanly
    {
      factors[j++] = prime;
      n = n / prime;
    }
    else prime++;
  }
  return j;
}