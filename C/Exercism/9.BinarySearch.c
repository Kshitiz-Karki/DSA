#include <stdio.h>

const int *binary_search(int value, const int *arr, size_t length)
{
  int left = 0;
  int right = length-1;

  int mid=0;

  while(left <= right)
  {
    mid = (left+right)/2;
    if(arr[mid] == value)
      return &arr[mid];
    else if(arr[mid] > value)
      right = mid-1;
    else
      left = mid+1;
  }
  return NULL;
}

int main(void)
{
   int arr[] = { 1, 3, 4, 6, 8, 9, 11 };
  
  printf("%p\n", binary_search(4, arr, 7));
  return 0;
}