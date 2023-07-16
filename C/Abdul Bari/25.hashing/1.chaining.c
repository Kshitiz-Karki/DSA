#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *create_list(int data)
{
  struct Node *list = (struct Node *)malloc(sizeof(struct Node));
  list->data = data;
  list->next = NULL;
  return list;
}

void insert_sorted(struct Node **head, int data)
{
  struct Node *p = *head;
  struct Node *q = NULL;
  struct Node *temp = (struct Node *) malloc(sizeof(struct Node ));
  temp->data = data;
  temp->next = NULL;

  if(*head == NULL)
    *head = temp;
  else
  {
    while(p && p->data < data)
    {
      q=p;
      p=p->next;
    }
      if(*head == p)
      {
        temp->next = p;
        *head = temp;
      }
      else
      {
        temp->next = q->next;
        q->next = temp;
      }
  }
}

struct Node *LinearSearch(struct Node *p, int key)
{
  while(p)
  {
    if(p->data == key)
      return p;
    p=p->next;
  }
  return NULL;
}

void display(struct Node *p)
{
  while(p)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void free_list(struct Node *head)
{
  struct Node *temp = NULL;
  while(head)
  {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int hash_value(int key)
{
  return key%10; //hash function
}

void insert_hash_table(struct Node *hash_table[], int key)
{
  int index = hash_value(key);
  if(!hash_table[index])
    hash_table[index] = create_list(key);
  else
    insert_sorted(&hash_table[index], key);
  
}

int main(void)
{
  // struct Node *list = create_list();
  // insert_sorted(&list, 4);
  // insert_sorted(&list, 15);
  // insert_sorted(&list, 8);

  // insert_sorted(&list, -1);
  // insert_sorted(&list, 0);
  // printf("list  - %p\n", list);

  struct Node *hash_table[10] = {NULL};
  for(int i=0; i<10; i++)
    hash_table[i] = NULL;
  
  insert_hash_table(hash_table, 22);
  insert_hash_table(hash_table, 12);
  insert_hash_table(hash_table, 42);
  insert_hash_table(hash_table, 10);
  insert_hash_table(hash_table, 5);

  struct Node *temp = LinearSearch(hash_table[hash_value(10)], 10);
  printf("key - %d\n", temp->data);

  // display(hash_table[2]);
  // display(hash_table[5]);
  // display(hash_table[0]);
  
  // free_list(hash_table[2]);
  // free_list(hash_table[5]);
  // free_list(hash_table[0]);

  return 0;
}