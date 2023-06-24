#include <stdbool.h>
#include <stdio.h>

typedef enum {
   ALLERGEN_EGGS = 0,
   ALLERGEN_PEANUTS,
   ALLERGEN_SHELLFISH,
   ALLERGEN_STRAWBERRIES,
   ALLERGEN_TOMATOES,
   ALLERGEN_CHOCOLATE,
   ALLERGEN_POLLEN,
   ALLERGEN_CATS,
   ALLERGEN_COUNT,
} allergen_t;

typedef struct {
   int count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

bool is_allergic_to(allergen_t allergen, int score)
{
  return score & 1 << allergen;
}

allergen_list_t get_allergens(int score)
{
  allergen_list_t result;
  result.count = 0;

  for(int i=0; i<ALLERGEN_COUNT; i++)
  {
    result.allergens[i] = is_allergic_to(i, score);
    if(result.allergens[i]) result.count++;
  }
  return result;
}

