#include <stdio.h>
#include <string.h>

int main (void)
{
  char s1[] = "help";
  char s2[] = "held";

  int i=0;
  int j=0;
  int found=0;

  while(i < strlen(s1) && j < strlen(s2))
  {
    if(s1[i]-97 > s2[i]-97)
    {
      printf("string1\n");
      found = 1;
      break;
    }
      
    if(s1[i]-97 < s2[i]-97)
    {
      printf("string2\n");
      found = 1;
      break;
    }
    i++;j++;
  }
  
  if(found == 0)
  {
    for(;i<strlen(s1); i++)
    {
      printf("string1\n");
      break;
    }

    for(;j<strlen(s2); j++)
    {
      printf("string2\n");
      break;
    }
  }
  
  return 0;
}