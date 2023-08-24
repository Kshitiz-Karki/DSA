#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double width = atof(argv[1]);
  double height = atof(argv[2]);
  double perimeter = 0.0, area = 0.0;
  perimeter = 2.0*(width + height);
  area = width * height;

  printf("Area - %.2lf\n", area);
  printf("Perimeter - %.2lf\n", perimeter);
  return 0;
}