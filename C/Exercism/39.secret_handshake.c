// #include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <math.h>

#define NR_OF_ACTIONS 4

const char **commands(size_t number)
{
  char *actions[NR_OF_ACTIONS] = {"wink", "double blink", "close your eyes", "jump"};
  const char **result = (const char **)malloc(sizeof(char *) * NR_OF_ACTIONS);
  int j=0;

  if((size_t) pow(2, NR_OF_ACTIONS) & number)
  {
    for(int i=NR_OF_ACTIONS-1; i>=0; i--)
      if((size_t) pow(2, i) & number)
        result[j++] = actions[i];
  }
  else
  {
    for(int i=0; i<NR_OF_ACTIONS; i++)
      if((size_t) pow(2, i) & number)
        result[j++] = actions[i];
  }
  result[j] = '\0';
  return result;
}

int main(void)
{
  const char **result =  commands(9);
  for(int i=0; result[i]; i++)
  {
    printf("%s\n", result[i]);
  }
  free(result);
  return 0; 
}
