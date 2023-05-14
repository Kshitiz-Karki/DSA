#include <stdio.h>

int main (void)
{
  int rows = 4;
  int k = 1;
  int l = 2*rows - 5;

  for(int i=1; i<=rows; i++)
  {
    if(i==1)
    {
      for(int j=1; j<rows; j++)
        printf(" ");
      printf("*");
    }
    else
    {
      for(int p=1; p<=rows-i; p++)
        printf(" ");
      printf("*");

      for(int x=1; x<=k; x++)
        printf(" ");
      k += 2;
      printf("*");
    }
    printf("\n");
  }
////////////////////////////////////////////
  for(int i=1; i<rows; i++)
  {
    for(int p=1; p<=i; p++)
      printf(" ");
    printf("*");

    if(i!=rows-1)
    {
      for(int x=1; x<=l; x++)
        printf(" ");
      l -= 2;
      printf("*");
    }
    printf("\n");
  }
  return 0;
}

//    *         - 0
//   * *        - 1
//  *   *       - 3
// *     *      - 5
//*       *     - 7
// *     *      - 5
//  *   *       - 3
//   * *        - 1
//    *         - 0