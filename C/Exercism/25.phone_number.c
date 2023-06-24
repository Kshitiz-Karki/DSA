#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *phone_number_clean(const char *input)
{
  int i=0;
  int len = strlen(input);
  char *prefix = "+1";
  char *expected = (char *)malloc(sizeof(char) * 12); // 12 beacause max lenth possible is 11 and 12th index is for \0
  if(len > 10)
  {
    if(input[0] == '1')
      i = 1;
    if(strncmp(prefix, input, 2) == 0)
      i = 2;
  } 
  else
    return strcpy(expected, "0000000000");

  int j=0;
  for(; i<len; i++)
  {
    if(input[i] >= 48 && input[i] <= 57)
      expected[j++] = input[i];
  }
  expected[j] = '\0';
  return strlen(expected) == 10 && !(expected[0] <= '1') && !(expected[3] <= '1') ? expected : strcpy(expected, "0000000000");
}

int main (void)
{
  const char input[] = "1 (123) 156-789";
   char *expected = phone_number_clean(input);
  // printf("%s\n", phone_number_clean(input));
  free(expected);
  return 0;
}