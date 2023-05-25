// #include <stdio.h>
// #include <string.h>
// //Given an array (or string), the task is to reverse the array/string.
// int main (void)
// {
//   // int arr[] = {1,2,3};             
//   // int size = sizeof(arr)/sizeof(int);
//   char arr[] = "hello!";
//   int size = strlen(arr);
//   int temp[size];
//   int k=0;

//   for(int i=size-1; i>=0; i--)
//     temp[k++] = arr[i];

//   for(int i=0; i<size; i++)
//     arr[i] = temp[i];
  
//   printf("%s\n", arr);
  
//   // for(int i=0; i<size; i++)
//     // printf("%d ", arr[i]);
//   // printf("\n");

//   return 0;
// }


//Using recursion
#include <stdio.h>
#include <string.h>
//Given an array (or string), the task is to reverse the array/string.

// void reverse(int arr[], int start, int end)
// {
//   int temp=0;
//   if(start < end)
//   {
//     temp = arr[end];
//     arr[end] = arr[start];
//     arr[start] = temp;
//     reverse(arr, start+1, end-1);
//   }
// }

// int main (void)
// {
//   int arr[] = {1,2,3};             
//   int size = sizeof(arr)/sizeof(int);

//   reverse(arr, 0, 2);
  
//   for(int i=0; i<size; i++)
//     printf("%d ", arr[i]);
//   printf("\n");

//   return 0;
// }


//reverse string
void reverse(char s[], int start, int end)
{
  int temp=0;
  if(start < end)
  {
    temp = s[end];
    s[end] = s[start];
    s[start] = temp;
    reverse(s, start+1, end-1);
  }
}

int main (void)
{
  char s[] = "hello!"; 
  int size = strlen(s);

  reverse(s, 0, size-1);
  
  printf("%s\n", s);

  return 0;
}