#include <stdio.h>

// int square_root(int n)
// {
//   //Repeated Subtraction Method
//   //-->In this method, the perfect square number is repeatedly subtracted with successive odd numbers, i.e. 3,5,7,9, etc. till we get zero as the remainder. The subtraction begins from 1 and goes on to 3, 5, 7, etc. until zero is derived. This method involves the number of times the value is subtracted to attain zero. This count denotes the square root of numbers that is desired.
//   if(n <= 1)
//     return n;
  
//   int x = 1;
//   int count = 0;
//   while(n != 0)
//   {
//     n -= x;
//     x += 2;
//     count++;
//   }
//   return count;
// }

int square_root(int n)
{//which method ???
  if(n <= 1)
    return n;
  int sqrt = n/2, temp = 0; // sqrt = 8
    while(sqrt != temp){            
      temp = sqrt;       //temp = 4
      sqrt = (n/temp+temp)/2;     //sqrt = (4 + 4) / 2 = 4
    }
    return sqrt;
}

int main (void)
{
  int n = 65025;
  printf("Square root - %d\n", square_root(n));
  return 0;
}

