#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char *encode(char *text, size_t rails)
{
  size_t txt_len = strlen(text);
  char *output = (char *)malloc(txt_len + 1);
  char input[rails][txt_len];
  //initialize matrix with some initial char
  for(size_t i=0; i<rails; i++)
    for(size_t j=0; j<txt_len; j++)
      input[i][j] = '-';

  size_t row=0, col=0, i=0, x=0, row_down_dir=0;
  //fill the matrix with the text in zig-zag order
  while(text[i])
  {
    if(row == 0 || row == rails-1)
      row_down_dir = !row_down_dir;
    input[row][col++] = text[i++];
    if(row_down_dir) row++; else row--;
  }
  //read from the matrix iterating each row and appending the char found in the output
  for(size_t i=0; i<rails; i++)
    for(size_t j=0; j<txt_len; j++)
      if(input[i][j] != '-')
        output[x++] = input[i][j];
  output[x] = '\0';
  return output;
}

char *decode(char *ciphertext, size_t rails)
{
  size_t len = strlen(ciphertext);
  char *output = (char *)malloc(len+1);
  char input[rails][len];
  //initialize matrix with some initial char
  for(size_t i=0; i<rails; i++)
    for(size_t j=0; j<len; j++)
      input[i][j] = '-';
  //fill the matrix with marker/placeholder for the chars
  size_t row=0, col=0, i=0, row_down_dir=0;

  while(ciphertext[i])
  {
    if(row == 0 || row == rails-1)
      row_down_dir = !row_down_dir;
    input[row][col++] = '*';
    if(row_down_dir) row++; else row--;
    i++;
  }
  //Iterate thro the each row in the matrix and replace the marker with the char in the ciphertext
  int a=0;
  for(size_t p=0; p<rails; p++)
    for(size_t q=0; q<len; q++)
      if(input[p][q] == '*')
        input[p][q] = ciphertext[a++];
  //read the matrix in zig-zag order, appending each time the char found in the output
  int b=0;
  i=0,row=0,col=0,row_down_dir=0;
  while(ciphertext[i])
  {
    if(row == 0 || row == rails-1)
      row_down_dir = !row_down_dir;
    output[b++] = input[row][col++];
    if(row_down_dir) row++; else row--;
    i++;
  }
  output[b] = '\0';
  return output;
}

int main(void)
{
  // char *input = "WEAREDISCOVEREDFLEEATONCE";
  char *input = "EXERCISES";
  // char *output = encode(input, 4);

  // char *input = "ESXIEECSR";
  // char *input = "TEITELHDVLSNHDTISEIIEA";
  // char *input = "EIEXMSMESAORIWSCE";
  // char *input = "133714114238148966225439541018335470986172518171757571896261";
  // char *output = decode(input, 4);
  // char *output = decode(input, 3);
  char *output = encode(input, 4);
  printf("%s\n", output);
  free(output);
  return 0;
}