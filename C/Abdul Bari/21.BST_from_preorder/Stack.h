#ifndef Stack_h
#define Stack_h

#include <stdlib.h>
#include <stdio.h>

struct bst_node
{
  struct bst_node *lchild;
  int data;
  struct bst_node *rchild;
};

struct Node
{
  // int data;
  struct bst_node *data;
  struct Node *next;
};

// struct Node *create_stack(int data)
// {
//   struct Node *stack = (struct Node *)malloc(sizeof(struct Node));
//   stack->data = data;
//   stack->next = NULL;
//   return stack;
// }

void push(struct Node **p, struct bst_node *data)
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

struct bst_node *pop(struct Node **top)
{
  struct bst_node *x = NULL;
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

// int main (void)
// {
//   struct Node *stk = NULL;
//   push(&stk, 5);
//   push(&stk, 10);
//   push(&stk, 20);
//   push(&stk, 30);
//   display(stk);
  
//   printf("Popped element is %d\n", pop(&stk));
//   display(stk);
//   freeList(stk);
//   return 0;
// }
#endif