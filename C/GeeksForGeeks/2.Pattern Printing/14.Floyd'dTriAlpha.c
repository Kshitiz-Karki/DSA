#include <stdio.h>

int main (void)
{
  int rows=6;
  int x=97;
  
  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<i; j++)
    {
      printf("%c ", x++);
    }
    printf("\n");
  }
  return 0;
}