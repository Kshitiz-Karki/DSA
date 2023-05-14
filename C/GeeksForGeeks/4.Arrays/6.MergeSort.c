#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
  int i=left;
  int j=mid+1;
  int k=left;

  int B[right+1];

  while(i<=mid && j<=right)
  {
    if(arr[i] < arr[j])
      B[k++] = arr[i++];
    else
      B[k++] = arr[j++];
  }

  for(; i<=mid; i++)
    B[k++] = arr[i];
  
  for(; j<=right; j++)
    B[k++] = arr[j];

  for(i=left; i<=right; i++)
    arr[i] = B[i];
}

void mergeSort(int arr[], int left, int right)
{ 
  int mid;
  if(left < right)
  {
    mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main (void)
{
  int arr[9] = {2, 19, 0, 10, 16, 4, -5, 1, 14};
  int arraySize = sizeof(arr)/sizeof(int);
  
  mergeSort(arr,0,8);

  for(int i=0; i<arraySize; i++)
  {
    printf("%d\n", arr[i]);
  }
  return 0;
}