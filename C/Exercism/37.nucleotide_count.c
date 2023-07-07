#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct
{
  int A;
  int C;
  int G;
  int T;
}nucleotide_t;

char *count(const char *dna_strand)
{
  char *result = (char *)malloc(SIZE);
  if(!dna_strand)
  {
    strcpy(result, "A:0 C:0 G:0 T:0");
    return result;
  }

  nucleotide_t nucleotide;
  nucleotide.A = nucleotide.C = nucleotide.G = nucleotide.T = 0;

  for(int i=0; dna_strand[i] != '\0'; i++)
  {
    switch (dna_strand[i])
      {
        case 'A':
          nucleotide.A++;
          break;
        case 'C':
          nucleotide.C++;
          break;
        case 'G':
          nucleotide.G++;
          break;
        case 'T':
          nucleotide.T++;
          break;
        default:
          strcpy(result, "");
          return result;
      }
  }
    sprintf(result, "A:%d C:%d G:%d T:%d", nucleotide.A, nucleotide.C, nucleotide.G, nucleotide.T);
    return result;
}

int main(void)
{
  // const char *dna_strand = "AGXXACT";
  const char *dna_strand = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";
  char *result = count(dna_strand);
  printf("Nucleotide count - %s\n", result);
  free(result);
  return 0;
}

