#include <stdio.h>
#include <ctype.h>

int main (void)
{
  char ch;
  printf("Enter a character: ");
  scanf("%c", &ch);

  if(toupper(ch) == 'A' || toupper(ch) == 'E' || toupper(ch) == 'I' || toupper(ch) == 'O' || toupper(ch) == 'U')
    printf("%c is vowel\n", ch);
  else if(toupper(ch) < 65 || toupper(ch) > 91)
    printf("%c is neither vowel nor consonant\n", ch);
  else
    printf("%c is consonant\n", ch);

  return 0;
}