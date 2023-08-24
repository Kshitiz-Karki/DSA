#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
   int value;
   const char *keys;
} legacy_map;

typedef struct {
   char key;
   int value;
} new_map;

int convert(const legacy_map *input, const size_t input_len, new_map **output);

int main(void)
{
  // legacy_map input[] = { { 1, "AEIOU" } };
   legacy_map input[] = { { 1, "AE" }, { 2, "DG" } };
  size_t input_len = 2;
  new_map *output = NULL;
  int new_len = convert(input, input_len, &output);
  printf("new_len - %d\n", new_len);
  for(int i=0; i<new_len; i++)
  {
    printf("%c - %d\n", output[i].key, output[i].value);
  }
  free(output);
  return 0;
}

int convert(const legacy_map *input, const size_t input_len, new_map **output)
{
  int total_keys = 0;
  int current_key_len = 0;
  //determine the lenth of the output
  for(size_t i=0; i<input_len; i++)
  {
    current_key_len = strlen(input[i].keys);
    total_keys += current_key_len;
  }
  //create an array of new map and assign the address to output
  *output = (new_map *)calloc(total_keys, sizeof(new_map));
  //map points for each character of alphabets from a-z
  int k=0;
  int alpha_map[26] = {0};
  for(size_t i=0; i<input_len; i++)
  {
    current_key_len = strlen(input[i].keys);
    for(int j=0; j<current_key_len; j++)
      alpha_map[tolower(input[i].keys[j])-97] = input[i].value;
  }
  //update output with key-value pair for a-z where points > 0
  for(int i=0; i<26; i++)
  {
    if(alpha_map[i] > 0)
    {
       (*output+k)->key = (char)i+97;
      (*output+k++)->value = alpha_map[i];
      // alternately:
      // (*output)[k].key = (char)i+97;
      // (*output)[k++].value = alpha_map[i];
    }
  }
  return total_keys;
}