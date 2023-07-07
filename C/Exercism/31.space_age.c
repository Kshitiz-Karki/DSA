#include <stdio.h>
#include <stdint.h>

typedef enum planet {
   MERCURY,
   VENUS,
   EARTH,
   MARS,
   JUPITER,
   SATURN,
   URANUS,
   NEPTUNE,
} planet_t;

// float age(planet_t planet, int64_t seconds)
// {
//   float age_in_secs = 0.00F;
//   switch (planet)
//   {
//   case MERCURY:
//     age_in_secs = seconds/(31557600 * 0.2408467);
//     break;
//   case VENUS:
//     age_in_secs = seconds/(31557600 * 0.61519726);
//     break;
//   case EARTH:
//     age_in_secs = seconds/(31557600 * 1);
//     break;
//   case MARS:
//     age_in_secs = seconds/(31557600 * 1.8808158);
//     break;
//   case JUPITER:
//     age_in_secs = seconds/(31557600 * 11.862615);
//     break;
//   case SATURN:
//     age_in_secs = seconds/(31557600 * 29.447498);
//     break;
//   case URANUS:
//     age_in_secs = seconds/(31557600 * 84.016846);
//     break;
//   case NEPTUNE:
//     age_in_secs = seconds/(31557600 * 164.79132);
//     break;
//   default:
//     age_in_secs = -1;
//     break;
//   }
//   return age_in_secs;
// }

static const int EARTH_YR_SECS = 31557600;
static const double PLANET_YRS[] = {0.2408467, 0.61519726, 1.0, 1.8808158, 11.862615, 29.447498, 84.016846, 164.79132};
float age(planet_t planet, int64_t seconds)
{
  return planet >= 0 && planet <=7 ? seconds/(EARTH_YR_SECS * PLANET_YRS[planet]) : -1;
}

int main(void)
{
  float x = 0.00F;
  x = age(MERCURY, 2134835688);
  printf("%f\n", x);
  return 0;
}