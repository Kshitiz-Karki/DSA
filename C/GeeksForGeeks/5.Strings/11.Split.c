// Splits str[] according to given delimiters.
// and returns next token. It needs to be called
// in a loop to get all tokens. It returns NULL
// when there are no more tokens.

//char * strtok(char str[], const char *delims);

#include <stdio.h>
#include <string.h>

int main (void)
{
  char str[] = "Hello,world!,KK";

  char *token = strtok(str, ",");

  while(token != NULL)
  {
    printf("%s\n", token);
    token = strtok(NULL, ",");
  }
  return 0;
}