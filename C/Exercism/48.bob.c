#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_escape_sequence(int ch)
{
  if(ch == 10 || ch == 13 || ch == 9)
    return 1;
  return 0;
}

char *hey_bob(char *greeting)
{
  int len = strlen(greeting), is_all_caps = 1, has_char = 0, only_whitespace = 1, count = 0, is_question = 0;
  for (int i=0; i<len; i++)
  {
    if(isalpha(greeting[i]) && !is_escape_sequence(greeting[i]))
      has_char = 1;
    if((isalpha(greeting[i]) &&  !(greeting[i] >= 65 && greeting[i] <= 90) ) || is_escape_sequence(greeting[i]))
      is_all_caps = 0;
    if(greeting[i] != 32)
      only_whitespace = 0;
    if(greeting[i] == ' ' || is_escape_sequence(greeting[i]))
      count++;
    if(greeting[i] == '?' && i != len-1)
    {
      for(int j=i+1; j<len; j++)
        is_question = greeting[j] == ' ' ? 1 : 0;   
      break;
    }
  }
  if(only_whitespace || strcmp(greeting, "") == 0 || count == len)
    return "Fine. Be that way!";
  else if(is_all_caps && has_char && greeting[len-1] == '?')
    return "Calm down, I know what I'm doing!";
  else if(is_all_caps && has_char && greeting[len-1] != '?')
    return "Whoa, chill out!";
  else if(greeting[len-1] == '?' || is_question)
    return "Sure.";
  return "Whatever.";
}

int main (void)
{
  // char *greeting = "Okay if like my  spacebar  quite a bit?   ";
  char *greeting = "Ending with ? means a question.";
  char *result = hey_bob(greeting);
  printf("result - %s\n", result);
  return 0;
}