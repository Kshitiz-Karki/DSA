#include <stdio.h>

int areEqual(int arr1[4][4], int arr2[4][4], int row, int col)
{
  for(int i=0; i<col; i++)
  {
    for(int j=0; j<row; j++)
    {
      if(arr1[i][j] != arr2[i][j])
        return 0;
    }
  }
  return 1;
}

int main (void)
{
  int A[4][4] = { {1,2,3,4},
                  {1,2,3,4},
                  {1,2,3,4},
                  {1,2,3,4}
                  };

  int B[4][4] = { {1,2,3,4},
                  {1,2,3,4},
                  {1,2,3,4},
                  {1,2,3,4}};
  
  int sizeA = sizeof(A)/sizeof(int);
  int sizeB = sizeof(B)/sizeof(int);

  if(sizeA != sizeB)
    printf("Are equal - 0\n");
  else
    printf("Are equal - %d\n", areEqual(A, B, 4, 4));

  return 0;
}