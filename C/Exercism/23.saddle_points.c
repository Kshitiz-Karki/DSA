#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
  int row;
  int column;
}saddle_point_t;

typedef struct
{
  size_t count;
  saddle_point_t points[];
}saddle_points_t;

saddle_points_t *saddle_points(int row, int col, uint8_t matrix[row][col])
{
  saddle_points_t *result = (saddle_points_t *)malloc(sizeof(size_t) + sizeof(saddle_point_t)*50);
  if(!result) return NULL;
  result->count = 0;
  
  int largest_row, smallest_col = 0;

  for(int i=0; i<row; i++)
  {
    largest_row = matrix[i][0];
    for(int x=0; x<col-1; x++)
    {
      if(matrix[i][x+1] > largest_row)
        largest_row = matrix[i][x+1];
    }
    for(int j=0; j<col; j++)
    {
      if(matrix[i][j] == largest_row)
      {
        smallest_col = matrix[0][j];
        for(int y=0; y<row-1; y++)
        {
          if(matrix[y+1][j] < smallest_col)
            smallest_col = matrix[y+1][j];
        }
        if(largest_row == smallest_col)
          result->points[result->count++] = (saddle_point_t) {i+1, j+1};
      }
    }
  }
  return result;
}

void free_saddle_points(saddle_points_t *saddle_points)
{
  free(saddle_points);
}

int main(void)
{
  //  uint8_t matrix[3][3] = { { 9, 8, 7 }, { 5, 3, 2 }, { 6, 6, 7 } };
   uint8_t matrix[3][3] = { { 6, 7, 8 }, { 5, 5, 5 }, { 7, 5, 6 } };
  //  uint8_t matrix[3][3] = { { 8, 7, 9 }, { 6, 7, 6 }, { 3, 2, 5 } };
  saddle_points_t *actual = saddle_points(3, 3, matrix);
  printf("Count - %d\n", actual->count);
  for(int i=0; i<actual->count; i++)
  {
    printf("{ %d, %d }\n", actual->points[i].row, actual->points[i].column);
  }
  free_saddle_points(actual);
  return 0;
}


