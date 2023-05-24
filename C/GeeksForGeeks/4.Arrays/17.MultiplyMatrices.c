#include <stdio.h>

int main (void)
{
  int A[2][2] = { {1, 2}, 
                  {3, 4}};
  
  int B[2][2] = { {1, 1}, 
                  {1, 1}};

  int C[2][2];

  for(int i=0; i<2; i++)
  {
    for(int j=0; j<2; j++)
    {
      C[i][j] = A[i][j] + B[i][j];
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
    


  return 0;
}