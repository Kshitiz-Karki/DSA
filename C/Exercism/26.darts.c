#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct
{
  float x;
  float y;
}coordinate_t;

uint8_t score(coordinate_t pos)
{  
  float distance = hypot(pos.x, pos.y);

  if(distance <= 1.0F)
    return 10;
  if(distance <= 5.0F)
    return 5;
  if(distance <= 10.F)
    return 1;
  return 0;
}

int main(void)
{
  coordinate_t landing_position = { 0.0F, -1.0F };
  printf("Score - %u\n", score(landing_position));
  return 0;
}