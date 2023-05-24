#include <stdio.h>

int main (void)
{
  int arr[4][4] = {   { 1, 2, 3, 4 },
                      { 6, 2, 3, 9 },
                      { 3, 2, 3, 9 },
                      { 1, 2, 3, 4 } };

  for (int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      printf("%d  ", arr[i][j]);
    }
    printf("\n");
  }

  printf("########################\n");

  for (int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
    {
      if(i == 0 || i == 3 || j == 0 || j == 3)
        printf("%d  ", arr[i][j]);
      else
      {
        printf(" ");
        printf("  ");
      }
    }
    printf("\n");
  }

  return 0;
}