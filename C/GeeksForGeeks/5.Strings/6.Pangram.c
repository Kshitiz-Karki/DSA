#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
  char s[] = "The quick brown fox jumps over dog";

  int lookUp[26] = {0};

  for(int i=0; i<strlen(s); i++)
    if(s[i] != ' ')
      lookUp[tolower(s[i]) - 97]++;
  
  int i;
  for(i=0; i<26; i++)
    if(lookUp[i] == 0)
      break;
  
  if(i == 26)
    printf("Is a pangram\n");
  else
    printf("Is not a pangram\n");
  return 0;
}