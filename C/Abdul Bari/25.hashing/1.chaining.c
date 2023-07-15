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

int main(void)
{
  struct Node *list = create_list(5);
  insert_sorted(&list, 4);
  insert_sorted(&list, 15);
  insert_sorted(&list, 8);
  // insert_sorted(list, -1);
  // insert_sorted(list, 15);
  // insert_sorted(list, 0);
  display(list);
  free_list(list);

  return 0;
}