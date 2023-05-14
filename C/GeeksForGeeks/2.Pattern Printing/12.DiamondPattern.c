#include <stdio.h>

int main (void)
{
  int rows = 8;

  for(int i=1; i<=rows; i++)
  {
    for(int x=1; x<=rows-i; x++)
      printf(" ");
    
    for(int y=1; y<=i; y++)
      printf("* ");

    printf("\n");
  }
/////////////////////////////////////////////
  for(int i=1; i<=rows; i++)
  {
    for(int x=1; x<i; x++)
      printf(" ");
    
    for(int y=0; y<=rows-i; y++)
      printf("* ");

    printf("\n");
  }
  return 0;
}

// //     *       - 5
// //    * *      - 4
// //   * * *     - 3 
// //  * * * *    - 2
// // * * * * *   - 1
// //* * * * * *  - 0 
// * * * * * *    
//  * * * * * 
  // * * * * 
  //  * * * 
    // * * 
    //  * 