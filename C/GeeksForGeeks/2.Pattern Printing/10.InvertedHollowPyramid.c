#include <stdio.h>

int main (void)
{
  int rows = 6;
  int k = 2*rows-5;

  for(int i=1; i<=rows; i++)
  {
    if(i==1)
    {
      for(int j=0; j<2*rows-1; j++)
        printf("*");
    }
    else
      {
        if(i != rows)
        {
          for(int p=1; p<i; p++)
            printf(" ");
          printf("*");
          
          for(int q=1; q<=k; q++)
            printf(" ");
          k -= 2;
          printf("*");
        }
        else
          {
            for(int x=1; x<rows; x++)
              printf(" ");
            printf("*");
          }
      }
  printf("\n");
  }
  return 0;
}

// *********
//  *     * - 5
//   *   *  - 3
//    * *   - 1
//     *    - 0 

//***************
  //  *           *  - 11
  //   *         * - 9
  //    *       *     - 7
  //     *     *
  //      *   *
  //       * *
  //        *  