//Optimise and make it more readable wherever possible!!

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// #define ARRAY_SIZE 50

// char get_operator(char starting_char, int position, const char *question)
// {
//   char operator;
//   char *operator_type = (char *)calloc(14, sizeof(char));
//   switch (starting_char)
//   {
//   case 'p':
//     strncpy(operator_type,question+position,4);
//     if(strcmp(operator_type, "plus") == 0)
//       operator = '+';
//     free(operator_type);
//     break;
//   case 'd':
//     strncpy(operator_type,question+position,10);
//     if(strcmp(operator_type, "divided by") == 0)
//       operator = '/';
//     free(operator_type);
//     break;
//   case 'm':
//     if(question[position+1] == 'u')
//     {
//       strncpy(operator_type,question+position,13);
//       if(strcmp(operator_type, "multiplied by") == 0)
//         operator = '*';
//     }
//     else
//     {
//       strncpy(operator_type,question+position,5);
//       if(strcmp(operator_type, "minus") == 0)
//         operator = '-';
//     }
//     free(operator_type);
//     break;
//   }
//   return operator;
// }

// int is_operator(char x)
// {
//   if(x == '+' || x == '-' || x == '*' || x == '/') return 1;
//   return 0;
// }

// int is_valid(char expression[], int size)
// {
//   if(size == 1) return 1;
//   const char operators[] = "+-*/";
//   if((strchr(operators, expression[0]) && expression[1] == ' ') || expression[size-1] == ' ')
//     return 0;

//   for(int i=1; i<size-1; i++)
//   {
//     if(strchr(operators, expression[i]))
//     {
//       if(strchr(operators, expression[i-2]) && expression[i] != '-' && !strchr(operators, expression[i+1]) )
//         return 0;
//     }
//   }

//   if(strchr(operators, expression[size-1]))
//     return 0;
//   return 1;
// }

// char *infix_to_postfix(char *infix, int size)
// {
//   int j=0;
//   char *postfix = (char *)calloc(2*size + 1, sizeof(char));
//   char stack_top = '0';
//   for(int i=0; i<size; i++)
//   {   
//     if(is_operator(infix[i]) && infix[i+1] == ' ')
//     {
//       postfix[j++] = ' ';
//       if(stack_top == '0')
//         stack_top = infix[i];
//       else
//       {
//         postfix[j++] = stack_top;
//         postfix[j++] = ' ';
//         stack_top = infix[i];
//       }
//     }
//     else
//     {
//       if(infix[i] != ' ')
//       {
//       while(infix[i] != ' ' && infix[i] != '\0')
//         postfix[j++] = infix[i++] ;
//       }
//     }
//   }
//   if(stack_top != '0')
//   {
//     postfix[j++] = ' ';
//     postfix[j++] = stack_top;
//   }
//   postfix[j] = '\0';
//   return postfix;
// }

// int evaluate_postfix(char *postfix)
// {
//   if(strlen(postfix) == 1)
//    return atoi(postfix);
//   int j, result, stack_index=0, x1, x2;
//   int stack[2] = {0};
//   char *operand ;
//   for(size_t i=0; i<strlen(postfix); i++)
//   {
//     j=i;
//     if( is_operator(postfix[i]) && (postfix[i+1] == ' ' || i == strlen(postfix)-1) ) 
//     {
//       x2=stack[1];
//       x1=stack[0];
//       switch (postfix[i])
//       {
//       case '+': result = x1+x2; break;
//       case '-': result = x1-x2; break;
//       case '*': result = x1*x2; break;
//       case '/': result = x1/x2; break;
//       }
//       stack[stack_index++] = result;
//       i = i+1;
//     }
//     else
//     {
//       while(postfix[j] != ' ')
//         j++;
//       operand = (char *)calloc(10, sizeof(char));
//       strncpy(operand,postfix+i,j);
//       stack[stack_index++] = atoi(operand);
//       stack_index = stack_index % 2;
//       i=j;
//     }
//   }
//   return result;
// }

// bool answer(const char *question, int *result)
// {
//   char operator;
//   char *substring = (char *)calloc(9, sizeof(char));
//   strncpy(substring,question+0,8);

//   char infix_expression[ARRAY_SIZE];
//   int j=0;
 
//   if(strcmp(substring, "What is ") == 0)
//   {
//     int is_prev_char_operator = 0;
//     for(size_t i=8; i<strlen(question)-1; i++)
//     {
//       char current_char = question[i];
//       if((current_char >= 48 && current_char <= 57) || current_char == 45)
//       {
//         infix_expression[j++] = current_char;
//         is_prev_char_operator = 0;
//       }
//       else if((current_char == 'p' || current_char == 'm' || current_char == 'd') && !is_prev_char_operator)
//       {
//         is_prev_char_operator = 1;
//         operator = get_operator(current_char, i, question);
//         if(operator == '+' || operator == '-' || operator == '*' || operator == '/')
//         {
//           infix_expression[j++] = ' ';
//           infix_expression[j++] = operator;
//           infix_expression[j++] = ' ';
//           switch (operator)
//           {
//           case '+':
//             i += 4;
//             break;
//           case '-':
//             i += 5;
//             break;
//           case '*':
//             i += 13;
//             break;
//           case '/':
//             i += 10;
//             break;
//           }
//         }
//       }
//       else if(current_char == 32) continue;
//       else return false;
//     }
//     infix_expression[j] = '\0';
//   }
//   else
//     return false;
//   //validate,, if validation fails then return false else convert from infix to postfix and then evaluate postfix expression to get the answer & also return true!!!!
//   if(!is_valid(infix_expression, strlen(infix_expression)))
//     return false;
  
//   char *postfix = infix_to_postfix(infix_expression, strlen(infix_expression));
//   *result = evaluate_postfix(postfix);
//   return true;
// }

bool answer(const char *question, int *result)
{
  int operand = 0;
  int current_pointer = 0;
  if (!sscanf(question, "What is %d%n", result, &current_pointer)) 
    return false;
  else question += current_pointer + 1;

  while (*question)
  {
    if(sscanf(question, "plus %d%n", &operand, &current_pointer))
      *result += operand;
    else if(sscanf(question, "minus %d%n", &operand, &current_pointer))
      *result -= operand;
    else if(sscanf(question, "multiplied by %d%n", &operand, &current_pointer))
      *result *= operand;
    else if(sscanf(question, "divided by %d%n", &operand, &current_pointer))
      *result /= operand;
    else
      return false;
    question += current_pointer + 1;
  }
  return true;                            
}

int main(void)
{
  // char *question = "What is 5 cubed?";
  char *question = "What is 1 plus 2?";
  // char *question = "What is -3 multiplied by 25?";
  int result;
  // answer(question, &result);
  printf("Is valid - %d\n", answer(question, &result));
  printf("result - %d\n", result);

  // char expression[] = "5++1";
  // printf("Is valid - %d\n", is_valid(expression, 3));

  // printf("Is operator - %d\n", is_operator('9'));

  // char *infix = "4+66-10*100";
  // char *postfix = infix_to_postfix(infix, 11);
  // printf("postfix - %s!!!\n", postfix);

  // char *postfix = "4 66 + 10 - 100 *";
  // printf("result - %d\n", evaluate_postfix(postfix));
  return 0;
}