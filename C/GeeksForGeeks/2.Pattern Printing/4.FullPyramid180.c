#include <stdio.h>

int main (void)
{
  int rows;
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<i; j++)
      printf("%d ", i);
    printf("\n");
  }

  for(int i=rows-1; i>=1; i--)
  {
    for(int j=0; j<i; j++)
      printf("%d ", i);
    printf("\n");
  }
  return 0;
}