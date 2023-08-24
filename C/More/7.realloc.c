#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int*grades = NULL;
  int*temp = NULL;
  int total_grades = 5;
  grades = (int *) calloc(total_grades, sizeof(int));
  total_grades += 2;
  temp = (int *) realloc(grades, total_grades*sizeof(int));  
  if(temp)
    grades = temp;
  free(grades);
  return 0;
}