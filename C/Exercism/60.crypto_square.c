#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *ciphertext(const char *input);

int main(void)
{
  char *res = ciphertext("If man was meant to stay on the ground, god would have given us roots.");
  // char *res = ciphertext("This is fun!");
  // char *res = ciphertext("");
  // char *res = ciphertext("@1,%!");
  // char *res = ciphertext("Chill out.");
  printf("res - |%s|\n", res);
  free(res);
  return 0;
}

char *ciphertext(const char *input)
{
  if(!strcmp(input, ""))
  {
    char *empty_res = (char *)calloc(1, sizeof(char));
    strcpy(empty_res, "");
    return empty_res;
  }
  int input_len = strlen(input), j = 0, row = 1, col = 1;
  char *ciphertext_normalized = (char *)calloc(input_len+1, sizeof(char));

  for(int i=0; i<input_len; i++)
  {
    if(isalnum(tolower(input[i])))
      ciphertext_normalized[j++] = tolower(input[i]);
  }

  if(strlen(ciphertext_normalized) == 1) return ciphertext_normalized;

  int ciphertext_len = strlen(ciphertext_normalized);
  while(row * col < ciphertext_len)
  {
    if(col == row) col++;
    else row++;
  }

  char **rectangle = (char **)calloc(row, sizeof(char *));
  for(int x=0; x<row; x++)
    rectangle[x] = (char *)calloc(col+1, sizeof(char));
  
  for(int j=0, k=0; j<ciphertext_len; j+=col, k++)
    strncpy(rectangle[k], &ciphertext_normalized[j], col);

  free(ciphertext_normalized);

  char *result = (char *)calloc(input_len+col, sizeof(char));
  for(int p=0; p<col; p++)
  {
    char *temp = (char *)calloc(row+1, sizeof(char));
    for(int q=0; q<row; q++)
      strncat(temp, &rectangle[q][p], 1);
    if((int)strlen(temp) < row) strcat(temp, " ");
    strcat(result, temp);
    if(p < col-1) strcat(result, " ");
    free(temp);
  }

  for(int x=0; x<row; x++)
    free(rectangle[x]);
  free(rectangle);
  return result;
}