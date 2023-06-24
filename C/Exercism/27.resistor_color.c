#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
   BLACK = 0,
   BROWN,
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   BLUE,
   VIOLET,
   GREY,
   WHITE,
} resistor_band_t;

uint16_t color_code(resistor_band_t bands[])
{
  char codes[2];
  for(int i=0; i<2; i++)
    codes[i] = bands[i] + '0';
  return atoi(codes);
}

int main (void)
{
  resistor_band_t bands[] = { BROWN, BLACK };
  printf("%d\n", color_code(bands));
  return 0;
}