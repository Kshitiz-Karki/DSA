#include <stdio.h>

int binarySearch(int arr[], int x, int size)
{
  int left = 0;
  int right = size-1;
  int middle = 0;

  while(left <= right)
  {
    // middle = left + (right-left)/2;
    middle = (left+right)/2;
    if(arr[middle] == x)
      return middle;
    else if(arr[middle] < x )
      left = middle + 1;
    else
      right = middle - 1;
  }
  return -1;
}

int main (void)
{
  int arr[] = {2, 3, 4, 10, 40};
  int arrLength = sizeof(arr)/sizeof(int);
  int x = 10;

  printf("Element %d is at index - %d\n", x, binarySearch(arr, x, arrLength));
  return 0;
}