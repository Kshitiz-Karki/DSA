#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

char *to_rna(const char *dna)
{
  int len = strlen(dna);
  char *result = (char *)malloc(len);
  if(!dna)
  {
    strcpy(result, "");
    return result;
  }

  int i=0;
  for(; i<len; i++)
  {
    switch (dna[i])
    {
    case 'G':
      result[i] = 'C';
      break;
    case 'C':
      result[i] = 'G';
      break;
    case 'T':
      result[i] = 'A';
      break;
    case 'A':
      result[i] = 'U';
      break;
    default:
      break;
    }
  }
  result[i] = '\0';
  return result;
}

int main(void)
{
  const char *dna = "ACGTGGTCTTAA";
  char *rna = to_rna(dna);
  printf("rna - %s\n", rna);
  return 0;
}
