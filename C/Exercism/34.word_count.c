#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORDS 20   // at most MAX_WORDS can be found in the test input string
#define MAX_WORD_LENGTH 50   // no individual word can exceed this length

// results structure
typedef struct word_count_word {
   char text[MAX_WORD_LENGTH +
             1];   // allow for the string to be null-terminated
   int count;
} word_count_word_t;

#define EXCESSIVE_LENGTH_WORD -1
#define EXCESSIVE_NUMBER_OF_WORDS -2

// count_words - routine to classify the unique words and their frequency in a
// sentence inputs:
//    sentence =  a null-terminated string containing that is analyzed
//
// outputs:
//    words = allocated structure to record the words found and their frequency
//    uniqueWords - number of words in the words structure
//           returns a negative number if an error.
//           words will contain the results up to that point.
int count_words(const char *sentence, word_count_word_t *words)
{
  char current_char;
  int j=0, y=0, count_words=0;
  char *temp;
  int skip_copy;

  int sen_len = strlen(sentence);

  for(int i=0; i<sen_len; i++)
  {
    current_char = sentence[i];
    if(current_char == ' ' || i == sen_len - 1 || current_char == '\n' || current_char == ',')
    {
      if(i != j)
      { 
        temp = (char *)malloc(MAX_WORD_LENGTH);

        int x=0;
      
        for(;j<i;j++)
        {
          if((sentence[j] != ':' && sentence[j] != '.' && ( !ispunct(sentence[j]) || ((sentence[j] == 39 && sentence[j-1] != ' ') && (sentence[i] == ' ' && sentence[i-1] != 39))) && sentence[j] != '\n' && sentence[j] != ' ') || (sentence[j] == 39 && sentence[j-1] != ' ' && sentence[j+1] != ' '))
            temp[x++] = tolower(sentence[j]) ;
        }
        if(isalnum(sentence[i]))
          temp[x++] = tolower(sentence[i]);

        temp[x] = '\0';
  
        skip_copy = 0;
        
        for(int i=0; i<y; i++)
        {
          if(strcmp(words[i].text, temp) == 0)
          {
            words[i].count++;
            skip_copy = 1;
            break;
          }
        }
        if(!skip_copy && strlen(temp)>0)
        {
          strcpy(words[y].text, temp);
          words[y].count = 1;
          count_words++;
          y++;
        }
        j++;
      }
    }
  }
  return count_words;
}


int main(void)
{
    //  char *input_text = "go Go GO Stop stop";
     char *input_text = "go Go GO Stop stop";
  // char *input_text = "one fish two fish red fish blue fish";
    //  char *input_text = "one,\ntwo,\nthree";
    // char *input_text = "one,two,three";
    // char *input_text = "car: carpet as java: javascript!!&@$%^&";
    //  char *input_text = "Joe can't tell between 'large' and large.";
    // char *input_text = " multiple   whitespaces";
    //  char *input_text = "can, can't, 'can't'";
        // char *input_text = "testing, 1, 2 testing";
      //  char *input_text = "First: don't laugh. Then: don't cry. You're getting it.";
  


  // char *input_text = "one";
  word_count_word_t *words = (word_count_word_t *)malloc(sizeof(int) + (MAX_WORD_LENGTH + 1));
  
  int count = count_words(input_text, words);
  // printf("\n#################\n");
  printf("word count - (%d)\n", count);
  for(int i=0; i<count; i++)
  {
    printf("(%s) || count - (%d)\n", words[i].text, words[i].count);
    // printf("#########\n");
  }
  return 0;

}