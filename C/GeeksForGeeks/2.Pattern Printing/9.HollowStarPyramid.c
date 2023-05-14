// #include <stdio.h>

// int main (void)
// {
//   int rows = 5;
  
//   for(int i=1; i<=rows; i++)
//   {
//     for(int j=0; j<rows-i; j++)
//       printf(" ");
    
//     if(i == rows)
//     {
//       for(int x=0; x<=2*i; x++)
//         printf("*");
//     }
//     else
//     {
//       if(i == 1)
//         printf(" *");
//       else
//         printf("*");

//       for(int p=1; p<i; p++)
//       {
//         printf(" ");
//         printf(" ");
//       }
//     }

//     if(i!=1 && i!= rows)
//       printf(" *");

//     printf("\n");
//   }
//   return 0;
// }

#include <stdio.h>

int main (void)
{
  int rows = 5;
  
  for(int i=1; i<=rows; i++)
  {
    for(int j=0; j<rows-i; j++)
      printf(" ");
    
    if(i == rows)
    {
      for(int x=0; x<2*i-1; x++)
        printf("*");
    }
    else
    {
      printf("*");

      for(int p=1; p<i; p++)
        printf(" ");
      
      if(i > 2)
      {
        for(int q=0; q<i-2; q++ )
            printf(" ");
      }
    }

    if(i!=1 && i!= rows)
      printf("*");
    printf("\n");
  }
  return 0;
}