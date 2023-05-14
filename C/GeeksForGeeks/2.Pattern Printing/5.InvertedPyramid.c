#include <stdio.h>

int main (void)
{
  int size;
  printf("Enter pyramid size: ");
  scanf("%d", &size);

  for(int i=0; i<size; i++)
  {
    for(int k=0; k<i; k++)
      printf("  ");
    
    for(int j=0; j<size-i; j++)
      printf("* ");

    for(int p=1; p<size-i; p++)
      printf("* ");

    printf("\n");
  }
}