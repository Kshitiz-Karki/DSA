#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *atbash_encode(const char *input);
char *atbash_decode(const char *input);

char cipher[] = "zyxwvutsrqponmlkjihgfedcba";

int main (void)
{
  // char *cipher_text = atbash_encode("The quick brown fox jumps over the lazy dog.");
  // printf("cipher_text - |%s|\n", cipher_text);
  // free(cipher_text);
  char *plain_text = atbash_decode("vc vix    rhn");
  printf("plain_text - |%s|\n", plain_text);
  free(plain_text);
  return 0;
}

char *atbash_encode(const char *input)
{
  int input_len = strlen(input);
  char *cipher_text = (char *)calloc(input_len + input_len/5 + 1, sizeof(char));
  int j=0, space_idx = 5;
  char current_char = '\0';
  for(int i=0; i<input_len; i++)
  {
    current_char = tolower(input[i]);
    if(isalpha(current_char))
      cipher_text[j++] = cipher[current_char-97];
    if(isdigit(current_char))
      cipher_text[j++] = current_char;
    if(input[i+1] == '.') break;
    if(space_idx == j)
    {
      cipher_text[j++] = ' ';
      space_idx = j+5;
    }
  }
  return cipher_text;
}

char *atbash_decode(const char *input)
{
  int input_len = strlen(input);
  char *plain_text = (char *)calloc(input_len + 1, sizeof(char));
  int j=0;
  char current_char = '\0';
  for(int i=0; i<input_len; i++)
  {
    current_char = tolower(input[i]);
    if(isalpha(current_char))
      plain_text[j++] = cipher[current_char-97];
    if(isdigit(current_char))
      plain_text[j++] = current_char;
  }
  return plain_text;
}