#include <stdio.h>

#define ROW 3
#define COL 4

int main (void)
{
  int A[ROW][COL] = {
                  {6,3,1,5},
                  {4,5,2,7},
                  {2,4,9,0}
  };

  int temp;

  for(int i=0; i<ROW; i++)
  {
    temp = A[i][0];
    A[i][0] = A[i][COL-1];
    A[i][COL-1] = temp;
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