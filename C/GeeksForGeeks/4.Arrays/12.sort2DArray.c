#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void sortRowWise(int arr[4][4], int row, int col)
{
  int noSwap;
  for(int i=0; i<col; i++)
  {
    for(int j=row; j>0; j-- )
    {
      noSwap = 1;
      for(int k=0; k<j-1; k++)
      {
        if(arr[i][k] > arr[i][k+1])
          swap(&arr[i][k], &arr[i][k+1]);
          noSwap = 0;
      }
      if(noSwap)
        break;
    }
  }
}

int main (void)
{
  int arr[4][4] = {{4,7,0,3}, {8, 1, 1, 6}, {0,9,3,2}, {7, 0, 2, 4}};

  sortRowWise(arr, 4, 4);

  for(int i=0; i<4; i++)
  {
    for(int j=0; j<4; j++)
      printf("%d  ", arr[i][j]);
    printf("\n");
  }
  return 0;
}