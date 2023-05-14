#include <stdio.h>

void insertionSort(int arr[], int size)
{
  int j;
  int currentValue;
  for(int i=1; i<size; i++)
  {
    currentValue = arr[i];
    for(j=i-1; j>=0 && arr[j]>currentValue; j--)
      arr[j+1] = arr[j];
    arr[j+1] = currentValue;
  }
}

int main (void)
{
  int arr[9] = {2, 19, 0, 10, 16, 4, -5, 1, 14};
  int arraySize = sizeof(arr)/sizeof(int);
  
  insertionSort(arr, arraySize);

  for(int i=0; i<arraySize; i++)
    printf("%d\n", arr[i]);

  return 0;
}