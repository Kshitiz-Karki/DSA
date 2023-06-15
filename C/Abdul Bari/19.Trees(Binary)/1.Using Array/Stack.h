#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Stack
{
  int size;
  int top;
  struct Node **S;
};

void createStack(struct Stack *st, int size)
{
  st->size = size;
  st->top = -1;
  st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
  if(st->top == st->size - 1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top] = x;
  }
}

struct Node *pop(struct Stack *st)
{
  struct Node *x = NULL;
  if(st->top == -1)
    printf("Stack Underflow\n");
  else
  {
    x = st->S[st->top--];
  }
  return x;
}

int isStackEmpty(struct Stack st)
{
  return st.top == -1;
}

int isStackFull(struct Stack st)
{
  return st.top == st.size - 1;
}

// int main (void)
// {
//   struct Stack s;
//   create(&s);
//   push(&s, 100);
//   push(&s, 90);
//   push(&s, 80);
//   // pop(&s);
//   // pop(&s);
//   // pop(&s);
//   int index = 4;
//   printf("Value at index %d of stack = %d\n", index, peek(s, index));
//   display(s);
//   free(s.S);
//   return 0;
// }
#endif