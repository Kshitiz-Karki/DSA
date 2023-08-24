#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
  time_t t;
  srand((unsigned) time(&t));
  int random_number = rand() % 21;
  
  printf("This is a guessing game.\nI have chosen a number between 0 and 20 which you must guess.");

  int user_num = -1;
  int number_of_tries = 5;

  while(user_num != random_number && number_of_tries > 0)
  {
    printf("\nYou have %d tries left.\n", number_of_tries);
    printf("Enter a guess: ");
    scanf("%d", &user_num);

    if(user_num == random_number)
    {
      printf("Congratulations. You guessed it!!\n");
      return 0;
    }
    else if(user_num < 0 && user_num > 20)
      printf("The entered number must be between 0 - 20.\n");
    else
    {
      printf("Sorry, %d is wrong. ", user_num);
      if(random_number < user_num)
        printf("My number is less than that.\n");
      else
        printf("My number is greater than that.\n");
      number_of_tries--;
    }
  }
  printf("Game over, the number was - %d\n", random_number);
  return 0;
}