// #include <stdio.h>

// void transpose(int arr[4][4])
// {
//   int temp[4][4];

//   for(int i=0; i<4; i++)
//   {
//     for(int j=0; j<4; j++)
//       temp[j][i] = arr[i][j];
//   }

//   for(int i=0; i<4; i++)
//   {
//     for(int j=0; j<4; j++)
//       arr[i][j] = temp[i][j];
//   }
// }

// int main (void)
// {
//   int A[4][4] = { {1, 1, 1, 1},
//                   {2, 2, 2, 2},
//                   {3, 3, 3, 3},
//                   {4, 4, 4, 4}};
          
//   transpose(A);

//   for(int i=0; i<4; i++)
//   {
//     for(int j=0; j<4; j++)
//       printf("%d  ", A[i][j]);
//     printf("\n");
//   }

//   return 0;
// }


///transpose of a rectangular matrix (row != col)
#include <stdio.h>

void transpose(int arr1[3][4], int arr2[4][3])
{
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<4; j++)
      arr2[j][i] = arr1[i][j];
  }
}

int main (void)
{
  int A[3][4] = { {1, 1, 1, 1},
                  {2, 2, 2, 2},
                  {3, 3, 3, 3},
                };
  int B[4][3];
          
  transpose(A, B);

  for(int i=0; i<4; i++)
  {
    for(int j=0; j<3; j++)
      printf("%d ", B[i][j]);
    printf("\n");
  }
  return 0;
}