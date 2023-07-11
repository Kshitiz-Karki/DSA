#include <stdio.h>
#include <string.h>

#define MAX_SIZE 16

char *convert(char result[], int drops)
{
  if(drops % 3 == 0)
    strcat(result, "Pling");
  if(drops % 5 == 0)
    strcat(result, "Plang");
  if(drops % 7 == 0)
    strcat(result, "Plong");
  if(drops % 3 != 0 && drops % 5 != 0 && drops % 7 != 0)
    sprintf(result, "%d", drops);

  int len = strlen(result);
  result[len] = '\0';
  return result;
}

int main (void)
{
  int drops = 15;
  char result[MAX_SIZE];
  char *rain_drops = convert(result, drops);
  printf("%s\n", rain_drops);
  return 0;
}