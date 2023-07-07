#include <stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubble(int A[], int size)
{
  int no_swap = 0;
  for(int i=size-1; i>0; i--)
  {
    no_swap = 0;
    for(int j=0; j<i; j++)
    {
      if(A[j] > A[j+1])
      {
        swap(&A[j], &A[j+1]);
        no_swap = 1;
      }
    }
    if(!no_swap) break; //return;
  }
}

void insertion(int A[], int size)
{
  int j, current_elem = 0;
  for(int i=1; i<size; i++)
  {
    j=i-1;
    current_elem = A[i];
    while(j>=0 && A[j] > current_elem)
    {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = current_elem;
  }
}

void selection(int A[], int size)
{
  int i, j, k;
  for(i=0; i<size-1; i++)
  {
    for(j=k=i; j<size; j++)
    {
      if(A[j] < A[k])
        k=j;
    }
    if(k != i)
      swap(&A[k], &A[i]);
  }

}

int main(void)
{
  int A[] = {4, 2, -1, 0, 10, 9, 20, 15, 11};
  int size = sizeof(A)/sizeof(int);

  // bubble(A, size);
  // insertion(A, size);
  selection(A, size);

  for(int i=0; i<size; i++)
    printf("%d  ", A[i]);
  printf("\n");

  return 0;
}