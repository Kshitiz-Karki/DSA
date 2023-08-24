#include <stdio.h>
#include <stdlib.h>

int * create_array(int size)
{
  int *arr = (int *) malloc(size * sizeof(int));
  for(int i=0; i<size; i++)
    arr[i] = i;
  return arr;
}
int main(void)
{
  int size = 5;
  int *arr1 = create_array(size);
  for(int i=0; i<size; i++)
    printf("%d ", arr1[i]);
  free(arr1);
  return 0;

}