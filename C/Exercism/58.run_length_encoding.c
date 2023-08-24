#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define COUNT_SIZE 3
#define DECODED_STR_LEN 100

char *encode(const char *text);
char *decode(const char *data);

int main(void)
{
  // char *res = encode("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB"); //2a3b4c
  // char *res = encode("XYZ");
  // char *encoded = encode("AABBBCCCC");
  char *decoded = decode("2A3B4C");
  // char *decoded = decode("2 hs2q q2w2 ");
  // char *decoded = decode("XYZ");
  // printf("encode_res - %s\n", encoded);
  printf("decode_res - |%s|\n", decoded);
  // free(encoded);
  free(decoded);
  return 0;
}

char *encode(const char *text)
{
  int text_len = strlen(text);
  char * result = (char *)calloc(text_len+1, sizeof(char));
  unsigned int j=1;
  char count[COUNT_SIZE];
  for(int i=0; i<text_len; i++)
  {
    if(i == text_len-1 || text[i+1] != text[i])
    {
      if(j>1)
      {
        sprintf(count, "%d", j);
        strcat(result, count);
        j=1;
      }
    strncat(result, &text[i], 1);
    }
    else j++;
  }
  return result;
}

char *decode(const char *data)
{
  char *result = (char *)calloc(DECODED_STR_LEN, sizeof(char));
  int x=0;
  for(size_t i=0; i<strlen(data); i++)
  { 
    char *count = (char *)calloc(COUNT_SIZE, sizeof(char));
    if(isdigit(data[i]))//check if current char is digit
    {
      x=i;
      while(isdigit(data[i]))
        i++;
      strncpy(count, &data[x], i-x);
    }
    if(strlen(count) == 0 && (isalpha(data[i]) || isspace(data[i]))) // handles the case where data[i] is non repeating
      strncat(result, &data[i], 1);
    else
    {
      for(int j=0; j<atoi(count); j++)
        strncat(result, &data[i], 1);
    }
    free(count);
  }
  return result;
}