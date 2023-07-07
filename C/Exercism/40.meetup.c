#include <stdio.h>
#include <string.h>

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week)
{
  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  //check for leap year
  if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    days_in_month[2] = 29;
  //Tomohiko Sakamoto’s Algorithm --start
  // array with leading number of days values for each month
  int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
  // if month is January or February then reduce year by 1
  if (month < 3)
    year -= 1;
  
  int day = 1;
  if(strcmp(week, "teenth") == 0)
    day = 13;
  if(strcmp(week, "last") == 0)
    day = days_in_month[month];
  
  int first_day_of_month = (year + year/4 - year/100 + year/400 + t[month - 1] + day) % 7;
  //Tomohiko Sakamoto’s Algorithm --end
  char *days_in_week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  
  int week_num = 0;
  if(strcmp(week, "first") == 0)
    week_num = 0;
  if(strcmp(week, "second") == 0)
    week_num = 1;
  if(strcmp(week, "third") == 0)
    week_num = 2;
  if(strcmp(week, "fourth") == 0 )
    week_num = 3;

  int i= first_day_of_month + (week_num*7);
  int date = day + (week_num*7);
  while(strcmp(day_of_week, days_in_week[i%7]) != 0)
  {
    if(strcmp(week, "last") == 0)
    {
      i--;date--;
    }
    else
    {
      i++;date++;
    }
    if(i < 0)
      i = 6;
    else
      i=i%7;
  }
  return date;
}                        


int main (void)
{
  unsigned int year = 2013;
  unsigned int month = 4;
  const char *week = "last";
  const char *day_of_week = "Wednesday";
  printf("Date - %d\n", meetup_day_of_month(year, month, week, day_of_week));
  return 0;
}


