#include <stdio.h>
#include <string.h>

void two_fer(char *buffer, const char *name)
{
  if(name == NULL)
    strcpy(buffer, "One for you, one for me.");
  else
  {
    strcpy(buffer, "One for ");
    strcat(buffer, name);
    strcat(buffer, ", one for me.");
  }
}

int main (void)
{

  return 0;
}