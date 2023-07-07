#include <stdio.h>

void insert_heap(int A[], int i)
{
  int temp = A[i];
  while (i > 0 && temp > A[i/2])
  {
    A[i] = A[i/2];
    i = i/2;
  }
  A[i] = temp;
}

int delete(int A[], int size)
{
  int temp = 0;
  int val = A[0];
  A[0] = A[size];
  A[size] = val;
  int i=0, j=1;

  while(j<size-1)
  {
    if(A[j+1] > A[j])
      j=j+1;
    if(A[i] < A[j])
    {
      //swap
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      i=j;
      j=2*j;
    }
    else
      break;
  }
  return val;
}

int main(void)
{
  // int A[] = {2,7,26,25,19,17,1,90,3,36};
  // int A[] = {2, 7, 10, 12, 15, 90} ;
  // int A[] = {1,2,3,4,5,6,7,8,9};
  int A[] = {10,20,30,25,5,40,35};
  int size = sizeof(A)/sizeof(int);

  printf("Before - ");
  for(int i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n#################\n");

  for(int i=1; i<size; i++)
    insert_heap(A, i);
  
  // printf("Deleted value = %d\n", delete(A, size-1));
  // printf("Deleted value = %d\n", delete(A, size-2));
  
  for(int i=size-1; i>0; i--)
    delete(A, i);

  printf("After - ");
  for(int i=0; i<size; i++)
    printf("%d ", A[i]);
  printf("\n");

  return 0;
}