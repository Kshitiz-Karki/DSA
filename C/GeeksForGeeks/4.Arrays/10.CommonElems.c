// #include <stdio.h>

// void commonElems(int arr1[], int size1, int arr2[], int size2)
// {
//   int newSize = size1 < size2 ? size1 : size2;
//   int i = 0;
//   int j = 0;
//   int k = 0;
//   int temp[newSize];
  
//   while(i < size1 && j < size2)
//   {
//     if(arr1[i] < arr2[j])
//       i++;
//     else if(arr1[i] > arr2[j])
//       j++;
//     else
//     {
//       // printf("%d ", arr1[i]);
//       temp[k++] = arr1[i];
//       i++;
//       j++;
//     }
//   }
  
//   for(int x=0; x<k; x++)
//     printf("%d ", temp[x]);
  
//   printf("\n");


// }

// void merge(int arr[], int left, int mid, int right)
// { 
//   int i = left;
//   int j = mid+1;
//   int k = left;

//   int temp[right+1];

//   while(i <= mid && j <= right)
//   {
//     if(arr[i] < arr[j])
//       temp[k++] = arr[i++];
//     else
//       temp[k++] = arr[j++];
//   }

//   for(; i<=mid; i++)
//     temp[k++] = arr[i];

//   for(; j<=right; j++)
//     temp[k++] = arr[j];

//   for(int x=left; x<=right; x++)
//     arr[x] = temp[x];

// }

// void mergeSort(int arr[], int left, int right)
// {
//   int mid;
//   if (left < right)
//   {
//     mid = (left + right)/2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid+1, right);
//     merge(arr, left, mid, right);
//   }
// }

// int main (void)
// {
//   int arr1[] = {8, 2, 3, 4, 5, 6, 7, 1};
//   int arr2[] = {4, 5, 7, 11, 6, 1};
//   int size1 = sizeof(arr1)/sizeof(int);
//   int size2 = sizeof(arr2)/sizeof(int);

//   int temp1[size1];
//   int temp2[size2];

//   for(int i=0; i<size1; i++)
//     temp1[i] = arr1[i];
  
//   for(int i=0; i<size2; i++)
//     temp2[i] = arr2[i];

//   mergeSort(temp1, 0 , size1-1);
//   mergeSort(temp2, 0 , size2-1);

//   commonElems(temp1, size1, temp2, size2);

//   // for(int i=0; i<size1; i++)
//   //   printf("%d ", temp1[i]);
  
//   // printf("\n");

//   // printf("###########################\n");

//   // for(int i=0; i<size2; i++)
//   //   printf("%d ", temp2[i]);

//   // printf("\n");

//   return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Array
// {
//   int *p;
//   int size;
// };

// int *commonElems(int arr1[], int size1, int arr2[], int size2, int newSize)
// {
//   int i = 0;
//   int j = 0;
//   int k = 0;

//   int *temp = malloc(newSize * sizeof(int));
  
//   while(i < size1 && j < size2)
//   {
//     if(arr1[i] < arr2[j])
//       i++;
//     else if(arr1[i] > arr2[j])
//       j++;
//     else
//     {
//       // printf("%d ", arr1[i]);
//       temp[k++] = arr1[i];
//       i++;
//       j++;
//     }
//   }
  
//   // for(int x=0; x<k; x++)
//   //   printf("%d ", temp[x]);
  
//   // printf("\n");
//   return temp;


// }

// void merge(int arr[], int left, int mid, int right)
// { 
//   int i = left;
//   int j = mid+1;
//   int k = left;

//   int temp[right+1];

//   while(i <= mid && j <= right)
//   {
//     if(arr[i] < arr[j])
//       temp[k++] = arr[i++];
//     else
//       temp[k++] = arr[j++];
//   }

//   for(; i<=mid; i++)
//     temp[k++] = arr[i];

//   for(; j<=right; j++)
//     temp[k++] = arr[j];

