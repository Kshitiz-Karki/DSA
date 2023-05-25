#include <stdio.h>
#include <string.h>

int main (void)
{
  char s[] = "Geeks for Geeks";

  printf("%c ", s[0]);
  for(int i=1; i<strlen(s); i++)
  {
    if(s[i] == ' ')
      printf("%c ", s[i+1]);
  }
  printf("\n");
  return 0;
}