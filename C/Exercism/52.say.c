#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int say(int64_t input, char **ans);
void number_to_words(int number, char **words);

int main(void)
{
  int64_t input = 345;
  char *ans = NULL;
  say(input, &ans);
  printf("ans - |%s|\n", ans);
  free(ans);
  return 0;
}

char *digits[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
                    "eighteen", "nineteen"};
char *tens[] = {"", "", "twenty-", "thirty-", "forty-", "fifty-", "sixty-", "seventy-", "eighty-", "ninety-"};
char *places[] = {"", "", "", " thousand ", "", "", " million ", "", "", " billion "};

int say(int64_t input, char **ans)
{
  
  if(input < 0 || input > 999999999999)
    return -1;
  *ans = (char *)calloc(200, sizeof(char));
  if(input == 0)
  {
    strcpy(*ans, "zero");
    return 0;
  }
  int quotient = 0;
  int exponent = 9;
  int divisor = 0;
  char *words = (char *)calloc(200, sizeof(char));
  while(exponent >= 0)
  {
    divisor = pow(10, exponent);
    quotient = input / divisor;
    if(quotient)
    {
      number_to_words(quotient, &words);
      strcat(*ans, words);
      strcat(*ans, places[exponent]);
      words[0] = '\0';
    }
    input = input % divisor;
    exponent -= 3;
  }
  free(words);
  int ans_len = strlen(*ans);
  char last_char = *(*ans+ans_len-1);
  if(last_char == '-' || last_char == ' ')
    *(*ans+ans_len-1) = '\0';
  return 0;
}

void number_to_words(int number, char **words)
{
  int quotient = 0;
  int exponent = 2;
  int divisor = 0;

  for(int i=0; i<3; i++)
  {
    if(number >= 10 && number <= 19)
    {
      strcat(*words, digits[number]);
      break;
    }
    divisor = pow(10, exponent);
    quotient = number / divisor;
    if(exponent == 1)
      strcat(*words, tens[number/10]);
    else
      strcat(*words, digits[quotient]);
    if(i==0 && quotient)
      strcat(*words, " hundred ");
    number = number % divisor;
    exponent--;
  }
}