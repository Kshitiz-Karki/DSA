#include <stdio.h>

int main (void)
{
  int rows;
  printf("Enter no. of rows: ");
  scanf("%d", &rows);

  int x=1;
  int y=1;
  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<rows-i; j++)
      printf(" ");
    
    x=i;
    for(int k=0; k<i; k++)
      printf("%d", x++);
    
    y=i;
    for(int l=1; l<i; l++)
      y+=1;
    
    for(int l=1; l<i; l++)
      printf("%d", --y);
    
    printf("\n");
  }

  return 0;
}