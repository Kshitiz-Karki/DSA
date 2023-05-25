#include <stdio.h>

#define ROW 3
#define COL 3

int main (void)
{
  int A[ROW][COL] = {
                  {6,3,1},
                  {4,5,2},
                  {2,4,9}
  };

  int temp;

  for(int i=0; i<COL; i++)
  {
    temp = A[0][i];
    A[0][i] = A[ROW-1][i];
    A[ROW-1][i] = temp;
  }

  for(int i=0; i<ROW; i++)
  {
    for(int j=0; j<COL; j++)
    {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}