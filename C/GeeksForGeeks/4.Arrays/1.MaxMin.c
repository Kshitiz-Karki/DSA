#include <stdio.h>

int main (void)
{
  int arr[] = {1000, 11, 445, 1, 330, 3000};
  int arrLength = sizeof(arr)/sizeof(int);
  int max = arr[0];
  int min = arr[0];
  for(int i=1; i<arrLength; i++)
  {
    if(arr[i] > max)
      max = arr[i];
    if(arr[i] < min)
      min = arr[i];
  }
  printf("Max - %d\n", max);
  printf("Min - %d\n", min);
  return 0;
}