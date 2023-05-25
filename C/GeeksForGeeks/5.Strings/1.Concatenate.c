#include <stdio.h>
#include <string.h>

int main (void)
{
  char str1[] = "hello";
  char str2[] = "world!";

  int len1 = strlen(str1);
  int len2 = strlen(str2);

  int newLen = len1+len2+1;
  char str3[newLen];

  int i=0; 
  int j=0;
  while(str1[i] != '\0')
  {
    str3[i] = str1[i];
    i++; j++;
  }
  i=0;
  while(str2[i] != '\0')
  {
    str3[j] = str2[i];
    i++;j++;
  }

  str3[j] = '\0';

  printf("Concatenated string - %s\n", str3);
  return 0;
}