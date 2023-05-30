#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
  int data;
  struct Node *next;
}*head = NULL;

void create(int A[], int n)
{
  int i;
  struct Node *temp, *tail;
  head = (struct Node *) malloc(sizeof(struct Node));
  
  head->data = A[0];
  head->next = NULL;

  tail = head;

  for(i=1; i<n; i++)
  {
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = A[i];
    temp->next = NULL;

    tail->next = temp;
    tail = temp;
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

void display_recursive(struct Node *p)
{
  // if(p)
  // {
  //   printf("%d ", p->data);
  //   display_recursive(p->next);
  // }
  // else
  //   printf("\n");

  if(p)
  {
    display_recursive(p->next);
    printf("%d ", p->data);
  }
}

int count(struct Node *p)
{
  int c=0;
  while(p)
  {
    c++;
    p = p->next;
  }
  return c;
}

int count_recursive(struct Node *p)
{
  if(p)
    return count_recursive(p->next) + 1;
  return 0;
}

int sum(struct Node *p)
{
  int sum = 0;
  while(p)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int sum_recursive(struct Node *p)
{
  if(p)
    return p->data + sum_recursive(p->next);
  return 0;
}

int maximumNode(struct Node *p)
{
  int max = INT_MIN;
  while(p)
  {
    if(p->data > max)
      max = p->data;
    p = p->next;
  }
  return max;
}

int maximumNode_recursive(struct Node *p)
{
  int x;
  if(p)
  {
    x=maximumNode_recursive(p->next);
    return x > p->data ? x : p->data;
  }
  return INT_MIN;
}

int main (void)
{
  int A[] = {3,5,17,-10,15};

  create(A, 5);

  // display(head);

  // display_recursive(head);
  // printf("\n");

  printf("Node count - %d\n", count_recursive(head));
  printf("Sum - %d\n", sum_recursive(head));
  printf("Maximum node data = %d\n", maximumNode(head));

  return 0;
}