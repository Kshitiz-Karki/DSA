#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int rows = 0;
  int columns = 0;
  int **arr = NULL;

  printf("Enter the number of rows: ");
  scanf("%d", &rows);

  arr = (int **)calloc(rows, sizeof(int *));

  for(int i=0; i<rows; i++)
  {
    printf("Enter the number of columns for row-%d: ", i+1);
    scanf("%d", &columns);

    arr[i] = (int *)calloc(columns, sizeof(int));
  }
  
  //free memory
  for(int i=0; i<rows; i++)
  {
    free(arr[i]);
  }
  free(arr);
  arr = NULL; //handle dangling pointer
  return 0;
}