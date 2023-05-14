#include <stdio.h>

// int main (void)
// {
//   int num;
//   printf("Enter a number: ");
//   scanf("%d", &num);

//   int rev_num = 0;
//   while(num != 0)
//   {
//     rev_num = num % 10 + rev_num * 10;
//     num = num / 10;
//   }
//   printf("%d\n", rev_num);
//   return 0;
// }

//Using recursion
int reverse(int num)
{
  static int rev_num = 0;
  if(num == 0)
    return rev_num;
  else
  {
    rev_num = num % 10 + rev_num * 10;
    num = num / 10;
    reverse(num);
  }
}

int main (void)
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  printf("%d\n", reverse(num));
  return 0;
}