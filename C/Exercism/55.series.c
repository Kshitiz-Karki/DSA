#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_TEXT_LENGTH (8)
#define MAX_SERIES_RESULTS (MAX_INPUT_TEXT_LENGTH)
#define MAX_SERIES_LENGTH (5)

// results structure
typedef struct slices {
   unsigned int substring_count;
   char **substring;   // array of pointers of dimension substring_count
} slices_t;

// slices - routine to slice up input text into consecutive substrings of text
// of a given substring_length
//
// inputs:
//    input_text - bounded to MAX_INPUT_TEXT_LENGTH
//    substring_length - the desired length of substrings that are returned
//    bounded to MAX_SERIES_LENGTH
//
// outputs:
//    slices_t results - structure containing count of the substrings and an
//    array of
//       pointers to the substrings.
//
//       Calling routine will free memory associated with each of the substrings
//       and the pointers to the substrings.
slices_t slices(char *input_text, unsigned int substring_length);

int main(void)
{
  char *input = "918493904243";
  unsigned int len = 5;
  slices_t result = slices(input, len);
  printf("substring_count - %d\n", result.substring_count);
  printf("substring - ");
  for(unsigned int i=0; i<result.substring_count; i++)
  {
    printf("%s ", result.substring[1]);
  }
  return 0;
}

slices_t slices(char *input_text, unsigned int substring_length)
{
  unsigned int len = strlen(input_text);
  if (len < substring_length || substring_length == 0) return (slices_t){0, NULL};
  unsigned int size = len-substring_length+1; 
  slices_t result = { size, calloc(size, sizeof(char *))};
  for(unsigned int i=0; i<size; i++)
  {
    result.substring[i] = calloc(substring_length+1, sizeof(char));
    strncpy(result.substring[i], input_text++, substring_length);
  }
  return result;
}