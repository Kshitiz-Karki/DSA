#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *sentence)
{
  if(!sentence) return false;
  int buffer[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  char current_char;
  for(size_t i=0; i<strlen(sentence); i++)
  {
    current_char = toupper(sentence[i]);
    if(current_char >= 65 && current_char <= 90)
      buffer[current_char - 65] += 1;
  }
  for(int i=0; i<26; i++)
  {
    if(buffer[i] == 0)
      return false;
  }
  return true;
}

int main(void)
{
  const char sentence[] = "abcdefghijklmnopqrstuvwxyz";
  // is_pangram(sentence);
  printf("%d\n", is_pangram(sentence));
  return 0;
}