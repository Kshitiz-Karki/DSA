#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool luhn(const char *num);

int main(void)
{
  const char *num = "4539 3195 0343 6467";
  // const char *num = " 0";
  printf("result - %d\n", luhn(num));
  return 0;
}

bool luhn(const char *num)
{
  int num_len = strlen(num);
  int new_len = 0;
  char current_char = '\0';
  for(int x=0; x<num_len; x++)
  {
    current_char = num[x];
    if(!isdigit(current_char) && !isspace(current_char))
      return false;
    if(isdigit(current_char))
      new_len++;
  }
  if (new_len <= 1) return false;

  int temp = 0, sum = 0, j = new_len % 2 == 0 ? 0 : 1;
  char *new_num = (char *)calloc(num_len+1, sizeof(char));
  char temp_ch = '\0';
  for(int i=0; i<num_len; i++)
  {
    current_char = num[i];
    if(isdigit(current_char))
    {
      if(j++ % 2 == 0 )//check for even placed digit
      {
        temp = (current_char - 48) * 2;
        if(temp > 9) temp -= 9;
        temp_ch = temp + '0';
        strncat(new_num, &temp_ch, 1);
      }
      else
        strncat(new_num, &num[i], 1);
    }
  }
  for(int j=0; new_num[j] != '\0'; j++)
    sum += new_num[j] - 48;
  free(new_num);
  return sum % 10 == 0;
}