#include <stdio.h>

// int main (void)
// {
//   int num;
//   int fact = 1;
//   printf("Enter number: ");
//   scanf("%d", &num);

//   for(int i=2; i<=num; i++)
//     fact *= i;
  
//   printf("Factorial - %d\n", fact);
//   return 0;
// }


//using recursion
int fact(int num)
{
  if(num <= 1)
    return 1;
  return fact(num-1) * num;
}

int main (void)
{
  int num;
  printf("Enter number: ");
  scanf("%d", &num);
  
  printf("Factorial - %d\n", fact(num));
  return 0;
}