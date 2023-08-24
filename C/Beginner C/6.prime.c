#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int N;
  printf("Enter the number: ");
  scanf("%d", &N);

  bool isPrime[N+1];
  for(int i=0; i<=N; i++)
    isPrime[i] = true;
  
  for(int i=2; i<=N; i++)
  {
    if(isPrime[i])
    {
      printf("%d ", i);
      for(int j=i*i; j<=N; j=j+i)
      {
        
        isPrime[j] = false;
     
      }
    }
  }
  return 0;
}