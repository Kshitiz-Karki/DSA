#include <stdio.h>

int is_palindrome(char *arr, int size)
{
  if(size <= 1)
    return 1;
  if(arr[0] != arr[size-1])
    return 0;
  return is_palindrome(arr+1, size-2);
}

int main(void)
{
  char ints[] = "1221";
  int size = sizeof(ints) - 1;
  printf("Is palindrome - %d\n", is_palindrome(ints, size));
  return 0;
}