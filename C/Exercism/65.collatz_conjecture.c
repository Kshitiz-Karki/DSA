#include <stdio.h>

#define ERROR_VALUE -1

int steps(int start);

int main(void)
{
  printf("steps - %d\n", steps(12));
  return 0;
}

int steps(int start)
{
  if (start < 1) return ERROR_VALUE;
  int i=0;
  while(start != 1)
  {
    if(start % 2 == 0) //check if start is even
    {
      start /= 2;
    }
    else
    {
      start = 3*start + 1;
    }
    i++;
  }
  return i;
}