#include <stdint.h>
#include <string.h>
#include <ctype.h>

int64_t largest_series_product(char *digits, size_t span);

int main(void)
{
  int64_t largest_product = largest_series_product("99099", 3);
  printf("largest_product - %ld\n", largest_product);
  return 0;
}

int64_t largest_series_product(char *digits, size_t span)
{
  size_t digits_len =strlen(digits);
  if(digits_len < span || (int)span < 0) return -1;
  int64_t product = 1, largest_product = 0;

  for(size_t i=0; i<=digits_len-span; i++)
  {
    for(size_t j=i; j<i+span; j++)
    {
      if(!isdigit(digits[j])) return -1;
      product *= digits[j] - 48;
    }
    if(product > largest_product)
      largest_product = product;
    product = 1;
  }
  return largest_product;
}