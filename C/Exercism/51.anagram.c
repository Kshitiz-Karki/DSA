#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_STR_LEN 20

enum anagram_status { UNCHECKED = -1, NOT_ANAGRAM, IS_ANAGRAM };

struct candidate {
   enum anagram_status is_anagram;
   const char *word;
};

struct candidates {
   struct candidate *candidate;
   size_t count;
};

/**
 * @description - determines if any of the words in candidate are anagrams
 *                for subject. Contents of candidate structures may be modified.
 */
void find_anagrams(const char *subject, struct candidates *candidates);

int main(void)
{
  
  return 0;
}

void bubble_sort(char candidate[], int size);

void find_anagrams(const char *subject, struct candidates *candidates)
{
  int sub_len = strlen(subject);
 //sort subject and store in new variable 'subject_sorted'
  char subject_sorted[MAX_STR_LEN];
  strncpy(subject_sorted, subject, sizeof(subject_sorted));
  bubble_sort(subject_sorted, sub_len);
  
  int candidate_len = 0;
  //for each candidate
  char candidate_sorted[MAX_STR_LEN];
  for(size_t i=0; i<candidates->count; i++)
  {
    //if word length and subject length are not equal OR if current word is same as subject case insensitively then the word cannot be anagram
    candidate_len = strlen(candidates->candidate[i].word);
    if(candidate_len != sub_len || !strcasecmp(candidates->candidate[i].word, subject))
    {
      candidates->candidate[i].is_anagram = NOT_ANAGRAM;
      continue;
    }
    //sort current candidate word and store in new variable 'candidate_sorted'
    strncpy(candidate_sorted, candidates->candidate[i].word, sizeof(candidate_sorted));
    bubble_sort(candidate_sorted, candidate_len);
    //if candidate_sorted and subject_sorted are equal then current word is anagram
    if(!strcasecmp(subject_sorted, candidate_sorted))
      candidates->candidate[i].is_anagram = IS_ANAGRAM;
    else
      candidates->candidate[i].is_anagram = NOT_ANAGRAM;
  }
}

void bubble_sort(char candidate[], int size)
{
  int no_swap = 0;
  char current_char = '\0';
  char next_char = '\0';
  for(int i=size-1; i>0; i--)
  {
    no_swap = 0;
    for(int j=0; j<i; j++)
    {
      current_char = tolower(candidate[j]);
      next_char = tolower(candidate[j+1]);
      if(current_char > next_char)
      {
        char temp = current_char;
        candidate[j] = next_char;
        candidate[j+1] = temp;
        no_swap = 1;
      }
    }
    if(!no_swap) break; //return;
  }
}