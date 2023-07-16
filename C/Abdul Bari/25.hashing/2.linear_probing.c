//lambda factor for linear probing must be <= 0.5 (memory space must be atleast double than the number of elements),,,for deleting is expensive in linear probing because of shifting involed in deleting the elements of hash table. Instead re-hashing is performed excluding the element to be deleted or use a flag for each element to denote if the element is deleted.

#include <stdio.h>

#define SIZE 10

int hash_value(int key)
{
  return key%SIZE;
}

int probe(int H[], int key)
{
  int index = hash_value(key);
  int i=0;
  while(H[(index+i)%SIZE] != 0)
    i++;
  return (index+i)%SIZE;
}

void insert(int H[], int key)
{
  int index = hash_value(key);

  if(H[index] != 0)
    index = probe(H, key);
  
  H[index] = key;
}

int search(int H[], int key)
{
  int index = hash_value(key);
  int i=0;
  while(H[(index+i)%SIZE] != key && H[(index+i)%SIZE] != 0)
    i++;
  if(H[(index+i)%SIZE] == key)
    return (index+i)%SIZE;
  return -1;
}

int main(void)
{
  int hash_table[SIZE] = {0};
  insert(hash_table, 12);
  insert(hash_table, 25);
  insert(hash_table, 35);
  insert(hash_table, 26);

  for(int i=0; i<SIZE; i++)
    printf("%d ", hash_table[i]);
  printf("\n");

  int key = 35;
  printf("Index of key %d is %d\n", key, search(hash_table, key));

  return 0;
}