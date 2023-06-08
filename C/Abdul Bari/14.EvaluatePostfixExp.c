//Add for 2 digit numbers ??

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    x=p->data;
    *top = p->next;
    free(p);
  }
  return x;
}

int isOperand(char x)
{
  if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') return 0;
  return 1;
}

int evalPostfix(char *postfix)
{
  struct Node *top = NULL;
  int x1, x2, result, out;

  for(int i=0; postfix[i] != '\0'; i++)
  {
    if(isOperand(postfix[i]))
      push(&top, postfix[i] - '0');
    else
    {
      x2=pop(&top);
      x1=pop(&top);
      switch (postfix[i])
      {
      case '+': result = x1+x2; break;
      case '-': result = x1-x2; break;
      case '*': result = x1*x2; break;
      case '/': result = x1/x2; break;
      }
      push(&top, result);
    }
  }
  free(top);
  return result;
}

int main (void)
{
  char *postfix = "234*+82/-";
  printf("Result = %d\n", evalPostfix(postfix));
  return 0;
}