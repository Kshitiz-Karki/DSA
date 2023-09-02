#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stddef.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length);

int main(void)
{
  int8_t digits[DIGITS_ARRAY_SIZE] = { 1, 0, 1, 0, 1, 0 };
  // int8_t digits[DIGITS_ARRAY_SIZE] = {5};
  // int8_t digits[DIGITS_ARRAY_SIZE] = {1};
  // int8_t digits[DIGITS_ARRAY_SIZE] = { 1, 1, 2, 0 };
  // int8_t digits[] = { 4, 2 };
  // int8_t digits[DIGITS_ARRAY_SIZE] = { 2, 10 };
  // int8_t digits[DIGITS_ARRAY_SIZE] = { 1, 0, 1, 0, 1, 0 };  
  // int8_t digits[DIGITS_ARRAY_SIZE] = { 3, 46, 60 };
  // int8_t digits[] = { 7 };
  
  size_t output_length = rebase(digits, 2, 10, 6);
  printf("\noutput_length = %ld\n", output_length);

  for(size_t y=0; y<output_length; y++)
    printf("%d ", digits[y]);

  return 0;
}

size_t rebase(int8_t *digits, int16_t input_base, int16_t output_base, size_t input_length)
{
  if (input_base <= 1 || output_base <= 1 || !input_length) return 0;
  int16_t base_10 = 0;
  for(size_t i=0; i<input_length; i++)
  {
    if(digits[i] < 0 || digits[i] >= input_base) return 0;
    base_10 += digits[i] * pow(input_base, input_length - 1 - i);
    digits[i] = 0;
  }
  int8_t out_digits[DIGITS_ARRAY_SIZE] = {0};
  size_t output_len = 0;
  do
    {
      out_digits[output_len++] = base_10 % output_base;
      base_10 /= output_base;
    }
  while(base_10 > 0);

  for(size_t j=0; j<output_len; j++)
    digits[j] = out_digits[output_len - 1 - j];

  return output_len;
}