#include <stdio.h>

void heapify(int A[], int size)
{
  int j=0;
  int temp = 0;
  int i = (size/2) - 1;
  for(; i>=0; i--)
  {
    j=2*i + 1;

    while(j < size-1)
    {
      if(A[j+1] > A[j])
        j=j+1;
      if(A[i] < A[j])
      {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp; 
        i=j;
        j=2*i + 1;
      }
      else
        break;
    }
  }
}

int main(void)
{
  int A[] = {5,10,30,20,35,40,15};
  int size = sizeof(A)/sizeof(int);
  heapify(A, size);

  for(int i=0; i<size; i++)
    printf("%d ", A[i]);
  
  printf("\n");
  return 0;
}