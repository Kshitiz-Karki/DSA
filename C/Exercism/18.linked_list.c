#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef int ll_data_t;
struct list;

struct list_node {
   struct list_node *prev, *next;
   ll_data_t data;
};

struct list {
   struct list_node *first, *last;
};

int isEmpty(struct list list)
{
  return list.first == NULL && list.last == NULL;
}

// constructs a new (empty) list
struct list *list_create(void)
{
  struct list *list = (struct list *)malloc(sizeof(struct list));
  list->first = NULL;
  list->last = NULL;
  return list;
}

// counts the items on a list
size_t list_count(const struct list *list)
{
  size_t count=0;
  struct list_node *temp = list->first;
  while(temp)
  {
    count++;
    temp=temp->next;
  }
  return count;
}

// inserts item at back of a list
void list_push(struct list *list, ll_data_t item_data)
{
  struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
  node->next = node->prev = NULL;
  node->data = item_data;

  //check if list is empty
  if(isEmpty(*list))
  {
    list->first = list->last = node;
  }
  else
  {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }
}

// removes item from back of a list
ll_data_t list_pop(struct list *list)
{
  ll_data_t x = -1;
  if(!isEmpty(*list))
  {
    x=list->last->data;
    struct list_node *temp = NULL;
    if(list_count(list) == 1)
    {
      temp=list->first;
      list->first = list->last = NULL;
    }
    else
    {
      temp=list->last;
      list->last = temp->prev;
      list->last->next = NULL;
    }
    free(temp);
  }
  return x;
}

// inserts item at front of a list
void list_unshift(struct list *list, ll_data_t item_data)
{
  struct list_node *node = (struct list_node *)malloc(sizeof(struct list_node));
  node->next = node->prev = NULL;
  node->data = item_data;
  //check if list is empty
  if(isEmpty(*list))
    list->first = list->last = node;
  else
  {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }
}

// removes item from front of a list
ll_data_t list_shift(struct list *list)
{
  ll_data_t x = -1;
  if(!isEmpty(*list))
  {
    x=list->first->data;
    // struct list_node *temp = NULL;
    struct list_node *temp = list->first;
    if(list_count(list) == 1)
    {
      // temp=list->first;
      list->first = list->last = NULL;
    }
    else
    {
      // temp=list->first;
      list->first = temp->next;
      list->first->prev = NULL;
    }
    free(temp);
  }
  return x;
}

// deletes a node that holds the matching data
void list_delete(struct list *list, ll_data_t data)
{
  if(isEmpty(*list))
    printf("List is empty\n");
  else
  {
    struct list_node *temp = list->first;
    if(list_count(list) == 1 && list->first->data == data)
    {
      list->first = list->last = NULL;
      free(temp);
    }
    else if(list->first->data == data)
    {
      list->first = list->first->next;
      list->first->prev = NULL;
      free(temp);
    }
    else if(list->last->data == data)
    {
      temp = list->last;
      list->last = list->last->prev;
      list->last->next = NULL;
      free(temp);
    }
    else{
      struct list_node *p = list->first->next;
      while(p)
      {
        if(p->data == data)
        {
          p->prev->next = p->next;
          p->next->prev = p->prev;
          free(p);
          break;
        }
        p=p->next;
      }
    }
  }
}

// destroys an entire list
// list will be a dangling pointer after calling this method on it
void list_destroy(struct list *list)
{
  struct list_node *temp = NULL;
  while(list->first)
  {
    temp = list->first;
    list->first = list->first->next;
    free(temp);
  }
  free(list);
}

void displayList(struct list *list)
{
  struct list_node *temp = list->first;
  while(temp)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main(void)
{
  struct list *linkedList = list_create();

  // list_unshift(&linkedList, 0);

  // list_push(linkedList, 1);
  // list_push(linkedList, 2);
  // list_push(linkedList, 3);
  // list_push(linkedList, 4);

  // list_unshift(linkedList, 0);
  // list_unshift(linkedList, 10);
  list_unshift(linkedList, 20);

  printf("Linked list = ");
  displayList(linkedList);

  printf("list count - %d\n", list_count(linkedList));
  printf("##########################\n");

  printf("Popped node = %d\n", list_pop(linkedList));
  printf("Linked list = ");
  displayList(linkedList);
  printf("list count - %d\n", list_count(linkedList));
  printf("##########################\n");

  printf("Shifted node = %d\n", list_shift(linkedList));
  printf("Linked list = ");
  displayList(linkedList);
  printf("list count - %d\n", list_count(linkedList));
  printf("##########################\n");

  list_delete(linkedList, 1);
  displayList(linkedList);

  list_destroy(linkedList);
  return 0;
}
