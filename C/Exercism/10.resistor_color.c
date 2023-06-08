#include <stdio.h>

typedef enum {
    BLACK = 0,
    BROWN = 1,
    RED = 2,
    ORANGE = 3,
    YELLOW = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    GREY = 8,
    WHITE = 9
} resistor_band_t;

int color_code(resistor_band_t color)
{ 
  return color;
}
resistor_band_t * colors()
{
   static resistor_band_t bands[10];
   for (resistor_band_t band = BLACK; band <= WHITE; band++)
        bands[band] = band;
    return bands;
}

int main (void)
{
  printf("%d\n", color_code(VIOLET));
  const resistor_band_t *bands = colors();
  
  // for (resistor_band_t band = BLACK; band <= WHITE; band++)
    printf("%s ", bands[0]);
  return 0;
}