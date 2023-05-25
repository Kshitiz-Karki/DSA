// //A string is said to be palindrome if the reverse of the string is the same as the string. 
// #include <stdio.h>
// #include <string.h>

// int isPalindrome(char s[])
// {
//   int left = 0;
//   int right = strlen(s)-1;

//   while(left < right)
//   {
//     if(s[left] != s[right])
//       return 0;
//     left++; right--;
//   }
//   return 1;
// }

// int main (void)
// {
//   char s[] = "abba";

//   printf("Is palindrome - %d\n", isPalindrome(s));
//   return 0;
// }

//using recursion
// #include <stdio.h>
// #include <string.h>

// int isPalindrome(char s[], int left, int right)
// {
//   if(left < right)
//   {
//     if(s[left] == s[right])
//       return isPalindrome(s, left+1, right-1);
//     else
//       return 0;
//   }
//   return 1;
// }

// int main (void)
// {
//   char s[] = "madam";

//   printf("Is palindrome - %d\n", isPalindrome(s, 0, strlen(s)-1));
//   return 0;
// }