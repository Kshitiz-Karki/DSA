#include <stdio.h>

int main (void)
{
  int rows=5;
  int x=(rows*(rows+1))/2;
  
  for(int i=0; i<rows; i++)
  {
    for(int j=0; j<rows-i; j++)
    {
      printf("%d ", x--);
    }
    printf("\n");
  }
  return 0;
}

// 6 + 5 + 4 + 3 + 2 + 1