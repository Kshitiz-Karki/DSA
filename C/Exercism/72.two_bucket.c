
//Explanation to the below soution for this problem can be found at: https://www.geeksforgeeks.org/two-water-jug-puzzle/
#include <stdbool.h>

typedef enum { BUCKET_ID_1, BUCKET_ID_2 } bucket_id_t;

typedef unsigned int bucket_liters_t;

typedef struct {
   bool possible;
   int move_count;
   bucket_id_t goal_bucket;
   bucket_liters_t other_bucket_liters;
} bucket_result_t;

void pour(bucket_result_t *actual, int from, int to, int goal, int start_bucket)
{
  actual->possible = true;
  if(to == goal)
  {
    actual->move_count =  start_bucket ? 1 : 2;
    actual->other_bucket_liters = start_bucket ? 0 : from;
    actual->goal_bucket = BUCKET_ID_2;
    return;
  }

  int x = from; //first bucket
  int y = 0; //second bucket
  int temp = 0;
  int move_count = 1;

  while(x != goal && y != goal)
  {
    //find maximum amount that can be poured
    temp = x < to - y ? x : to - y;
    //pour temp liters from "x" to "y"
    y += temp;
    x -= temp;
    move_count++;
    if(x == goal || y == goal) break;
    //If first bucket becomes empty, then fill it
    if(x == 0)
    {
      x = from;
      move_count++;
    }
    //If second bucket becomes full, then empty it
    if(y == to)
    {
      y = 0;
      move_count++;
    }
  }
  actual->move_count = move_count;
  actual->goal_bucket = x == goal && !start_bucket ? BUCKET_ID_1 : BUCKET_ID_2;
  actual->other_bucket_liters = x == goal ? y : x;
}

int gcd(int a, int b)
{
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket)
{  
  bucket_result_t actual;

  //If goal_volume > bucket_2_size OR if greatest common divisor of bucket_1_size & bucket_2_size is not divisible by goal_volume then we cannot measure water using the jugs
  if(goal_volume > bucket_2_size || goal_volume % gcd(bucket_1_size, bucket_2_size))
  {
    actual.possible = false;
    return actual;
  }

  if(start_bucket)
    pour(&actual, bucket_2_size, bucket_1_size, goal_volume, start_bucket);
  else
    pour(&actual, bucket_1_size, bucket_2_size, goal_volume, start_bucket);

  return actual;
}                      