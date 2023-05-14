#include <stdio.h>

// void func(int n){
//   if(n > 0){
//     func(n-1);
//     printf("%d\n", n);
//   }
// }

// void func(int n){
//   if(n > 0){
//     printf("%d\n", n);
//     func(n-1);
//   }
// }

//////////////////////recursion using global and static variable///////////////
// int x = 0;   //using global variable
// int func(int n){
//   // static int x = 0;
//   if(n > 0){
//     x++;
//     return func(n-1)+x;
//   }
//   return 0;
// }

// int main(void){
//   int n = 5;
//   printf("%d\n", func(n));
//   return 0;
// }

/////////////////////////////////////////////Sum of n natural numbers////////////////////////////////////////////////
//1. using mathematical formula
//Time complexity - O(1)
//Space complexity - O(1)

// int sum (int n){
//   return n * (n+1)/2;    
// }

//2. using loop
//Time complexity - O(n)
//Space complexity - O(1)
// int sum(int n){
//   int sum = 0;
//   for(int i = 1; i <= n; i++ )
//     sum += i;
//   return sum;
// }

//3. using recursion
//Time complexity - O(n)
//Space complexity - O(n)
// int sum (int n){
//   if(n == 1)
//     return 1;
//   return sum(n-1) + n;
// }

// int main(void){
//   printf("%d\n", sum(5));
//   return 0;
// }

/////////////////////////////////////////////Factorial of a number////////////////////////////////////////////////

// //1. using recursion
// //Time complexity - O(n)
// //Space complexity - O(n)
// int factorial(int n){
//   if(n < 0)
//     return 0;
//   if(n == 0)
//     return 1;
//   return n * factorial(n-1);
// }

// //1. using loop
// //Time complexity - O(n)
// //Space complexity - O(1)
// int factorial(int n){
//   if(n < 0)
//     return 0;
//   int fact = 1;
//   for(int i = 1; i <= n; i++)
//     fact *= i;
//   return fact;
// }

// int main(void){
//   printf("%d\n", factorial(5));
//   return 0;
// }

/////////////////////////////////////////////Exponent of a number////////////////////////////////////////////////
//1. using recursion
//Time complexity - O(n)
//Space complexity - O(n)
// int power(int m, int n){
//   if(n < 0 || m <= 0)
//     return 0;
//   if(n == 0)
//     return 1;
//   return m * power(m, n-1);
// }

//Optimised version,, number of recursive steps are reduced
// int power(int m, int n){
//   if(n < 0 || m <= 0)
//     return 0;
//   if(n == 0)
//     return 1;
//   if(n % 2 == 0)
//     return power(m*m, n/2);
//   return m * power(m*m, (n-1)/2);
// }

// int main(void){
//   printf("%d\n", power(3, 4));
//   return 0;
// }

/////////////////////////////////////////////////////Taylor series////////////////////////////////////////////////////
//Time complexity - O(n**2)
//1. using recursion
// double e(int x, int n) {
// ///x --> number for which taylor series is to be calculated
// ///n --> number of terms in the taylor series
//   static double p=1, f=1;
//   double result;

//   if(n == 0)
//     return 1;

//   result = e(x, n-1);
//   p=p*x;
//   f=f*n;
//   return result+p/f;

// }

// int main(void){
//   printf("%lf\n", e(1, 10));

//   return 0;
// }


////////////////////Horner's rule////////////
//Time complexity - O(n)
//2. using loop

// double e(int x, int n ){
//   double sum = 1;

//   for(; n>0; n--){
//     sum = 1 + x*sum/n;
//   }
//   return sum;
// }

// int main (void){

//   printf("%lf\n", e(1, 10));
//   return 0;
// }

//2. using recursion
// double e(int x, int n ){
//   static double sum;
//   if(n == 0)
//     return sum;
//   sum = 1 + x*sum/n;
//   return e(x, n-1);
// }

// int main (void){
//   printf("%lf\n", e(1, 10));
//   return 0;
// }


/////////////////////////////////////////Fibonacci series/////////////////////////////////////////////////////////
// //Time complexity - O(n)
// //1. using loop

// int fib(int n){
//   int t0 = 0;
//   int t1 = 1, sum = 0;

//   for(int i = 2; i <= n; i++){
//     sum = t0 + t1;
//     t0 = t1;
//     t1 = sum;
//   }
//   return sum;
// }

// int main(void){
//   printf("%d \n", fib(7));
//   return 0;
// }

// // Time complexity - O(2**n)
// //2. using recursion (Execessive recursion)

// int fib(int n){
//   if(n <= 1)
//     return n;
//   return fib(n-1) + fib(n-2);
  
// }

// int main(void){
//   printf("%d \n", fib(7));
//   return 0;
// }

// Time complexity - O(n)
//3. using recursion and memoization (Dynamic programming, overlapping subprolems)

const int size = 7;
int F[7];

int mfib(int n){  
  if(n <= 1){
    F[n] = n;
    return n;
  }
  else{
    if(F[n-2] == -1)
      F[n-2] = mfib(n-2);
    if(F[n-1] == -1)
      F[n-1] = mfib(n-1);
    F[n] = F[n-1] + F[n-2];
    return F[n-1] + F[n-2];
  }
  
}

int main(void){
  for(int i = 0; i < size; i++){
    F[i] = -1;
  }
  printf("%d \n", mfib(size));
  return 0;
}