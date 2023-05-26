#include <stdio.h>
#include <string.h>
//Given two strings s1 and s2, the task is to write C program compare the two strings without using strcmp() function
int main (void)
{
  char s1[] = "geeksforgeeks";
  char s2[] = "geeksforgseks";

  int strLen1 = strlen(s1);
  int strLen2 = strlen(s2);

  int i = 0;
  if(strLen1 != strLen2)
    printf("Unequal Strings\n");
  else
  {
    while(s1[i] != '\0')
    {
      if(s1[i] != s2[i])
      {
        printf("Unequal Strings\n");
        break;
      }
      i++;
    }
    if(i == strLen1)
      printf("Equal Strings\n");
  }
  return 0;
}