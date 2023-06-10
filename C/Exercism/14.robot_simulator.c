#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H

#include <stdio.h>
#include <string.h>


typedef enum {
   DIRECTION_NORTH = 0,
   DIRECTION_DEFAULT = DIRECTION_NORTH,
   DIRECTION_EAST,
   DIRECTION_SOUTH,
   DIRECTION_WEST,
   DIRECTION_MAX
} robot_direction_t;

typedef struct {
   int x;
   int y;
} robot_position_t;

typedef struct {
   robot_direction_t direction;
   robot_position_t position;
} robot_status_t;

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
  robot_status_t robot;
  robot.direction = direction;
  robot.position.x = x;
  robot.position.y = y;
  return robot;
}

void robot_move(robot_status_t *robot, const char *commands)
{
  for(size_t i=0; i<strlen(commands); i++)
  {
    switch (commands[i])
    {
    case 'R': robot->direction = (robot->direction + 1) % DIRECTION_MAX; break;
    case 'L': robot->direction = (robot->direction - 1) % DIRECTION_MAX; break;
    case 'A': {
      switch (robot->direction)
      {
        case 0: robot->position.y++; break;
        case 1: robot->position.x++; break;
        case 2: robot->position.y--; break;
        case 3: robot->position.x--; break;
        case 4: break;
      }
    } break;
    }
  }
}

int main (void)
{
  robot_status_t robot = robot_create(DIRECTION_SOUTH, 8, 4);
  printf("x = %d\n", robot.position.x);
  printf("y = %d\n", robot.position.y);
  printf("Direction = %d\n", robot.direction);
  // printf("DIRECTION_MAX = %d\n", DIRECTION_MAX);
  robot_move(&robot, "LAAARRRALLLL");
  printf("After:\n");
  printf("x = %d\n", robot.position.x);
  printf("y = %d\n", robot.position.y);
  printf("Direction = %d\n", robot.direction);

  return 0;
}

#endif
