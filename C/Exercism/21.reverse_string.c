#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(const char *value)
{
  if(!value) return NULL;
  int len = strlen(value);
  char *reversed = (char *)malloc((len+1) * sizeof(char));
  for(int i=0; i<len; i++)
    reversed[len-i-1] = value[i];
  reversed[len] = '\0';
  return reversed;
}

// char *reverse(const char *value)
// {
//   if(!value) return NULL;
//   int len = strlen(value);
//   char *reversed = (char *)malloc(len * sizeof(char));
//   for(reversed += len; *value; value++)
//     *(--reversed) = *value;
//   return reversed;
// }

int main(void)
{
  const char *s = "reward";
  char *reversed = reverse(s);
  printf("%s\n", reversed);
  free(reversed);
  return 0;
}