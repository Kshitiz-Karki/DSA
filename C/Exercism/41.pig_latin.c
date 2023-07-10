//optimise/make readable, by use of functions and replacing reprating/similar code statements, logic, etc
//(WHEN THERE IS ENOUGH TIME !!!!!!!!!!!!!!!! :) )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_vowel(char letter)
{
  return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}
char *translate_single_word(const char *phrase)
{
  char const *ay = "ay";
  char *pig_latin = (char *)malloc(strlen(phrase) + 7);
  if(phrase[0] == 'a' || phrase[0] == 'e' || phrase[0] == 'i' || phrase[0] == 'o' || phrase[0] == 'u' ||
  (phrase[0] == 'x' && phrase[1] == 'r') || (phrase[0] == 'y' && phrase[1] == 't'))
  {
    strcpy(pig_latin, phrase);
    strcat(pig_latin, ay);
    return pig_latin;
  }
  if(strlen(phrase) == 2 && !is_vowel(phrase[0]) && phrase[1] == 'y')
  {
    char temp[3];
    int j=0;
    for(int i=1; i>=0; i--)
      temp[j++] = phrase[i];
    temp[j] = '\0';
    strcpy(pig_latin, temp);
    strcat(pig_latin, ay);
  }
  char prefix[10];
  char suffix[10];
  if(!is_vowel(phrase[0]) && phrase[1] == 'q' && phrase[2] == 'u')
  {
    int j=0;
    for(size_t i=0; i<strlen(phrase); i++)
    {
      if(i < 3)
        suffix[i] = phrase[i];
      else
        prefix[j++] = phrase[i];
    }
    suffix[3] = '\0';
    prefix[j] = '\0';
    strcpy(pig_latin, prefix);
    strcat(pig_latin, suffix);
    strcat(pig_latin, ay);
    return pig_latin;
  }
  size_t i;
  int add_prefix = 0;
    if(strlen(phrase) != 2)
    {
      for(i=0; i<strlen(phrase)-1; i++)
      {
        if( phrase[0] == 'q' && phrase[1] == 'u')
        {
          size_t j = 0;
          for(; j<2; j++)
            suffix[j] = phrase[j];
          suffix[j] = '\0';
          i=1;
          add_prefix = 1;
          break;
        }
        if( !is_vowel(phrase[i]) && (is_vowel(phrase[i+1]) || phrase[i+1] == 'y'))
        {
          size_t j = 0;
          for(; j<=i; j++)
            suffix[j] = phrase[j];
          add_prefix = 1;
          suffix[j] = '\0';
          break;
        }
      }
    }
  if(add_prefix)
  {
    int y=0;
    for(size_t x=i+1; x<strlen(phrase); x++)
      prefix[y++] = phrase[x];
    prefix[y] = '\0';
    strcpy(pig_latin, prefix);
    strcat(pig_latin, suffix);
    strcat(pig_latin, ay);
  }
  return pig_latin;
}
char *translate(const char *phrase)
{
  const char ch = ' ';
  char *is_single_word = strchr(phrase, ch);
  if(is_single_word == NULL)
    return translate_single_word(phrase);
  char *result = (char *)malloc(strlen(phrase) + 100);
  char *word = (char *)malloc(50);
  int j=0;
  for(size_t i=0; i<strlen(phrase); i++)
  {
    if(phrase[i] == ' ' || i == strlen(phrase)-1)
    {
      if(i == strlen(phrase)-1)
        word[j++] = phrase[i];
      word[j] = '\0';
      strcat(result, translate_single_word(word));
      if(i != strlen(phrase)-1)
        strcat(result, " ");
      j=0;
    }
    else
      word[j++] = phrase[i];
  }
  return result; 
}

int main (void)
{
  // const char *phrase = "quick fast run";
  // const char *phrase = "apple";
  char *phrase = "pig";
  // char *phrase = "therapy";
  // char *phrase = "yellow";
  char *pig_latin = translate(phrase);
  printf("Pig latin - %s!!!!!\n", pig_latin);
  return 0;
}