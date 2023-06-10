#ifndef PASCALS_TRIANGLE_H
#define PASCALS_TRIANGLE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void free_triangle(uint8_t **triangle, size_t rows)
{
  for(size_t i=0; i<rows; i++)
    free(triangle[i]);
  free(triangle);
  
}

uint8_t **create_triangle(size_t rows)
{
  uint8_t row_zero = 0;
  if(rows == 0)
  {
    row_zero = 1;
    rows = 1;
  }
  
  uint8_t **arr = (uint8_t **)malloc(rows * sizeof(uint8_t *));
  for(size_t i=0; i<rows; i++)
    arr[i] = (uint8_t *)malloc(rows * sizeof(uint8_t));
  
  for(size_t i=0; i<rows; i++)
  {
    for(size_t j=0; j<rows; j++)
    {
      if(row_zero == 1)
      {
        arr[i][j] = 0;
        return arr;
      }
      else if(i == 0)
      {
        if(j == 0)
          arr[i][j] = 1;
        else
          arr[i][j] = 0;
      }
      else
      {
        if(j >= 1 && j <= rows-1)
          arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
        else
          arr[i][j] = arr[i-1][j];
      }
    }
  }
  return arr;
}

int main(void)
{
  size_t rows = 4;
  uint8_t **arr = create_triangle(rows);

  if(rows == 0)
    rows = 1;

  for(uint8_t i=0; i < rows; i++)
  {
    for(uint8_t j=0; j < rows; j++)
    {
      printf("%u ", arr[i][j]);
    }
    printf("\n");
  }

  free_triangle(arr, rows);

  return 0;
}

#endif
