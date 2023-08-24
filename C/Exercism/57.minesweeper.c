#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);
char check_for_mines(const char **minefield, int row, int col, int total_rows, int total_cols);

int main(void)
{
  const char *minefield[] = {
      // clang-format off
      "  *  ",
      "  *  ",
      "*****",
      "  *  ",
      "  *  "
      // clang-format on
   };
  // const char *minefield[] = { "" };
  // const char *minefield[] = {
  //     // clang-format off
  //     "   ",
  //     "   ",
  //     "   "
  //     // clang-format on
  //  };
  // const char **minefield = NULL;
  size_t rows; 
  rows = 0;
  // rows = sizeof(minefield)/sizeof(*minefield);
  printf("rows - %lu\n", rows);
  char **annotation = annotate(minefield, rows);
  free_annotation(annotation);
  return 0;
}

char **annotate(const char **minefield, const size_t rows)
{
  if(!minefield)
    return NULL;
  size_t cols = strlen(*minefield);
  char ** actual = (char **)calloc(rows, sizeof(char *));
  // char ** actual = (char **)calloc(rows+1, sizeof(char *));
  for(size_t x=0; x<rows; x++)
    actual[x] = (char *)calloc(cols, sizeof(char));
  // actual[rows] = NULL;

  for(size_t i=0; i<rows; i++)
  {
    for(size_t j=0; j<cols; j++)
    {
      if(minefield[i][j] == ' ')
        actual[i][j] = check_for_mines(minefield, i, j, rows, cols);
      else
        actual[i][j] = minefield[i][j];
    }
  }
  return actual;
}

void free_annotation(char **annotation)
{
  // int i=0;
  // while(annotation[i])
  //   free(annotation[i++]);
  free(annotation);
}

char check_for_mines(const char **minefield, int row, int col, int total_rows, int total_cols)
{
  int hint = 0;
  //check for right elemment from current row and col
  if(col+1 < total_cols && minefield[row][col+1] == '*') hint++;
  //check for diagonal elemment below right from current row and col
  if(col+1 < total_cols && row+1 < total_rows && minefield[row+1][col+1] == '*') hint++;
  //check for below elemment from current row and col
  if(row+1 < total_rows && minefield[row+1][col] == '*') hint++;
  //check for diagonal elemment below left from current row and col
  if(col-1 >= 0 && row+1 < total_rows && minefield[row+1][col-1] == '*') hint++;
  //check for left elemment from current row and col
  if(col-1 >= 0 && minefield[row][col-1] == '*') hint++;
  //check for diagonal elemment above left from current row and col
  if(col-1 >= 0 && row-1 >= 0 && minefield[row-1][col-1] == '*') hint++;
  //check for above elemment from current row and col
  if(row-1 >= 0 && minefield[row-1][col] == '*') hint++;
  //check for diagonal elemment above right from current row and col
  if(col+1 < total_cols && row-1 >= 0 && minefield[row-1][col+1] == '*') hint++;
  char hint_ch = hint + '0';
  if (hint_ch == '0')
    hint_ch = ' ';
  return hint_ch;
}