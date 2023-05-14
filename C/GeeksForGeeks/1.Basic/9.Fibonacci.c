#include <stdio.h>

// int main(void)
// {
//   int num;
//   printf("Enter number: ");
//   scanf("%d", &num);

//   int fib[num];
//   fib[0] = 0;
//   fib[1] = 1;

//   printf("%d %d ", fib[0], fib[1]);

//   for(int i=2; i<num; i++)
//   {
//     fib[i] = fib[i-1] + fib[i-2];
//     printf("%d ", fib[i]);
//   }
//   printf("\n");
// }
int fib_num[20];

int fib(int num)
  {
    if(num <= 0)
    {
      fib_num[0] = 0;
      return 0;
    }
    else if(num == 1)
    {
      fib_num[1] = 1;
      return 1;
    }
    else
    {
      if(fib_num[num-1] == -1)
        fib_num[num-1] = fib(num-1);

      if(fib_num[num-2] == -1)
        fib_num[num-2] = fib(num-2);

      fib_num[num] = fib_num[num-1] + fib_num[num-2];
      return fib_num[num-1] + fib_num[num-2];
    }
  }

int main(void)
{
  int num;
  printf("Enter number: ");
  scanf("%d", &num);

  for(int i=0; i<num; i++)
    fib_num[i] = -1;

  fib(num-1);

  for(int i=0; i<num; i++)
    printf("%d ", fib_num[i]);
  printf("\n");
}