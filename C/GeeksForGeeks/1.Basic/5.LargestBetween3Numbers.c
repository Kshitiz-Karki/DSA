#include <stdio.h>

int main (void)
{
  int A;
  int B;
  int C;

  printf("Enter 1st number: ");
  scanf("%d", &A);

  printf("Enter 2nd number: ");
  scanf("%d", &B);

  printf("Enter 3rd number: ");
  scanf("%d", &C);

  printf("Largest number is - %d\n", A>B ? (A>C ? A : C) : (B>C ? B : C));

  return 0;
}