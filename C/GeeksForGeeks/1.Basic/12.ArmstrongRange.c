#include <stdio.h>
#include <math.h>

int isArmstrong(int num)
{
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
    return 1;
  else
    return 0;

}

int main (void)
{
  for(int i=1; i<=1000; i++)
  {
    if(isArmstrong(i))
      printf("%d ", i);
  }
  printf("\n");
  return 0;
}