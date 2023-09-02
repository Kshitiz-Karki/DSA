#include <stdio.h>
#include <string.h>
#include <ctype.h>

int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

unsigned int score(const char *word);

int main (void)
{
  unsigned total_points = score("cabbage");
  printf("total_points - %u\n", total_points);
  return 0;
}

unsigned int score(const char *word)
{
  unsigned int total_points = 0;
  char current_char = '\0';
  for(size_t i=0; i<strlen(word); i++)
  {
    current_char = tolower(word[i]);
    total_points += points[current_char-97];
  }
  return total_points;
}