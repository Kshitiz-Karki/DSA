#ifndef SIEVE_H
#define SIEVE_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

/// Calculate at most `max_primes` prime numbers in the interval [2,limit]
/// using the Sieve of Eratosthenes and store the prime numbers in `primes`
/// in increasing order.
/// The function returns the number of calculated primes.
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes)
{
  bool isPrime[limit+1];
  for(uint32_t i=0; i<=limit; i++)
    isPrime[i] = true;

  uint32_t j=0;
  for(uint32_t i=2; i<=limit; i++)
  {
    if(isPrime[i] && j < max_primes)
    {
      // printf("%u ", i);
      primes[j++] = i;
      for(uint32_t j=i*i; j<=limit; j=j+i)
        isPrime[j] = false;
    }
  }
  // printf("\n");
  // for(int i=0; i<max_primes; i++)
  //   printf("%lu ", primes[i]);
  // printf("\n");
  return j;
}

int main (void)
{
  uint32_t limit = 5;
  size_t max_primes = 5;
  uint32_t primes[max_primes];

  // sieve(limit, primes, max_primes);
  printf("%lu\n", sieve(limit, primes, max_primes));
  return 0;
}

#endif
