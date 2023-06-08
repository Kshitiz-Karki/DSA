#include <stdio.h>
#include <stdlib.h>

struct Stack
{
  int size;
  int top;
  int *S;
};

void create(struct Stack *st)
{
  printf("Enter stack size:");
  scanf("%d", &st->size);
  
  st->top = -1;
  st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
  if(st->top == st->size - 1)
    printf("Stack overflow\n");
  else
  {
    st->top++;
    st->S[st->top] = x;
    
  }
}

int pop(struct Stack *st)
{
  int x = -1;
  if(st->top == -1)
    printf("Stack Underflow\n");
  else
  {
    x = st->S[st->top--];
  }
  return x;
}


void display(struct Stack st)
{
  for(int i = st.top; i >= 0; i--)
    printf("%d ", st.S[i]);
  printf("\n");
}

int peek(struct Stack st, int index)
{
  // if(index < 0 || index > st.top)
  int x = -1;
  if(st.top-index+1 < 0 || index <= 0)
  {
    printf("Invalid index\n");
    return -1;
  }
  x =  st.S[st.top-index+1];
  return x;
}

int isEmpty(struct Stack st)
{
  return st.top == -1;
}

int isFull(struct Stack st)
{
  return st.top == st.size - 1;
}

int stackTop(struct Stack st)
{
  if(!isEmpty)
    return st.S[st.top];
  return -1;
}

int main (void)
{
  struct Stack s;
  create(&s);
  push(&s, 100);
  push(&s, 90);
  push(&s, 80);
  // pop(&s);
  // pop(&s);
  // pop(&s);
  int index = 4;
  printf("Value at index %d of stack = %d\n", index, peek(s, index));
  display(s);
  free(s.S);
  return 0;
}
