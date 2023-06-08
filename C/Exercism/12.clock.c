// #ifndef CLOCK_H
// #define CLOCK_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN (5 + 1)   // "##:##\0"

typedef struct {
   char text[MAX_STR_LEN];
} clock_t;

clock_t clock_create(int hour, int minute)
{
   hour += minute / 60;
  minute %= 60;
  if (minute < 0) {
    minute += 60;
    hour -= 1;
  }
  hour %= 24;
  if (hour < 0) {
    hour += 24;
  }
  clock_t clock;
  sprintf(clock.text, "%02d:%02d", hour, minute);
  return clock;
}

clock_t clock_add(clock_t clock, int minute_add)
{
  int hour;
  int min;
  sscanf(clock.text, "%d:%d", &hour, &min);
  return clock_create(hour, min+minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
  int hour;
  int min;
  sscanf(clock.text, "%d:%d", &hour, &min);
  return clock_create(hour, min-minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b)
{
  return strcmp(a.text, b.text) == 0;
}

int main (void)
{
  clock_t clock1 = clock_create(10, 30);
  // printf("%s\n", clock1.text);

  // clock_t clock2 = clock_create(10, 30);
  clock_t clock2 = clock_add(clock1, 5);
  printf("%s\n", clock2.text);

  // clock_t clock3 = clock_subtract(clock1, 5);
  // printf("%s\n", clock3.text);

  // printf("Is equal = %d\n", clock_is_equal(clock1, clock2));
  return 0;
}

// #endif
