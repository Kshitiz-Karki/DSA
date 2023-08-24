#include <stdio.h>

int main(void)
{
  int minutes = 0;
  double years = 0.0;
  double days = 0.0; //use .0 if the data type is double/float

  printf("Enter the number of minutes: ");
  scanf("%d", &minutes);

  days  = minutes/(60.0 * 24.0);//use .0 if the data type is double/float
  years = days/365.0;

  printf("days - %lf\n", days);
  printf("years - %lf\n", years);
  return 0;
}