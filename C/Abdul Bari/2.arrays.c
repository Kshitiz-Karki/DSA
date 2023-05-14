#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Array
{
  // int *A;
  int A[20];
  int length;
  int size;
};

void display(struct Array arr)
{ 
  printf("Array elements: \n");
  for(int i=0; i < arr.length; i++)
    printf("%d\n", arr.A[i]);
}

void append(struct Array *arr, int x)
{
  if(arr->length < arr->size){
    arr->A[arr->length++] = x;
  }
}

void insert(struct Array *arr, int index, int x)
{
  if(arr->length < arr->size && index >= 0 && index <= arr->length)
  {
    int i = arr->length - 1;
    while(i != index - 1)
    {
      arr->A[i+1] = arr->A[i];
      i--;
    }
    arr->A[index] = x;
    arr->length++;
  }
}

int delete(struct Array *arr, int index)
{
  if(index >= 0 && index < arr->length)
  {
    int x = arr->A[index];
    for(int i=index; i < arr->length-1; i++ )
    {
      arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

int linearSearch(struct Array arr, int key)
{
  for(int i=0; i < arr.length; i++)
  {
    if(key == arr.A[i])
      return i;
  }
  return -1;
}

int binarySearch(struct Array arr, int key)
{
  int i = 0;
  int j = arr.length-1;
  int middle;

  while(i <= j)
  {
    int middle = (i + j) / 2;
    if(arr.A[middle] == key) return middle;
    else if(arr.A[middle] > key) j = middle - 1;
    else i = middle + 1;
  }
  return -1;
}

int recursiveBinarySearch(struct Array arr, int key, int left, int right)
{
  int middle = (left + right) / 2;

  if(left <= right )
  {
    if(arr.A[middle] == key) return middle;
    else if(arr.A[middle] > key)
      return recursiveBinarySearch(arr, key, left, middle - 1 );
    else
      return recursiveBinarySearch(arr, key, middle+1, right );
  }
  return -1;
}

int sumRecursive(struct Array arr, int length)
{
  if(length < 0)
    return 0;
  return arr.A[length] + sumRecursive(arr, length-1);
}
//reverse of an array without mutating original array
// void reverseNaive(struct Array arr)
// {
//   int *B = malloc(arr.length * sizeof(int));
//   for(int i=arr.length-1, j=0; i>=0; i--, j++)
//   {
//     B[j] = arr.A[i];
//   }
  
//   for(int i=0; i<arr.length; i++)
//   {
//     printf("%d\n", B[i]);
//   }
// }

//reverse of an array mutating original array
void reverseNaive(struct Array *arr)
{
  int *B = malloc(arr->length * sizeof(int));
  for(int i=arr->length-1, j=0; i>=0; i--, j++)
  {
    B[j] = arr->A[i];
  }
  
  for(int i=0; i<arr->length; i++)
  {
    arr->A[i] = B[i];
  }
  free(B);
}

void swap(int *x, int *y)
{ 
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void reverse(struct Array *arr)
{
  int left = 0;
  int right = arr->length-1;
  int temp = 0;

  while(left < right)
  {
    // temp = arr->A[left];
    // arr->A[left] = arr->A[right];
    // arr->A[right] = temp;
    swap(&arr->A[left], &arr->A[right]);
    left++;
    right--;
  }
}

void insertSorted(struct Array *arr, int x)
{
  if(arr->length < arr->size)
  {
    int i = arr->length - 1;
    while(arr->A[i] > x)
    {
      arr->A[i+1] = arr->A[i];
      i--;
    }
    arr->A[i+1] = x;
    arr->length++;
  }
}

bool checkArraySorted(struct Array arr)
{
  int i;
  for(i=0; i<arr.length-1; i++)
    if(arr.A[i] > arr.A[i+1]) return false;
  return true;
}

void rearrange(struct Array *arr)
{
  int i = 0;
  int j = arr->length - 1;

  while(i < j)
  {
    while(arr->A[i] < 0) i++;
    while(arr->A[j] >= 0) j--;
    if(i < j) 
      swap(&arr->A[i], &arr->A[j]);
  }
}

struct Array* merge(struct Array arr1, struct Array arr2)
{
  int i = 0;
  int j = 0;
  int k = 0;
  
  struct Array *arr3 = malloc(sizeof(struct Array));
  
  arr3->length = arr1.length + arr2.length;
  arr3->size = 20;


  while(i < arr1.length && j < arr2.length)
  {
    if(arr1.A[i] <= arr2.A[j])
    {
      arr3->A[k++] = arr1.A[i++];
    }
    else
      arr3->A[k++] = arr2.A[j++];
  }

  while(i < arr1.length)
    arr3->A[k++] = arr1.A[i++];

  while(j < arr2.length)
    arr3->A[k++] = arr2.A[j++];

  return arr3;
}

struct Array* UnionSorted(struct Array arr1, struct Array arr2)
{
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = malloc(sizeof(struct Array));

  while(i < arr1.length && j < arr2.length)
  {
    if(arr1.A[i] < arr2.A[j])
      arr3->A[k++] = arr1.A[i++];
    else if(arr2.A[j] < arr1.A[i])
      arr3->A[k++] = arr2.A[j++];
    else
    {
      arr3->A[k++] = arr1.A[i++];
      j++;
    }
  }

  while(i < arr1.length)
    arr3->A[k++] = arr1.A[i++];

  while(j < arr2.length)
    arr3->A[k++] = arr2.A[j++];

  arr3->length = k;
  arr3->size = 20;

  return arr3;
}

struct Array* intersectionSorted(struct Array arr1, struct Array arr2)
{
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = malloc(sizeof(struct Array));

  while(i < arr1.length && j < arr2.length)
  {
    if(arr1.A[i] < arr2.A[j])
      i++;
    else if(arr2.A[j] < arr1.A[i])
      j++;
    else
    {
      arr3->A[k++] = arr1.A[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 20;

  return arr3;
}

struct Array* differenceSorted(struct Array arr1, struct Array arr2)
{
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *arr3 = malloc(sizeof(struct Array));

  while(i < arr1.length)
  {
    if(arr1.A[i] < arr2.A[j])
      arr3->A[k++] = arr1.A[i++];
    else if(arr2.A[j] < arr1.A[i])
      j++;
    else
    {
      i++;
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 20;

  return arr3;
}

void singleMissingSorted(struct Array arr)
{
  int difference = arr.A[0] - 0;

  for(int i=0; i<arr.length; i++)
  {
    if(arr.A[i] - i != difference)
    {
      printf("The missing element is - %d\n", i+difference);
      break;
    }
  }
}

void multipleMissingSorted(struct Array arr)
{
  int difference = arr.A[0] - 0;

  for(int i=0; i<arr.length; i++)
  {
    if(arr.A[i] - i != difference)
    {
      while(difference < arr.A[i] - i)
      {
        printf("The missing element is - %d\n", i+difference);
        difference++;
      }
    }
  }
}

void multipleMissingHashing(struct Array arr)
{
  int lowest = 6;
  int highest = 19;
  int HashTable[19] = {0};

  for(int i=0; i<arr.length; i++)
    HashTable[arr.A[i]]++;

  for(int i=lowest; i<highest; i++)
  {
    if(HashTable[i] == 0)
      printf("The missing element is - %d\n", i);
  }
}

void findDuplicatesSorted(struct Array arr)
{ 
  int duplicate = 0;

  for(int i=0; i<arr.length-1; i++)
  {
    if(arr.A[i] == arr.A[i+1] && arr.A[i] != duplicate)
    { 
      duplicate = arr.A[i];
      printf("%d is duplicate\n", arr.A[i]);
    }
  }
}

void countDuplicatesSorted(struct Array arr)
{ 
  int duplicate = 0;
  int count = 1;

  for(int i=0; i<arr.length-1; i++)
  {
    if(arr.A[i] == arr.A[i+1] && arr.A[i] != duplicate)
    { 
      duplicate = arr.A[i];
      if(duplicate == arr.A[i]) count++;
        printf("%d is repeating %d times\n", arr.A[i], count);
    }
  }
}

void countDuplicatesSorted2(struct Array arr)
{ 
  int j = 0;
  for(int i=0; i<arr.length-1; i++)
  {
    if(arr.A[i] == arr.A[i+1])
    { 
      j = i+1;
      while(arr.A[i] == arr.A[j]) j++;
      printf("%d is repeating %d times\n", arr.A[i], j-i);
      i = j-1;
    }
  }
}

void findDuplicatesSortedHashing(struct Array arr)
{ 
  int lowest = 3;
  int highest = 20;
  int hashTable[20] = {0};

  for(int i=0; i<arr.length-1; i++)
    hashTable[arr.A[i]]++;

  for(int i=lowest; i < highest; i++)
  {
    if(hashTable[i] > 1)
      printf("%d is duplicate\n", i);
  }
}

void countDuplicatesSortedHashing(struct Array arr)
{ 
  int lowest = 3;
  int highest = 20;
  int hashTable[20] = {0};

  for(int i=0; i<arr.length-1; i++)
    hashTable[arr.A[i]]++;

  for(int i=lowest; i < highest; i++)
  {
    if(hashTable[i] > 1)
      printf("%d is repeating %d times\n", i, hashTable[i]);
  }
}

void sumPairHashing(struct Array arr, int sum)
{
  int lowest = 2;

  struct Array *hashTable = malloc(sizeof(struct Array));
  hashTable->size = 20;
  hashTable->length = sum+1;

  for(int i=0; i < hashTable->length; i++)
    hashTable->A[i] = 0;
  
  for(int i=0; i<arr.length; i++)
  {
    if(sum-arr.A[i] > 0)
    {
    if(hashTable->A[sum-arr.A[i]] != 0)
      printf("%d + %d = %d\n", arr.A[i], sum-arr.A[i], sum);
    hashTable->A[arr.A[i]]++;
    }
  }
  free(hashTable);
}

void sumPairSorted(struct Array arr, int k)
{
  int i=0;
  int j=arr.length-1;
  int sum;

  while(i < j)
  {
    sum = arr.A[i] + arr.A[j];
    if(sum > k) j--;
    else if(sum < k) i++;
    else
    {
      printf("%d + %d = %d\n", arr.A[i], arr.A[j], k);
      i++;
      j--;
    }
  }
}

void maxAndMinSingleScan(struct Array arr)
{
  int max = arr.A[0];
  int min = arr.A[0];

  for(int i=1; i<arr.length; i++)
  {
    if(arr.A[i] > max)
      max = arr.A[i];
    if (arr.A[i] < min)
      min = arr.A[i];
  }
  printf("Min - %d\n", min);
  printf("Max - %d\n", max);
}

// void stringLength(char s[])
// {
//   int count = 0;
//   for(int i=0; s[i]!='\0'; i++)
//     count++;
//   printf("string length - %d\n", count);
// }

void stringLength(char *s)
{
  int count = 0;
  for(int i=0; s[i]!='\0'; i++)
    count++;
  printf("string length - %d\n", count);
}

// void changeCase(char s[])
// {
//   int i;
//   for(i=0; s[i] != '\0'; i++)
//   {
//     s[i] = s[i] - 32;
//   }
//   s[i] = '\0';
//   printf("%s\n", s);
 
// }

void changeCase(char *s)
{
  char *upper = malloc((strlen(s)+1) * sizeof(char));
  int i;
  for(i=0; s[i] != '\0'; i++)
    upper[i] = s[i] - 32;
  upper[i] = '\0';
  printf("%s\n", upper);
  free(upper);
}

//without mutating
// void reverseString(char s[])
// {
//   char newString[10];
//   int stringLength = strlen(s);
//   int j=0;
//   for(int i=stringLength-1; i>=0; i--, j++)
//   {
//     newString[j] = s[i];
//   }
//   newString[j] = '\0';
//   printf("%s\n", s);
//   printf("%s\n", newString);
// }

void reverseString(char s[])
{
  int i=0;
  int j=strlen(s)-1;
  char temp;

  while(i<j)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    i++;
    j--;
  }
  printf("%s\n", s);
}

bool stringCompare(char s1[], char s2[])
{
  if (strlen(s1) != strlen(s2))
    return false;

  for(int i=0; i < strlen(s1); i++)
  {
    if(s1[i] != s2[i])
      return false;
  }
  return true;
}

// bool isPalindrome(char s[])
// {
//   int i=0;
//   int j=strlen(s)-1;

//   while(i<j)
//   {
//     if(s[i] == s[j])
//     {
//       i++;
//       j--;
//     }
//     else
//       return false;
//   }
//   return true;
// }

bool isPalindrome(char *s)
{
  int i=0;
  int j=strlen(s)-1;

  while(i<j)
  {
    if(s[i] == s[j])
    {
      i++;
      j--;
    }
    else
      return false;
  }
  return true;
}
//Finding duplicate using bitwise operations
void duplicateChars(char s[])
{
  int hashTable = 0;
  int x = 0;

  for(int i=0; s[i]!='\0'; i++)
  {
    x = 1;
    x = x << (s[i] - 97);
    if((x & hashTable) > 1)
      printf("%c is duplicate\n", s[i]);
    else
      hashTable = x | hashTable;
  }
}

// void permutation(char s[], int k)
// {
//   static int A[10] = {0};
//   static char result[10];

//   if(s[k] == '\0')
//   {
//     result[k] = '\0';
//     printf("%s\n", result);
//   }
//   for(int i=0; s[i] != '\0'; i++)
//   {
//     if(A[i] == 0)
//     {
//       result[k] = s[i];
//       A[i] = 1;
//       permutation(s, k+1);
//       A[i] = 0;
//     }
//   }
// }

void swapChar(char *a, char *b)
{
  char temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

// void swapCheck(char s[])
// {
//   swapChar(&s[0], &s[1]);
//   printf("%s\n", s);
// }

void permutation(char s[], int left, int right)
{
  char temp;
  if(left == right)
    printf("%s\n", s);
  else
  {
    for(int i=left; i <= right; i++)
    {
      swapChar(&s[left], &s[i]);
      permutation(s, left+1, right);
      swapChar(&s[left], &s[i]);
    }
  }
}

int main(void)
{
  // struct Array arr;
  // printf("Enter array size: ");
  // scanf("%d", &arr.size);

  // arr.A = malloc(arr.size * sizeof(int));

  // printf("Enter array length: ");
  // scanf("%d", &arr.length);

  // printf("Enter array elements:\n");
  // for(int i=0; i < arr.length; i++)
  //   scanf("%d", &arr.A[i]);
  
  // append(&arr, 100);
  // insert(&arr, 0, 15);
  // printf("%d was deleted!!\n", delete(&arr, 0));
  // printf("index - %d\n", linearSearch(arr, 6));
  // free(arr.A);

  // struct Array arr = {{4,8,10,15,18,21,24,27,29,33,34,37,39,41,43}, 15, 20};
  // printf("index - %d\n", binarySearch(arr, 37));
  // printf("index - %d\n", recursiveBinarySearch(arr, 37, 0, arr.length-1));

// struct Array arr = {{4,8,8}, 3, 20};
//   printf("Sum - %d\n", sumRecursive(arr, arr.length-1));

  // struct Array arr = {{4,8,6,0,10,13,1}, 7, 20};
  // reverseNaive(&arr);
  // reverse(&arr);

  // struct Array arr = {{4,8,13,16,20,25,28,33}, 8, 10};
  // printf("Is array sorted - %d\n", checkArraySorted(arr));
  // insertSorted(&arr, 18);
  // struct Array arr = {{-6,3,-8,10,5,-7,-9,12,-4,-2}, 10, 20};
  // rearrange(&arr);

  // struct Array arr1 = {{4, 8, 13, 20, 30}, 5, 20};
  // struct Array arr2 = {{1, 3, 18, 26, 36}, 5, 20};
  // struct Array *arr3 = merge(arr1, arr2);
  // display(*arr3);
  // free(arr3);
  
  // struct Array arr1 = {{4, 8, 18, 20, 30, 45}, 6, 20};
  // struct Array arr2 = {{1, 8, 18, 26, 36, 39}, 6, 20};
  // struct Array *arr3 = UnionSorted(arr1, arr2);
  // display(*arr3);
  // free(arr3);

    // struct Array arr1 = {{3, 4, 5, 6, 10}, 5, 20};
    // struct Array arr2 = {{2, 4, 5, 7, 12}, 5, 20};
    // struct  Array *arr3 = intersectionSorted(arr1, arr2);
    // display(*arr3);
    // free(arr3);
    
    // struct Array arr1 = {{3, 4, 5, 6, 10}, 5, 20};
    // struct Array arr2 = {{2, 4, 5, 7, 12}, 5, 20};
    // struct Array *arr3 = differenceSorted(arr1, arr2);
    // display(*arr3);
    // free(arr3);
    
    // struct Array arr = {{6,7,8,9,10,11,13,14,15,16,17},11,20};
    // singleMissingSorted(arr);

    // struct Array arr = {{6,7,8,9,11,12,15,16,17,18,19},11,20};
    // multipleMissingSorted(arr);

    // struct Array arr = {{6,7,8,9,11,12,15,16,17,18,19},11,20};
    // multipleMissingHashing(arr);

    // struct Array arr = {{3,6,8,8,10,12,15,15,15,20},10,20};
    // findDuplicatesSorted(arr);
    // findDuplicatesSortedHashing(arr);

    // struct Array arr = {{3,6,8,8,10,12,15,15,15,20},10,20};
    // countDuplicatesSorted(arr);
    // countDuplicatesSorted2(arr);
    // countDuplicatesSortedHashing(arr);

    // struct Array arr = {{6,3,8,10,16,7,5,2,9,14},10,20};
    // sumPairHashing(arr, 10);

    // struct Array arr = {{1,3,4,5,6,8,9,10,12,14},10,20};
    // sumPairSorted(arr, 10);

    // struct Array arr = {{5,8,3,9,6,2,10,7,-1,4},10,20};
    // maxAndMinSingleScan(arr);

    // char string[] = "welcome";
    // char *string = "welcome";
    // stringLength(string);
    // changeCase(string);
    // reverseString(string);

    // char string1[] = "Painter";
    // char string2[] = "Painter";
    // printf("Is string equal - %i\n", stringCompare(string1, string2));

    // char string[] = "madam";
    // char *string = "madam";
    // printf("Is palindrome - %i\n", isPalindrome(string));

    // char s[] = "finding";
    // duplicateChars(s);

    char s[] = "ABC";
    // char s[] = "AB";
    // permutation(s, 0);
    permutation(s, 0, 2);
    // swapCheck(s);
  return 0;
}
