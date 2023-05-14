#include <stdio.h>

int main (void)
{
  int rows;
  printf("Enter no. of rows: ");
  scanf("%d", &rows);

  char ch='A';

  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<i; j++)
      printf("%c ", ch++);

    printf("\n");
  }
  return 0;
}