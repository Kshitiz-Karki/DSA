#include <stdio.h>

int square_root(int n)
{
  int left = 0;
  int right = n/2;
  int mid = 0;

  if(n <= 1)
    return n;

  while(left <= right)
  {
    mid = (left+right)/2;
    if(mid == n)
      return mid;
    if(mid > n)
      right = mid-1;
    else
      left = mid+1;
  }
}

int main (void)
{
  printf("Square root - %d\n", square_root(16));
  return 0;
}