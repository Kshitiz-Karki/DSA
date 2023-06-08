#include <stdio.h>
#include <stdlib.h>

struct Node
{
  char data;
  struct Node *next;
};

void push(struct Node **p, char data)
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

void pop(struct Node **top)
{
  struct Node *p = *top;
  if(p == NULL)
    printf("Stack is empty.\n");
  else
  {
    *top = p->next;
    free(p);
  }
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

int isBalanced(struct Node **top, char *exp)
{
  for(int i=0; exp[i] != '\0'; i++)
  {
    if(exp[i] == '(')
      push(top, exp[i]);
    else if(exp[i] == ')')
    {
      if(*top == NULL)
        return 0;
      pop(top);
    }
  }
  if(*top == NULL)
    return 1;
  return 0;
}

int main (void)
{
  struct Node *top = NULL;
  char *exp = "((a+b) * (c+d)))";
  printf("Is balanced - %d\n", isBalanced(&top, exp));
  freeList(top);
}