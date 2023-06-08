//Add for {}, [] ??

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char pop(struct Node **top)
{
  char x;
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

int OutstackPrecedence(char x)
{
  if(x == '+' || x == '-') return 1;
  if(x == '*' || x == '/') return 3;
  if(x == '^') return 6;
  if(x == '(') return 7;
  if(x == ')') return 0;
  return 0;
}

int InstackPrecedence(char x)
{
  if(x == '+' || x == '-') return 2;
  if(x == '*' || x == '/') return 4;
  if(x == '^') return 5;
  if(x == '(') return 0;
  if(x == ')') return -1;
  return 0;
}

int isOperand(char x)
{
  if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')') return 0;
  return 1;
}

char *infixToPostfix(char *infix, struct Node **stack)
{
  struct Node *top = *stack;
  char *postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
  if(!postfix)
    return NULL;
  
  int i=0;
  int j=0;
  while(infix[i] != '\0')
  {
    if(isOperand(infix[i]))
      postfix[j++] = infix[i++];
    else
    {
      if(!top || (OutstackPrecedence(infix[i]) > InstackPrecedence(top->data) && InstackPrecedence(infix[i]) != -1))
        push(&top, infix[i++]);
      else
      {
        if(InstackPrecedence(top->data) > OutstackPrecedence(infix[i]))
          postfix[j++] = pop(&top);
        if(InstackPrecedence(top->data) == OutstackPrecedence(infix[i]))
          pop(&top);
        i++;
      }
    }
  }

  while(top!= NULL)
    postfix[j++] = pop(&top);

  postfix[j] = '\0';
  free(top);
  return postfix;
}

int main (void)
{
  struct Node *top = NULL;
  char *infix = "((a+b)*c)-d^e^f";

  char *postfix = infixToPostfix(infix, &top);
  printf("%s\n", postfix);
  free(postfix);
  return 0;
}