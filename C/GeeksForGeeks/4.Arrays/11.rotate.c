#include <stdio.h>

void rotate(int arr[], int size, int d)
{
  int temp[size];
  int i;

  for(i=0; i<size-d; i++)
    temp[i] = arr[i+d];
  
  for(int x=0; x<d; x++)
    temp[i+x] = arr[x];
  
  for(int k=0; k<size; k++)
    arr[k] = temp[k];
}

int main (void)
{
  int arr[] = {1,2,3,4,5,6,7};
  rotate(arr, 7, 3);

  for(int i=0; i<7; i++)
    printf("%d ", arr[i]);
  printf("\n");
  
  return 0;
}