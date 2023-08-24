#include <stdio.h>

void swap(char *a, char *b)
{
  char temp = '\0';
  temp = *a;
  *a = *b;
  *b = temp;
}

void reverse(char arr[], int size)
{
  int x=0;
  int y=size-1;
  while(x < y)
  {
    swap(&arr[x++], &arr[y--]);
  }
}
void reverse_recursive(char *arr, int size)
{           
  if(size > 1)
  {
    // swap(&arr[0], &arr[size-1]);
    swap(arr, arr + size-1);  //using pointer arithmetic
    reverse_recursive(arr+1, size-2);
  }
}

int main (void)
{
  char arr[] = "afkd";
  int size = sizeof(arr) / sizeof(arr[0]);
  // reverse(arr, size);
  reverse_recursive(arr, size);
  for(int i=0; i<size; i++)
    printf("%c ", arr[i]);
  return 0;
}