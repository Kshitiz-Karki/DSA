#include <stdlib.h>
#include <string.h>

#define MAXERR 100

typedef struct factors {
   int factor_a;
   int factor_b;
   struct factors *next;
} factor_t;

struct product {
   int smallest;
   int largest;
   factor_t *factors_sm;
   factor_t *factors_lg;
   char error[MAXERR];
};

typedef struct product product_t;

int is_palindrome(int num, int from, int to)
{
  char buffer[10];
  sprintf(buffer, "%d", num);
  int i=0, j= strlen(buffer)-1;
  while(i < j)
  {
    if(buffer[i] == buffer[j])
    {
      i++; j--;
    }
    else return 0;
  }
  
  for(int i=from; i<=to; i++)
  {
    if(num % i == 0 && num / i >= from && num / i <= to)
      return 1;
  }
  return 0;
}

factor_t *add_factors(int from, int to, int num)
{
  factor_t *first = NULL;
  for(int i=from; i<to; i++)
  {
    if(num % i == 0 && num / i >= from && num / i <= to)
    {
      factor_t *factor = (factor_t *)calloc(1, sizeof(factor_t));
      factor->factor_a = i;
      factor->factor_b = num / i;
      factor->next = NULL;
      if(!first)
        first = factor;
      else
        first->next = factor;
    }
  }
  return first;
}

product_t *get_palindrome_product(int from, int to)
{
  product_t *result = (product_t *)calloc(1, sizeof(product_t));
  if(from > to)
  {
    sprintf(result->error, "invalid input: min is %d and max is %d", from, to);
    return result;
  }
  
  int palinfrome_exists = 1, smallest = from * from;
  while (!is_palindrome(smallest, from , to))
  {
    if(smallest == to*to)
    {
      palinfrome_exists = 0;
      break;
    }
    smallest++;
  }
  if(!palinfrome_exists)
  {
    sprintf(result->error, "no palindrome with factors in the range %d to %d", from, to);
    return result;
  }
  result->smallest = smallest;

  int largest = to * to;
  while (!is_palindrome(largest, from , to) && largest >= from)
    largest--;
  result->largest = largest;
  result->factors_sm = add_factors(from, to, smallest);
  result->factors_lg = add_factors(from, to, largest);
  return result;
}

void free_product(product_t *p) 
{
  while(p->factors_lg)
  {
    factor_t *temp = p->factors_lg->next;
    free(p->factors_lg);
    p->factors_lg = temp;
  }
  while(p->factors_sm)
  {
    factor_t *temp = p->factors_sm->next;
    free(p->factors_sm);
    p->factors_sm = temp;
  }
  free(p);
}