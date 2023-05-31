#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
  int data;
  struct Node *next;
}*head = NULL;

struct Node *tail = NULL;
void create(int A[], int n)
{
  int i;
  struct Node *temp;
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

struct Node *LinearSearch_recursive(struct Node *p, int key)
{
  if(p == NULL)
    return NULL;
  if(key == p->data)
    return p;
  return LinearSearch_recursive(p->next, key);
}

struct Node *LinearSearch_moveToFirst(struct Node *p, int key)
{
  struct Node *q=p;
  while(p)
  {
    if(key==p->data)
    {
      if(p == q)
        return p;
      q->next = p->next;
      p->next = head;
      head = p;
      return p;
    }
    q=p;
    p=p->next;
  }
  return NULL;
}

void insertNode(struct Node *p, int index, int data)
{
  if(index < 0 || index > count(p))
    return;
  
  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
  temp->data = data;

  if(index == 0)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    for(int i=0; i<index-1; i++)
      p=p->next;
    temp->next = p->next;
    p->next = temp;
  }

}

void insertAtLast(int data)
{
  struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
  temp->data = data;
  temp->next = NULL;

  if(head == NULL)
    head = tail = temp;
  else
  {
    tail->next = temp;
    tail = temp;
  }
}

void insertSorted(struct Node *p, int data)
{
  struct Node *temp, *q = NULL;
  temp = (struct Node *) malloc(sizeof(struct Node *));
  temp->data = data;
  temp->next = NULL;

  if(head == NULL)
    head = temp;
  else
  {
    while(p && p->data < data)
    {
      q=p;
      p=p->next;
    }
      if(head == p)
      {
        temp->next = p;
        head = temp;
      }
      else
      {
        temp->next = q->next;
        q->next = temp;
      }
  }
}

int deleteNode(struct Node *p, int index)
{
  if(index < 1 || index > count(p))
    return -1;
  
  struct Node *q = NULL;
  int x;

  if(index == 1)
  {
    q=head;
    head = p->next;
    x = p->data;
    free(q);
    return x;
  }
  else
  {
    for(int i=1; i<index; i++)
    {
      q=p;
      p=p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int isSorted(struct Node *p)
{
  int x = INT_MIN;
  while(p)
  {
    if(p->data < x)
      return 0;
    x = p->data;
    p=p->next;
  }
  return 1;
}

int main (void)
{
  int A[] = {3,5,17,-10,15};
  create(A, 5);

  // display(head);

  // display_recursive(head);
  // printf("\n");

  // printf("Node count - %d\n", count_recursive(head));
  // printf("Sum - %d\n", sum_recursive(head));
  // printf("Maximum node data = %d\n", maximumNode(head));

  // struct Node *temp = LinearSearch(head, -60);
  // struct Node *temp = LinearSearch_recursive(head, -30);

  // struct Node *temp = NULL;
  // temp = LinearSearch_moveToFirst(head, 17);
  // temp = LinearSearch_moveToFirst(head, 5);
  // temp = LinearSearch_moveToFirst(head, 5);

  // if(temp)
  //   printf("Key is found - %d\n", temp->data);
  // else
  //   printf("Key not found\n");

  // display(head);

  // insertNode(head, 0, 55);
  // display(head);
  // insertNode(head, 2, 65);
  // display(head);
  // insertNode(head, 7, 100);
  // display(head);
  // insertNode(head, 9, 400);
  // display(head);
  // insertNode(head, -9, 400);
  // display(head);

  // insertNode(head, 0, 55);
  // insertNode(head, 1, 65);
  // insertNode(head, 2, 75);
  // insertNode(head, 3, 85);
  // insertNode(head, 4, 95);
  // display(head);

  // insertAtLast(10);
  // insertAtLast(20);
  // insertAtLast(30);
  // display(head);

  // int A[] = {3,5,10,12,15};
  // create(A, 5);
  // insertSorted(head, 49);
  // insertSorted(head, 40);
  // insertSorted(head, 4);
  // display(head);

  // printf("Deleted node with data - %d\n", deleteNode(head, 10));
  // display(head);

  // printf("Is sorted - %d\n", isSorted(head));


  return 0;
}