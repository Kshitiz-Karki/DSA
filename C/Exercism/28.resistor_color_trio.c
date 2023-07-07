#include <stdio.h>
#include <math.h>
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

typedef enum {
   OHMS = 0,
   KILOOHMS = 1000,
} unit_t;

typedef struct
{
  size_t value;
  unit_t unit;
}resistor_value_t;

resistor_value_t color_code(resistor_band_t bands[])
{
  resistor_value_t resistor;
  char codes[2];
  for(int i=0; i<2; i++)
    codes[i] = bands[i] + '0';
  int ohms = atoi(codes) * pow(10, bands[2]);
 
  if(ohms >= 1000)
  {
    resistor.value = ohms/1000;
    resistor.unit = KILOOHMS;
  }
  else
  {
    resistor.value = ohms;
    resistor.unit = OHMS;
  }
  return resistor;
}

int main(void)
{
  resistor_band_t bands[] = { YELLOW, VIOLET, YELLOW  };
  resistor_value_t resistor = color_code(bands);
  printf("%d  %d\n", resistor.value, resistor.unit);
  return 0;
}