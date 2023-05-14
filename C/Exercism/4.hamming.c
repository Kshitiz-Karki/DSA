#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
  if(strlen(lhs) != strlen(rhs))
    return -1;

  int count = 0;
  
  for(int i=0; lhs[i] != '\0'; i++)
  {
    if(lhs[i] != rhs[i])
      count++;
  }
  return count;
}

int main (void)
{
  printf("%d\n", compute("GAGCCTACTAACGGGAT", "CATCGTAATGACGGCCT"));
  return 0;
}