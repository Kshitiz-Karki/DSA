#include <stdio.h>
#include <stdlib.h>

// struct Matrix
// {
//   int A[20];
//   int size;
// };

// void set(struct Matrix *m, int i, int j, int x)
// {
//   if(i == j)
//     m->A[i-1] = x;
// }

// int get(struct Matrix m, int i, int j)
// {
//   if(i == j)
//     return m.A[i-1];
//   else
//     return 0;
// }

// void Display(struct Matrix m)
// {
//   for(int i=0; i < m.size; i++)
//   {
//     for(int j=0; j<m.size; j++)
//     {
//       if(i == j)
//         printf("%d ", m.A[i]);
//       else
//         printf("0 ");
//     }
//     printf("\n");
//   }
// }

// int main()
// {
//   struct Matrix m;
//   m.size = 4;

//   set(&m,1,1,5);
//   set(&m,2,2,4);
//   set(&m,3,3,9);
//   set(&m,4,4,8);

//   Display(m);

//   printf("%d \n", get(m, 2, 2));
// }

struct Matrix
{
  int *A;
  int size;
};
//Diagonal matrix
// void set(struct Matrix *m, int i, int j, int x)
// {
//   if(i == j)
//     m->A[i-1] = x;
// }

// int get(struct Matrix m, int i, int j)
// {
//   if(i == j)
//     return m.A[i-1];
//   else
//     return 0;
// }

// void Display(struct Matrix m)
// {
//   for(int i=0; i < m.size; i++)
//   {
//     for(int j=0; j<m.size; j++)
//     {
//       if(i == j)
//         printf("%d ", m.A[i]);
//       else
//         printf("0 ");
//     }
//     printf("\n");
//   }
// }

//Lower Triangular matrix
void set(struct Matrix *m, int i, int j, int x)
{
  if(i >= j)
    m->A[i*(i-1)/2 + j-1] = x;
}

int get(struct Matrix m, int i, int j)
{
  if(i >= j)
    return m.A[i*(i-1)/2 + j-1];
  else
    return 0;
}

void Display(struct Matrix m)
{
  for(int i=1; i <= m.size; i++)
  {
    for(int j=1; j<=m.size; j++)
    {
      if(i >= j)
        printf("%d ", m.A[i*(i-1)/2 + j-1]);
      else
        printf("0 ");
    }
    printf("\n");
  }
}

int main()
{
  struct Matrix m;

  printf("Enter size of the matrix: ");
  scanf("%d", &m.size);

  int length = m.size * (m.size + 1) / 2;

  m.A = malloc(length * sizeof(int));

  int x = 0;

  printf("Enter elements for matrix:\n");
  for(int i=1; i<=m.size; i++)
  {
    for(int j=1; j<=m.size; j++)
    {
      scanf("%d", &x);
      set(&m,i,j,x);
    }
  }

  printf("\n\n");
  printf("Lower triangular matrix:\n");

  Display(m);

  // printf("%d \n", get(m, 2, 2));
  free(m.A);
}


