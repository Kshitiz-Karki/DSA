#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct 
{
  int a;
  int b;
  int c;
}triplet_t;

typedef struct 
{
  int count;
  triplet_t triplets[];
  // triplet_t *triplets;
}triplets_t;

triplets_t *pythagorean_triplet_sum(int sum) 
{
  triplets_t *out = (triplets_t *)malloc( sizeof(int) + sizeof(triplet_t) * 50);
  // triplets_t *out = (triplets_t *)malloc(sizeof(triplets_t));
  // out->triplets = (triplet_t *)malloc(sizeof(triplet_t) * 50);
  out->count = 0;
  
  for(int a=1; a<sum/3; a++)
  {
    for(int b=a+1; b<=(sum-a)/2; b++)
    {
      int c = sqrt(a*a + b*b);
      if(a+b+c == sum && a<b && b<c && a*a + b*b == c*c)
      {
        triplet_t triplet;
        triplet.a = a;
        triplet.b = b;
        triplet.c = c;
        out->triplets[out->count] = triplet;
        out->count++;
      }
    }
  }
  return out;
}

void free_triplets(triplets_t * triplets)
{
  // free(triplets->triplets);
  free(triplets);
}

int main(void)
{
  int sum = 90;
  triplets_t *triplets = pythagorean_triplet_sum(sum);
  
  for(int i=0; i<triplets->count; i++)
  {
    printf("%d %d %d \n", triplets->triplets[i].a, triplets->triplets[i].b, triplets->triplets[i].c);
  }
  printf("Count - %d\n", triplets->count);
  free_triplets(triplets);
  return 0;
}