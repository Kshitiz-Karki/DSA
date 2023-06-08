//Circular Linked list with no memory leak !!

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *create(int A[], int n)
{
  struct Node *head = (struct Node *) malloc(sizeof(struct Node));
  head->data = A[0];
  head->next = head;

  struct Node *tail = NULL;
  struct Node *temp = NULL;
  
  tail = head;

  for(int i=1; i<n; i++)
  {
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = A[i];
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
  }
  return head;
}

void display(struct Node *p)
{
  if(!p)
    return;
  
  struct Node *head = p;
  do
  {
    printf("%d ", p->data);
    p=p->next;
  }
  while(p != head);
  printf("\n");
}

void display_recursive(struct Node *p, struct Node *head)
{
  static int flag = 0;
  if(p != head || flag == 0)
  {
    flag = 1;
    printf("%d ", p->data);
    display_recursive(p->next, head);
  }
  if(p == head && flag == 1)
    printf("\n");
  flag = 0;
}

void freeList(struct Node* head, int n)
{
  struct Node* tmp;

  for(int i=0; i<n; i++)
  {
    tmp = head;
    head = head->next;
    free(tmp);
  }
}

void insertNode(struct Node **head, int pos, int data, int size)
{
  if(pos < 0 || pos > size)
    return;
  
  struct Node *p = *head;
  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
  temp->data = data;

  if(pos == 0)
  {
    if(p == NULL)
    {
      *head=temp;
      (*head)->next = *head;
    }
    else
    {
      while(p->next != *head)
        p=p->next;
      temp->next = *head;
      p->next = temp;
      *head = temp;
    }
  }
  else
  {
    for(int i=1; i<=pos-1; i++)
      p=p->next;
    temp->next = p->next;
    p->next = temp;
  }
}

int deleteNode(struct Node **head, int pos, int size)
{
  if(pos < 0 || pos >= size || size == 0)
    return -1;
  
  int data;
  struct Node *p = *head;

  if(pos == 0)
  {
    struct Node *currHead = *head;
    while(p->next != currHead)
      p=p->next;
    
    if(p = currHead)
    {
      data = currHead->data;
      free(currHead);
      *head = NULL;
    }
    else
    {
      p->next = currHead->next;
      data = currHead->data;
      free(currHead);
      *head = p->next;
    }
  }
  else
  {
    for(int i=0; i<pos-1; i++)
      p=p->next;
    struct Node *nextNode = p->next;
    p->next = nextNode->next;
    data = nextNode->data;
    free(nextNode);
  }
  return data;
}

int main (void)
{
  int n;
  // int A[] = {1,2,3,4,5};
  int A[] = {1};
  n = sizeof(A)/sizeof(int);
  struct Node *head = create(A, n);
  // struct Node *head = NULL;
  if(!head)
    n = 0;
  // insertNode(&head, 0, 100, n);
  // display(head);
  // freeList(head, n+1);
  printf("Deleted node is %d\n", deleteNode(&head, 0, n));
  display(head);
  freeList(head, n-1);
  return 0;
} 