//   for(int x=left; x<=right; x++)
//     arr[x] = temp[x];

// }

// void mergeSort(int arr[], int left, int right)
// {
//   int mid;
//   if (left < right)
//   {
//     mid = (left + right)/2;
//     mergeSort(arr, left, mid);
//     mergeSort(arr, mid+1, right);
//     merge(arr, left, mid, right);
//   }
// }

// int main (void)
// {
//   int arr1[] = {8, 2, 3, 4, 5, 6, 7, 1};
//   int arr2[] = {4, 5, 7, 11, 6, 1};
//   int size1 = sizeof(arr1)/sizeof(int);
//   int size2 = sizeof(arr2)/sizeof(int);

//   int temp1[size1];
//   int temp2[size2];

//   for(int i=0; i<size1; i++)
//     temp1[i] = arr1[i];
  
//   for(int i=0; i<size2; i++)
//     temp2[i] = arr2[i];

//   mergeSort(temp1, 0 , size1-1);
//   mergeSort(temp2, 0 , size2-1);

//   int newSize = size1 < size2 ? size1 : size2;

//   int *p = commonElems(temp1, size1, temp2, size2, newSize);

//   // for(int i=0; i<size1; i++)
//   //   printf("%d ", temp1[i]);
  
//   // printf("\n");

//   // printf("###########################\n");

//   for(int i=0; i<newSize; i++)
//     printf("%d ", p[i]);

//   printf("\n");

//   free(p);
//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Array
{
  int *p;
  int size;
};

struct Array *commonElems(int arr1[], int size1, int arr2[], int size2, int newSize)
{
  int i = 0;
  int j = 0;
  int k = 0;

   struct Array *temp = malloc(sizeof(struct Array));
   temp->p = malloc(newSize * sizeof(int));
  
  while(i < size1 && j < size2)
  {
    if(arr1[i] < arr2[j])
      i++;
    else if(arr1[i] > arr2[j])
      j++;
    else
    {
      // printf("%d ", arr1[i]);
      temp->p[k++] = arr1[i];
      i++;
      j++;
    }
  }
  
  // for(int x=0; x<k; x++)
  //   printf("%d ", temp[x]);
  
  // printf("\n");
  temp->size = k;
  return temp;


}

void merge(int arr[], int left, int mid, int right)
{ 
  int i = left;
  int j = mid+1;
  int k = left;

  int temp[right+1];

  while(i <= mid && j <= right)
  {
    if(arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }

  for(; i<=mid; i++)
    temp[k++] = arr[i];

  for(; j<=right; j++)
    temp[k++] = arr[j];

  for(int x=left; x<=right; x++)
    arr[x] = temp[x];

}

void mergeSort(int arr[], int left, int right)
{
  int mid;
  if (left < right)
  {
    mid = (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

int main (void)
{
  int arr1[] = {8, 2, 3, 4, 5, 6, 7, 1};
  int arr2[] = {4, 5, 7, 11, 6, 1};
  int size1 = sizeof(arr1)/sizeof(int);
  int size2 = sizeof(arr2)/sizeof(int);

  int temp1[size1];
  int temp2[size2];

  for(int i=0; i<size1; i++)
    temp1[i] = arr1[i];
  
  for(int i=0; i<size2; i++)
    temp2[i] = arr2[i];

  mergeSort(temp1, 0 , size1-1);
  mergeSort(temp2, 0 , size2-1);

  int newSize = size1 < size2 ? size1 : size2;

  struct Array *arr = commonElems(temp1, size1, temp2, size2, newSize);

  // for(int i=0; i<size1; i++)
  //   printf("%d ", temp1[i]);
  
  // printf("\n");

  // printf("###########################\n");

  for(int i=0; i<arr->size; i++)
    printf("%d ", arr->p[i]);

  printf("\n");

  free(arr->p);
  free(arr);
  return 0;
}