//#ifndef LIST_OPS_H
// #define LIST_OPS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int list_element_t;

typedef struct {
   size_t length;
   list_element_t elements[];
} list_t;

// constructs a new list
list_t *new_list(size_t length, list_element_t elements[])
{
  list_t *temp = (list_t *)malloc(sizeof(list_t) + length * sizeof(list_element_t));
  if(temp == NULL)
    return NULL;
  temp->length = length;
  
  for(size_t i=0; i<length; i++)
    temp->elements[i] = elements[i];
  return temp;
}

// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
  list_t *temp = (list_t *)malloc(sizeof(list_t) +  ((list1->length + list2->length) * sizeof(list_element_t)) );
  if(temp == NULL)
    return NULL;
  temp->length = list1->length + list2->length;
  size_t i=0;
  for(size_t j=0; j<list1->length; j++)
    temp->elements[i++] = list1->elements[j];
  for(size_t j=0; j<list2->length; j++)
    temp->elements[i++] = list2->elements[j];
  return temp;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t))
{
  size_t newLength = 0;
  for(size_t i = 0; i < list->length; i++)
  {
    if(filter(list->elements[i]))
      newLength++;
  }

  // list_t *newList = (list_t *)malloc(sizeof(list_t) + newLength * sizeof(list_element_t));
  list_element_t *newList = (list_element_t *)malloc(newLength * sizeof(list_element_t));
  // newList->length = newLength;
  int j = 0;
  for(size_t i = 0; i < list->length; i++)
  {
    if(filter(list->elements[i]))
    {
      // newList->elements[j] = list->elements[i];
      newList[j++] = list->elements[i];
    }
  }
  return new_list(newLength, newList);
}

// returns the length of the list
size_t length_list(list_t *list)
{
  return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
  list_element_t *newList = (list_element_t *)malloc(list->length * sizeof(list_element_t));
  int j = 0;
  for(size_t i = 0; i < list->length; i++)
    newList[j++] = map(list->elements[i]);
  return new_list(list->length, newList);
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
  list_element_t accumulator = initial;
  for(size_t i=0; i<list->length; i++)
    accumulator = foldl(accumulator, list->elements[i]);
  return accumulator;
}                                                  

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial, 
                          list_element_t (*foldr)(list_element_t, list_element_t))
{
  list_element_t accumulator = initial;
  for(int i=list->length-1; i>=0; i--)
    accumulator = foldr(list->elements[i], accumulator);
  return accumulator;
}

// reverse the elements of the list
list_t *reverse_list(list_t *list){
  list_element_t *newElements = (list_element_t *)malloc(list->length * sizeof(list_element_t));
  if(!newElements)
    return NULL;
  int j=0;
  for(int i=list->length-1; i>=0; i--)
    newElements[j++] = list->elements[i];
  return new_list(list->length, newElements);
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list)
{
  free(list);
}

// #endif

bool filter(list_element_t x)
{
  return x % 2 == 0;
}

list_element_t mapper(list_element_t x)
{
  return x * 2;
}

list_element_t foldl(list_element_t acc,list_element_t item)
{
  return acc + item;
}

list_element_t foldr(list_element_t item, list_element_t acc)
{
  return acc + item;
}

int main (void)
{
  size_t length = 4;
  list_element_t elements[] = {2,4,3,7};
  // list_element_t elements1[] = {1,2,3};
  // list_element_t elements2[] = {4,5,6};
  // list_t *list1 = new_list(length, elements1);
  // list_t *list2 = new_list(length, elements2);
  //  for(size_t i =0 ; i<list2->length; i++)
  //   printf("%d ", list2->elements[i]);
  // printf("\n");

  // printf("Length - %ld\n", list1->length);
  // list_t *list3 = append_list(list1, list2);
  // printf("Length - %ld\n", list3->length);
  // for(size_t i =0 ; i<list3->length; i++)
  //   printf("%d ", list3->elements[i]);
  // printf("\n");

  list_t *list = new_list(length, elements);
  // list_t *list4 = filter_list(list, filter);
  // list_t *list4 = map_list(list, mapper);
  // list_t *list4 = reverse_list(list);
  // list_element_t accumulator = foldl_list(list, 0, foldl);
  list_element_t accumulator = foldr_list(list, 0, foldr);
  printf("accumulator - %d\n", accumulator);  
// printf("Length - %ld\n", list4->length);
//   for(size_t i =0 ; i<list4->length; i++)
//     printf("%d ", list4->elements[i]);
//   printf("\n");

  // delete_list(list);
  // delete_list(list4);
  // delete_list(list3);
  return 0;
}