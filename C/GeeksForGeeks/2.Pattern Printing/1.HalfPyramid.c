#include <stdio.h>

int main (void)
{
  int rows;
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<i; j++)
    {
      printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}