// #include <stdio.h>

// int removeDups(int arr[], int size)
// {
//   int temp[size];
//   int newSize = 0;

//   for(int i=0; i<size; i++)
//     temp[i] = 0;

//   for(int i=0; i<size; i++)
//     temp[arr[i]]++;

//   for(int i=0; i<size; i++)
//   {
//     if(temp[i] == 1)
//       arr[newSize++] = i;
//   }
//   return newSize;
// }

// int main (void)
// {
//   int arr[] = {1,2,1,3,1, 2};
//   int size = sizeof(arr)/sizeof(int);
//   int newSize = removeDups(arr, size);

//   for(int i=0; i<newSize; i++)
//     printf("%d\n", arr[i]);

//   return 0;
// }

#include <stdio.h>

int removeDups(int arr[], int value, int size)
{
  int temp[size];
  int newSize = 0;

  for(int i=0; i<size; i++)
  {
    if(arr[i] != value)
      temp[newSize++] = arr[i];
  }

  for(int i=0; i<newSize; i++)
    arr[i] = temp[i];

  return newSize;
}

int main (void)
{
  int arr[] = {1,2,1,3,-1, 2};
  int size = sizeof(arr)/sizeof(int);
  int newSize = removeDups(arr, -1, size);

  for(int i=0; i<newSize; i++)
    printf("%d\n", arr[i]);

  return 0;
}