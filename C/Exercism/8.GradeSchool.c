#include <stdio.h>
#include <stdint.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
  uint8_t grade;
  char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
  size_t count;
  student_t students[MAX_STUDENTS];
} roster_t;

void add_student(char name[], uint8_t grade)
{

}

int main (void)
{
  student_t students[MAX_STUDENTS];
  roster_t roster;

  // add_student(char name[], uint8_t grade);

  students[0].grade = 1;
  strcpy(students[0].name, "HIU");

  return 0;
}