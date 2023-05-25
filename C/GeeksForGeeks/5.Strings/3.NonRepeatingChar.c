#include <stdio.h>
#include <string.h>
//Given a string S consisting of lowercase Latin Letters, the task is to find the first non-repeating character in S.
int main(void)
{
  char S[] = "geeksforgeeks";

  int lookUp[26] = {0};

  for(int i=0; i<strlen(S); i++)
    lookUp[S[i] - 97]++;
  
  int i;
  for(i=0; i<26; i++)
  {
    if(lookUp[i] == 1)
    {
      printf("First non-repeating character is %c\n", 97+i);
      break;
    }
  }
  if(i == 26)
    printf("All characters are repeating atleast once!!\n");
  return 0;
  
}