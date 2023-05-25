#include <stdio.h>
#include <string.h>

int main (void)
{
  char num[] = "001234";

  int i = 0;
  while(num[i] == '0')
    i++;
  
  int k=0;
  for(;i<strlen(num); i++)
    num[k++] = num[i];
  
  num[k] = '\0';

  printf("%s\n", num);
  


  return 0;
}