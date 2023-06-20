#include <stdbool.h>
#include <stdio.h>

typedef enum {
   ALLERGEN_EGGS = 1,
   ALLERGEN_PEANUTS = 2,
   ALLERGEN_SHELLFISH = 4,
   ALLERGEN_STRAWBERRIES = 8,
   ALLERGEN_TOMATOES = 16,
   ALLERGEN_CHOCOLATE = 32,
   ALLERGEN_POLLEN = 64,
   ALLERGEN_CATS = 128,
   ALLERGEN_COUNT = 8,
} allergen_t;

typedef struct {
   int count;
   bool allergens[ALLERGEN_COUNT];
} allergen_list_t;

int allergens[] = {1, 2, 4, 8, 16, 32, 64, 128};

bool is_allergic_to(allergen_t allergen, int score)
{
  if(score == allergen) return true;
  if(score > 128 ) return true;
  if(score > allergen)
  {
    score -= allergen;
    for (int i=allergen; i<=ALLERGEN_COUNT; i++)     
    {
      if(allergens[i] == score)
      {
        score = score - allergens[i];
      }
      if(score == 0) return true;
    }
  }
  return false;
}

allergen_list_t get_allergens(int score)
{

}

int main(void)
{
  printf("is_allergic_to(ALLERGEN_EGGS, 0) - %d\n", is_allergic_to(ALLERGEN_EGGS, 0));
  printf("is_allergic_to(ALLERGEN_EGGS, 1) - %d\n", is_allergic_to(ALLERGEN_EGGS, 1));
  printf("is_allergic_to(ALLERGEN_EGGS, 3) - %d\n", is_allergic_to(ALLERGEN_EGGS, 3));
  printf("is_allergic_to(ALLERGEN_EGGS, 2) - %d\n", is_allergic_to(ALLERGEN_EGGS, 2));
  printf("is_allergic_to(ALLERGEN_EGGS, 255) - %d\n", is_allergic_to(ALLERGEN_EGGS, 255));
  return 0;
}


