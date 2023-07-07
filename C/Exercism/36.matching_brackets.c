#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//helper functions to create stack data structure for pushing and popping brackets
// typedef struct
// {
//   int size;
//   int top;
//   char *S;
// }stack_t;

// stack_t *create(int size)
// {
//   stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
//   stack->size = size;
//   stack->top = -1;
//   stack->S = (char *)malloc(size + 1);
//   return stack;
// }

// void push(stack_t *st, char x)
// {
//   if(st->top == st->size - 1)
//     printf("Stack overflow\n");
//   else
//   {
//     st->top++;
//     st->S[st->top] = x;
//   }
// }

// char pop(stack_t *st)
// {
//   char x = '\0';
//   if(st->top == -1)
//     printf("Stack Underflow\n");
//   else
//     x = st->S[st->top--];
//   return x;
// }


// bool isEmpty(stack_t *st)
// {
//   return st->top == -1;
// }

// int main (void)
// {
//   stack_t *s = create(10);
//   // create(&s);
//   push(s, 'A');
//   push(s, 'B');
//   push(s, 'C');
//   printf("popped value - %c\n", pop(s));
//   // pop(s);
//   display(s);
//   free(s->S);
//   free(s);
//   return 0;
// }


// bool is_paired(const char *input)
// {
//   if(!input) return true;
//   bool is_matching = false;
//   int len = strlen(input);
//   stack_t *s = create(len);

//   for(int i=0; input[i] != '\0'; i++)
//   {
//     if(input[i] == '(' || input[i] == '[' || input[i] == '{')
//       push(s, input[i]);
//     if(input[i] == ')' || input[i] == ']' || input[i] == '}')
//     {
//       if(isEmpty(s))
//         return false;
//       char opening_bracket = pop(s);
//       if(!((opening_bracket == '(' && input[i] == ')') || (opening_bracket == '[' && input[i] == ']') || (opening_bracket == '{' && input[i] == '}')))
//         return false;
//     }
//   }
//   if(isEmpty(s))
//     is_matching = true;
//   free(s->S);
//   free(s);
//   return is_matching;
// }

//alternate solution without stack
bool is_paired(const char *input)
{
  if(!input) return true;
  int len = strlen(input), j=0;
  char brackets[len+1];

  for(int i=0; input[i] != '\0'; i++)
  {
    if(input[i] == '(' || input[i] == '[' || input[i] == '{')
      brackets[j++] = input[i];
    if(input[i] == ')' || input[i] == ']' || input[i] == '}')
    {
      if((input[i] == ')' && brackets[j-1] == '(') || (input[i] == '}' && brackets[j-1] == '{') || (input[i] == ']' && brackets[j-1] == '['))
        j--;
      else
        return false;
    }
  }
  if(j == 0) return true; else return false;
}

int main(void)
{
  // const char *input = ")({}";
  // const char *input = "";
  // const char *input =
  //      "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)";
  const char *input = "([{}({}[])])";
  // "([({"
  printf("Is matching - %d\n", is_paired(input));
  return 0;
}

