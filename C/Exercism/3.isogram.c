#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_isogram(const char phrase[])
{
  if(phrase == NULL)
    return false;
  int hashTable[26] = {0};

  for(int i=0; phrase[i] != '\0'; i++)
  {
    char upper = (int) toupper(phrase[i]);
    if(upper >= 65 && upper <= 90)
      hashTable[upper-65]++;
  }

  for(int i=0; i<=25; i++)
  {
    if(hashTable[i] > 1)
      return false;
  }
  return true;
}

int main (void)
{

  printf("Is isogram - %d\n", is_isogram(NULL));
  return 0;
}