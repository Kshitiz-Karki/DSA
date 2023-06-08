#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void push(struct Node **p, int data)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

  if(temp == NULL)
    printf("Stack is full / heap memory is not available.\n");
  else
  {
    temp->data = data;
    temp->next = *p;
    *p = temp;
  }
}

int pop(struct Node **top)
{
  int x = -1;
  struct Node *p = *top;
  if(p == NULL)
    printf("Stack is empty.\n");
  else
  {
    *top = p->next;
    x = p->data;
    free(p);
  }
  return x;
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

void freeList(struct Node *top)
{
  struct Node *temp  = NULL;
  while(top)
  {
    temp = top;
    top=top->next;
    free(temp);
  }
}

int main (void)
{
  struct Node *top1 = NULL;
  struct Node *top2 = NULL;
  push(&top1, 10);
  push(&top1, 20);
  push(&top1, 30);
  display(top1);

  push(&top2, 200);
  push(&top2, 300);
  display(top2);
  
  // printf("Popped element is %d\n", pop(&top));
  freeList(top1);
  freeList(top2);
}