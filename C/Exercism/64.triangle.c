#include <stdio.h>
#include <stdbool.h>

typedef struct {
   double a;
   double b;
   double c;
} triangle_t;

bool is_equilateral(triangle_t sides);
bool is_isosceles(triangle_t sides);
bool is_scalene(triangle_t sides);
bool is_triangle(triangle_t sides);

int main (void)
{
  triangle_t sides = {3, 5, 4};
  printf("is_equilateral - %d\n", is_equilateral(sides));
  printf("is_isosceles - %d\n", is_isosceles(sides));
  printf("is_scalene - %d\n", is_scalene(sides));
  return 0;
}

bool is_triangle(triangle_t sides)
{
  return sides.a > 0 && sides.b > 0 && sides.c > 0 && (sides.a + sides.b >= sides.c) 
    && (sides.b + sides.c >= sides.a) && (sides.a + sides.c >= sides.b);
}


bool is_equilateral(triangle_t sides)
{
  return is_triangle(sides) && (sides.a == sides.b) && ( sides.b == sides.c);
}

bool is_isosceles(triangle_t sides)
{
  return is_triangle(sides) && ((sides.a == sides.b) || ( sides.b == sides.c) || ( sides.a == sides.c));
}

bool is_scalene(triangle_t sides)
{
  return is_triangle(sides) && ((sides.a != sides.b) && ( sides.b != sides.c) && ( sides.a != sides.c));
}