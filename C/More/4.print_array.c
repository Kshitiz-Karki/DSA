#include <stdio.h>

void print_array_left(int *arr, int size)
{
  if(size == 0)
    return;
  printf("%d ", *arr);
  print_array_left(arr + 1, size-1);
}

void print_array_right(int *arr, int size)
{
  if(size == 0)
    return;
  printf("%d ", *(arr+size-1));
  print_array_right(arr, size-1);
}

int main(void)
{
  int arr[] = {4, 3, 7, 9, 10};
  // print_array_left(arr, 5);
  print_array_right(arr, 5);
  return 0;
}