#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **arr, int n)
{
  //bubble Sort
  char *temp = malloc(50 * sizeof(char));
  for(int i=n-1; i>=0; i--) 
  {
    for(int j=0; j<i; j++)
    {
      if(strcmp(arr[j], arr[j+1]) > 0)
      {
        
        strcpy(temp, arr[j+1]);
        strcpy(arr[j+1], arr[j]);
        strcpy(arr[j], temp);
      }
    }
  }
  free(temp);
}

int main (void)
{
  int n;
  printf("Enter number of strings to be sorted: ");
  scanf("%d", &n);

  char **strings = malloc(n * sizeof(char *));
  
  for(int i=0; i<n; i++)
  {
    strings[i] = malloc(50 * sizeof(char));
    scanf("%s", strings[i]);
  }

  sort(strings, n);
  
  printf("######################\n");
  for(int i=0; i<n; i++)
    printf("%s\n", strings[i]);

  for(int i=0; i<n; i++)
    free(strings[i]);

  free(strings);

  return 0;
}