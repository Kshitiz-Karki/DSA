#include <stdio.h>

// int main (void)
// {
//   int n;
//   int sum = 0;
//   printf("Enter a positive number: ");
//   scanf("%d", &n);

//   for(int i=1; i<=n; i++)
//     sum += i;

//   printf("Sum - %d\n", sum);
//   return 0;
// }

////////////////////////////////////////////////////////////////////////////////////////////////////

//Using recursion
// int sum (int n)
// {
//   if(n < 1)
//     return 0;
//   return n + sum(n-1);
// }

// int main (void)
// {
//    int n;
//   printf("Enter a positive number: ");
//   scanf("%d", &n);

//   printf("Sum - %d\n", sum(n));
//   return 0;
// }
////////////////////////////////////////////////////////////////////////////////////////////////////

//Using Maths
int main (void)
{
   int n;
  printf("Enter a positive number: ");
  scanf("%d", &n);

  int sum = (n * (n+1))/2; 
  printf("Sum - %d\n", n >= 0 ? sum : 0);
  return 0;
}