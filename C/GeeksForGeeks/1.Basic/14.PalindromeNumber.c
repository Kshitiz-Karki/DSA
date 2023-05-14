#include <stdio.h>

int main (void)
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int temp = num;
  int rev_num = 0;
  while(temp != 0)
  {
    rev_num = temp % 10 + rev_num * 10;
    temp = temp / 10;
  }
  if(rev_num == num)
    printf("yes!!\n");
  else
    printf("no!!\n");
  return 0;
}