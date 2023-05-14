#include <stdio.h>
#include <math.h>

int main (void)
{
  int num;
  printf("Enter any positive number: ");
  scanf("%d", &num);

  int i = 0;
  int sum = 0;
  int temp = num;
  while (temp != 0)
  {
    temp = temp / 10;
    i++;
  }
  temp = num;
  while (temp != 0)
  {
    sum = sum + pow(temp % 10, i);
    temp = floor(temp / 10);
  }

  if(num == sum)
    printf("%d is armstrong!!\n", num);
  else
    printf("%d is not armstrong!!\n", num);

  return 0;
}