#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BYTES_SIZE 52

char **make_diamond(const char letter);
void free_diamond(char **diamond);

int main(void)
{
  char letter = 'B';
  char **diamond = make_diamond(letter);
  for(int i=0; i<2*(letter-64)-1; i++)
    printf("%s\n", diamond[i]);
  free_diamond(diamond);
  return 0;
}

char **make_diamond(const char letter)
{
  char **diamond = (char **)calloc(2*(letter-64)-1, sizeof(char *));
  char *diamod_row = NULL;
  int space_left = letter - 65;
  int space_right = letter - 65;
  int space_middle = 1;
  int current_char = '\0';
  int idx = 0;
  char char_str[2];
  char_str[1] = '\0';
  //printf upper half of diamond
  for(int i=64; i<letter; i++)
  {
    current_char = i+1;
    char_str[0] = current_char;
    diamod_row = (char *)calloc(BYTES_SIZE, sizeof(char));
    for(int j=0; j<space_left; j++)
      strcat(diamod_row, " ");
    strcat(diamod_row, char_str);
    if(current_char > 65)
    {
      for(int k=0; k<space_middle; k++)
        strcat(diamod_row, " ");
      space_middle += 2;
      strcat(diamod_row, char_str);
    }
    for(int n=0; n<space_right; n++)
      strcat(diamod_row, " ");
    space_left--;
    space_right--;
    diamond[idx++] = diamod_row;
  }
  //printf lower half of diamond
  for(int x=idx-2; x>=0; x--)
  {
    diamod_row = (char *)calloc(BYTES_SIZE, sizeof(char));
    strcpy(diamod_row, diamond[x]);
    diamond[idx++] = diamod_row;
  }
  return diamond;
}

void free_diamond(char **diamond)
{
  int i=0;
  while(diamond[i] && i<51)
    free(diamond[i++]);
  free(diamond);
}