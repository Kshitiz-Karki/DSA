#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
};

struct Node *create(int A[], int size)
{
  struct Node *temp = NULL;
  struct Node *tail = NULL;
  struct Node *head = (struct Node *) malloc(sizeof(struct Node));
  head->data = A[0];
  head->prev = NULL;
  head->next = NULL;
  tail = head;

  for(int i=1; i<size; i++)
  {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = A[i];
    temp->next = tail->next;
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
  }
  return head;
}

void display(struct Node *p)
{
  while(p)
  {
    printf("%d ", p->data);
    p=p->next;
  }
  printf("\n");
}

int length(struct Node *p)
{
  int count=0;
  while(p)
  {
    count++;
    p=p->next;
  }
  return count;
}

void freeList(struct Node *p)
{
  struct Node *temp = NULL;
  while(p)
  {
    temp = p;
    p=p->next;
    free(temp);
  }
}

void insertNode(struct Node **head, int index, int data)
{
  struct Node *temp = NULL;
  struct Node *p = *head;

  if(p == NULL)
  {
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    *head = temp;
    return;
  }

  if(index<0 || index>length(*head))
    return;
  
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = data;

  if(index == 0)
  {
    temp->next = p;
    p->prev = temp;
    temp->prev = NULL;
    *head = temp;
  }
  else
  {
    for(int i=0; i<index-1; i++)
      p=p->next;
    temp->next = p->next;
    temp->prev = p;
    p->next = temp;
    if(p->next)
      p->next->prev = temp;
  }
}

int deleteNode(struct Node **head, int index)
{
  if(index < 0 || index > length(*head)-1)
    return -1;
  
  int x=0; 
  struct Node *p = *head;
  if(index == 0)
  {
    *head = p->next;
    x=p->data;
    if(p->next)
      (*head)->prev = NULL;
    free(p);
  }
  else
  {
    for(int i=0; i<index; i++)
      p=p->next;
    p->prev->next = p->next;
    if(p->next)
      p->next->prev = p->prev;
    x = p->data;
    free(p);
  }
  return x;
}

void reverse(struct Node **head)
{
  struct Node *p = *head;
  struct Node * temp = NULL;
  while(p)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p=p->prev;
    if(p && p->next == NULL)
      *head = p;
  }
}

int main (void)
{
  // int A[] = {1,2,3,4,5};
  int A[] = {1};
  int arraySize = sizeof(A)/sizeof(int);
  struct Node *head = create(A, arraySize);
  // struct Node *head = NULL;
  // display(head);
  // printf("Length of doubly linked list = %d\n", length(head));

  // insertNode(&head, 4, 100);
  // printf("Deleted node is %d\n", deleteNode(&head, 10));
  // printf("Length of doubly linked list = %d\n", length(head));
  reverse(&head);
  display(head);
  freeList(head);
  return 0;
}