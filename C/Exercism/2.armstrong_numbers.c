#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int is_armstrong_number(int candidate, int numCount){

  int digit, sum = 0, num = candidate;

  while(candidate != 0) {
    digit = candidate % 10;
    sum += pow(digit, numCount);
    candidate = candidate / 10;
  }
  if (sum == candidate)
    return true;
  return false;
}

int findNumCount(int candidate){
  int count = 0;

  while(candidate != 0){
    candidate = candidate / 10;
    count++;
  }

  return count;
}

int main (void){
  int numCount = findNumCount(5);
  printf("%d\n", is_armstrong_number(5, numCount));
  return 0;
}