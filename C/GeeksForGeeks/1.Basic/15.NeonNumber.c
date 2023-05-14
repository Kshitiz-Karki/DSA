#include <stdio.h>

int main (void)
{
  int num;
  printf("Enter number - ");
  scanf("%d", &num);

  int sum = 0;
  int temp = num;
  temp = num * num;

  while(temp != 0)
  {
    sum += (temp % 10);
    temp /= 10;
  }

  if(sum == num)
    printf("Is Neon - yes!!\n");
  else
    printf("Is Neon - no!!\n");

  
  return 0;
}