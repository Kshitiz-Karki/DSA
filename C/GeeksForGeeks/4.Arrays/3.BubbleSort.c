#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *y;
  *y = *x;
  *x = temp;
}

void bubbleSort(int arr[], int size)
{
  int noSwap;
  for(int i=size-1; i>1; i--)
  {
    noSwap = 1;
    for(int j=0; j<i; j++)
    {
      if(arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
        noSwap = 0;
    }
    if(noSwap) break;
  }
}

int main (void)
{
  int arr[9] = {2, 19, 0, 10, 16, 4, -5, 1, 14};
  int arraySize = sizeof(arr)/sizeof(int);
  
  bubbleSort(arr, arraySize);

  for(int i=0; i<arraySize; i++)
  {
    printf("%d\n", arr[i]);
  }
  return 0;
}