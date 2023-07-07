#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char *abbreviate(const char *phrase)
{
  if(!phrase || *phrase == 0 ) return NULL;
  int new_size = 0;
  size_t len = strlen(phrase);
  for(size_t i=0; i<len-1; i++)
  {
    if((phrase[i] == ' ' || phrase[i] == '-') && phrase[i+1] != ' ' && phrase[i+1] != '-')
      new_size++;
  }

  char *acronym = (char *)malloc(sizeof(char) * (new_size+2));

  bool is_first_letter = true;
  int j=0;
  for(size_t i=0; i<len-1; i++)
  {
    if(is_first_letter) 
    {
      char current_letter = toupper(phrase[i]);
      while(current_letter < 65 || current_letter > 90)
        current_letter = toupper(phrase[i++]);
      acronym[j++] = current_letter;
      is_first_letter = false;
    }
    else
    {
      if((phrase[i] == ' ' || phrase[i] == '-') && phrase[i+1] != ' ' && phrase[i+1] != '-')
        is_first_letter = true;
    }
  }
  acronym[j] = '\0';
  return acronym;
}

int main(void)
{
  // char *phrase = "Something - I made up from thin air";
  char *phrase = NULL;
  // char *phrase = "The Road _Not_ Taken";
  char *acronym = abbreviate(phrase);
  // printf("%s\n", acronym);
  free(acronym);
  return 0;
}

