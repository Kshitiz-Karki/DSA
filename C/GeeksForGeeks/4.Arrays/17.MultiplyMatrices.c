// #include <stdio.h>

// #define ROW1 2
// #define COL1 3
// #define ROW2 3
// #define COL2 2

// int main (void)
// {
//   int A[ROW1][COL1] = { {1, 2, 3}, 
//                         {4, 5, 6}};
  
//   int B[ROW2][COL2] = { {7, 8}, 
//                         {9, 10},
//                         {11, 12}};  

//   int C[ROW1][COL2];

//   for(int i=0; i<ROW1; i++)
//   {
//     for(int j=0; j<COL2; j++)
//     {
//       for(int k=0; k<ROW2; k++)
//       {
//         C[i][j] += A[i][k] * B[k][j];
//         // printf("%d ", C[i][j]);
//       }
//     }
//     // printf("\n");
//   }

//   for(int i=0; i<ROW1; i++)
//   {
//     for(int j=0; j<COL2; j++)
//     {
//       printf("%d ", C[i][j]);
//     }
//     printf("\n");
//   }


//   return 0;
// }


// #include <stdio.h>

// #define ROW1 1
// #define COL1 3
// #define ROW2 3
// #define COL2 1

// int main (void)
// {
//   int A[ROW1][COL1] = { {1, 2, 3}}; 
  
//   int B[ROW2][COL2] = { {4}, 
//                         {5},
//                         {6}};

//   int C[ROW1][COL2];

//   for(int i=0; i<ROW1; i++)
//   {
//     for(int j=0; j<COL2; j++)
//     {
//       for(int k=0; k<ROW2; k++)
//       {
//         C[i][j] += A[i][k] * B[k][j];
//         // printf("%d ", C[i][j]);
//       }
//     }
//     // printf("\n");
//   }

//   for(int i=0; i<ROW1; i++)
//   {
//     for(int j=0; j<COL2; j++)
//     {
//       printf("%d ", C[i][j]);
//     }
//     printf("\n");
//   }


//   return 0;
// }

#include <stdio.h>

#define ROW1 2
#define COL1 2
#define ROW2 2
#define COL2 2

int main (void)
{
  int A[ROW1][COL1] = { {2, 4}, 
                        {3, 4}};
  
  int B[ROW2][COL2] = { {1, 2}, 
                        {1, 3}};

  int C[ROW1][COL2];

  for(int i=0; i<ROW1; i++)
  {
    for(int j=0; j<COL2; j++)
    {
      for(int k=0; k<ROW2; k++)
      {
        C[i][j] += A[i][k] * B[k][j];
        // printf("%d ", C[i][j]);
      }
    }
    // printf("\n");
  }

  for(int i=0; i<ROW1; i++)
  {
    for(int j=0; j<COL2; j++)
    {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }


  return 0;
}