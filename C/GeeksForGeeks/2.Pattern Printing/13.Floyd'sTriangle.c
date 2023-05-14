#include <stdio.h>

int main (void)
{
  int rows=6;
  int x=1;
  
  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<i; j++)
    {
      printf("%d ", x++);
    }
    printf("\n");
  }
  return 0;
}