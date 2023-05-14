#include <stdio.h>

int checkPrime(int N)
{
  if(N <= 1)
    return 0;

  int flag = 1;
  for(int i=2; i*i<=N; i++)
  {
    if(N % i == 0)
    {
      flag = 0;
      break;
    }
  }
  return flag;
}

int main(void)
{  
  int N;
  printf("Enter a number: ");
  scanf("%d", &N);

  printf("%d\n", checkPrime(N));
  return 0;
}