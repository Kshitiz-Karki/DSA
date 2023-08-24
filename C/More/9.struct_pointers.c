#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
  int x;
  int y;
}Point;

int main(void)
{
  Point *points_arr = NULL;
  int num_points = 2;

  points_arr = (Point *) calloc(num_points, sizeof(Point));

  for(int i=0; i<num_points; i++)
  {
    printf("Enter x co-ordinate for point - %d: ", i+1);
    scanf("%d", &points_arr[i].x);

    printf("Enter y co-ordinate for point - %d: ", i+1);
    scanf("%d", &points_arr[i].y);
  }

  for(int i=0; i<num_points; i++)
  {
    printf("(x, y) = (%d, %d)\n", points_arr[i].x, points_arr[i].y);
  }
  free(points_arr);
  return 0;
}