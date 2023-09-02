#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 104744

uint32_t nth(uint32_t n);

int main(void)
{
  uint32_t n = 10001;
  uint32_t result = nth(n);
  printf("result - %d\n", result);
  return 0;
}
//Optimized "Seieve of Eratosthenes" -> O(n log log n) ~ O(n)
uint32_t nth(uint32_t n)
{
  uint32_t result = 0;
  bool *isPrime = (bool *)calloc(MAX_SIZE, sizeof(isPrime));
  memset(isPrime, true, MAX_SIZE);
  uint32_t x=0;
  for(uint32_t i=2; i<=MAX_SIZE; i++)
  {
    if(isPrime[i])
    {
      if(++x == n){
        result = i;
        break;
      }
      for(uint32_t j=i*i; j<=MAX_SIZE; j=j+i)
        isPrime[j] = false;
    }
  }
  free(isPrime);
  return result;
}