#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *y;
  *y = *x;
  *x = temp;
}

void selectionSort(int arr[], int size)
{
  int lowest = 0;
  for(int i=0; i<size-1; i++)
  {
    lowest = i; 
    for(int j=i+1; j<size; j++)
    {
      if(arr[j] < arr[lowest])
        lowest = j;
    }
    if(lowest != i)
      swap(&arr[i], &arr[lowest]);
  }
}

int main (void)
{
  int arr[9] = {2, 19, 0, 10, 16, 4, -5, 1, 14};
  int arraySize = sizeof(arr)/sizeof(int);
  
  selectionSort(arr, arraySize);

  for(int i=0; i<arraySize; i++)
  {
    printf("%d\n", arr[i]);
  }
  return 0;
}