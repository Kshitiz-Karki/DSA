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

int main (void)
{
  int A[] = {1,2,3,4,5};
  struct Node *head = create(A, 5);
  display_recursive(head, head);
  freeList(head, 5);
  return 0;
} 