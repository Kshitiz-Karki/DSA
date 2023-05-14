#include <stdio.h>

int main (void)
{
  int rows;
  printf("Enter number of rows: ");
  scanf("%d", &rows);

  for(int i=1; i<=rows; i++)
  {
    for(int j=i; j<=rows-1; j++)
      printf("  ");
    
    for(int k=0;k<i; k++)
      printf("%d ", i);
    
    for(int p=0; p<i-1; p++)
      printf("%d ", i);

    printf("\n");
  }
  return 0;
}