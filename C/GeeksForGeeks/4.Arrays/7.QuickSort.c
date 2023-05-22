#include <stdio.h>

void swap(int *x, int *y)
{ 
  int temp = *x;
  *x = *y;
  *y = temp;
}

int pivot(int arr[], int start, int size)
{
  int pivot = arr[start];
  int swapIndex = start;

  for(int i=start+1; i<size; i++)
  {
    if(pivot > arr[i])
    {
      swapIndex++;
      swap(&arr[i], &arr[swapIndex]);
    }
  }
  swap(&arr[start], &arr[swapIndex]);
  return swapIndex;
}

void quickSort(int arr[], int left, int right, int size)
{
  if(left < right)
  {
    int pivotIndex = pivot(arr, left, size);
    quickSort(arr, left, pivotIndex-1, pivotIndex);
    quickSort(arr, pivotIndex+1, right, size);
  }
}

int main (void)
{
  int arr[9] = {2, 19, 0, 10, 16, 4, -5, 1, 14};
  // int arr[8] = {4,8,2,1,5,7,6,3};
  int arraySize = sizeof(arr)/sizeof(int);
  
  quickSort(arr, 0, arraySize, arraySize);

  for(int i=0; i<arraySize; i++)
    printf("%d\n", arr[i]);
    
  return 0;
}