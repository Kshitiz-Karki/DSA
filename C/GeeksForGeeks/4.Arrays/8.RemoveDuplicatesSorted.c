// #include <stdio.h>

// int removeDuplicate(int arr[], int size)
// {
//   int temp[size];
//   int k=0;
//   for(int i=0; i<size-1; i++)
//   {
//     if(arr[i] != arr[i+1])
//       temp[k++] = arr[i];
//   }
//   temp[k] = arr[size-1];
  
//   for(int i=0; i<=k; i++)
//     arr[i] = temp[i];
  
//   return k;
// }

// int main (void)
// {
//   int arr[] = {1,2,2,4,5,5,5,6,9,9,10};
//   int size = sizeof(arr)/sizeof(int);

//   int newSize = removeDuplicate(arr, size);

//   for(int i=0; i<=newSize; i++)
//     printf("%d\n", arr[i]);

//   return 0;
// }

//
#include <stdio.h>
#include <stdlib.h>

int removeDuplicate(int arr[], int size, int temp[])
{
  int k=0;
  for(int i=0; i<size-1; i++)
  {
    if(arr[i] != arr[i+1])
      temp[k++] = arr[i];
  }
  temp[k] = arr[size-1];
  return k;
}

int main (void)
{
  int size = 11;
  int *arr = malloc(size * sizeof(int));
  int *temp = malloc(size * sizeof(int));

  printf("Enter array elements: \n");
  for(int i=0; i<size; i++)
    scanf("%d", &arr[i]);

  printf("#####################################\n");

  int newSize = removeDuplicate(arr, size, temp);

  arr = realloc(arr, (newSize+1)*sizeof(int));
  
  for(int i=0; i<=newSize; i++)
  {
    arr[i] = temp[i];
    printf("%d\n", arr[i]);
  }
  free(temp);
  //////here u can make use of arr[].....................
  free(arr);
  return 0;
}