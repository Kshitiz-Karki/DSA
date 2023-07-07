#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len)
{
  return scores[scores_len-1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len)
{
  int32_t best = scores[0];
  for(size_t i=1; i < scores_len; i++)
  {
    if(scores[i] > best)
      best = scores[i];
  }
  return best;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
{
  int32_t temp_score=0, temp[scores_len];
  int no_swap;

  for(size_t i=0; i<scores_len; i++)
    temp[i] = scores[i];

  //perform bubble sort for 3 elements
  for(size_t i=0; i<scores_len; i++)
  {
    no_swap = 1;
    for(size_t j=0; j<scores_len-1-i; j++)
    {
      if(temp[j] > temp[j+1])
      {
        temp_score = temp[j];
        temp[j] = temp[j+1];
        temp[j+1] = temp_score;
        no_swap = 0;
      }
    }
    if(no_swap) break;
  }

  int j=0;
  for(int i=scores_len-1; i>=(int)scores_len-3; i--)
    output[j++] = temp[i];
  
  if(scores_len < 3 ) j =  scores_len;
  return j ;
}

int main(void)
{
   const int scores[] = { 10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70 };
    //  const int scores[] = { 20, 10, 30 };
    // const int scores[] = { 40, 20, 40, 30 };
      // const int scores[] = { 30, 70 };
   int output[3];
   int size = sizeof(scores)/sizeof(int);
  personal_top_three(scores, size, output);
  for(int i=0; i<3; i++)
    printf("%d ", output[i]);
  return 0;
}

