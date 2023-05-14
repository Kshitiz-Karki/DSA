#include <stdio.h>

//naive approach
// int main (void)
// {
//   int num;
//   printf("Enter a number - ");
//   scanf("%d", &num);

//   for(int i=1; i<=num/2; i++)
//   {
//     if(num % i == 0)
//       printf("%d ", i);
//   }
//   printf("%d\n", num);
//   return 0;
// }

//more efficient solution
int main (void)
{
  int num;
  printf("Enter a number - ");
  scanf("%d", &num);

  for(int i=1; i*i<=num; i++)
  {
    if(num % i == 0)
    {
      if(num / i == i)
        printf("%d ", i);
      else
      printf("%d %d ", i, num / i);
    }
  }
  printf("\n", num);
  return 0;
}