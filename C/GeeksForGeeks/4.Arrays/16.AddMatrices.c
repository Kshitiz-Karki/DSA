#include <stdio.h>

int main (void)
{
  int A[3][4] = { {1, 1, 1, 1},
                  {2, 2, 2, 2},
                  {3, 3, 3, 3}};
  
  int B[3][4] = { {1, 1, 1, 1},
                  {2, 2, 2, 2},
                  {3, 3, 3, 3},};
  int C[3][4];

  for(int i=0; i<3; i++)
  {
    for(int j=0; j<4; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
    


  return 0;
}