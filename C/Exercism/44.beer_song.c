#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

char *bottle_or_bottles(uint8_t start_bottles)
{
  char *bottle = start_bottles == 1 ? "bottle" : "bottles"; 
  return bottle; 
}

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
  int i=0; 
  char *bottle;
  for(int j=0; j<take_down; j++)
    {
      if(start_bottles == 0)
      {
        sprintf(song[i++], "No more bottles of beer on the wall, no more bottles of beer.");
        sprintf(song[i++], "Go to the store and buy some more, 99 bottles of beer on the wall.");
        return;
      }

      bottle = bottle_or_bottles(start_bottles);
      sprintf(song[i++], "%u %s of beer on the wall, %u %s of beer.", start_bottles, bottle, start_bottles, bottle);

      start_bottles--;
      bottle = bottle_or_bottles(start_bottles);

      if(start_bottles == 0)
        sprintf(song[i++], "Take it down and pass it around, no more bottles of beer on the wall.");
      else
        sprintf(song[i++], "Take one down and pass it around, %u %s of beer on the wall.", start_bottles, bottle);
      
      if(take_down > 1 && i < (take_down * 2 + (take_down - 1)))
        strcat(song[i++], "");
    }
}

int main (void)
{
  char **actual_song = calloc(MAX_LINE_COUNT, sizeof(*actual_song));
  for (size_t i = 0; i < MAX_LINE_COUNT; ++i)
    actual_song[i] = calloc(MAX_LINE_LENGTH, sizeof(**actual_song));

  uint8_t take_down = 100;
  recite(99, take_down, actual_song);
  for(int i=0; i<(take_down * 2 + (take_down - 1)); i++)
  {
    printf("%s\n", actual_song[i]);
  }
  return 0;
}