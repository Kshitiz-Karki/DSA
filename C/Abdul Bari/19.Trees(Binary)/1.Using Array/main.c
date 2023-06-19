#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

void createBinarytree(struct Queue *queue)
{
  queue->root=NULL;
  struct Node *p, *temp;
  int x;
  createQueue(queue, 100);
  printf("Enter root value: ");
  scanf("%d", &x);
  queue->root=(struct Node *)malloc(sizeof(struct Node));
  queue->root->data = x;
  queue->root->lchild = queue->root->rchild = NULL;
  enqueue(queue, queue->root);

  while(!isEmpty(*queue))
  {
    p=dequeue(queue);
    printf("Enter left child of %d :", p->data);
    scanf("%d", &x);
    if(x != -1)
    {
      temp = (struct Node *)malloc(sizeof(struct Node));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      p->lchild = temp;
      enqueue(queue, temp);
    }

    printf("Enter right child of %d :", p->data);
    scanf("%d", &x);
    if(x != -1)
    {
      temp = (struct Node *)malloc(sizeof(struct Node));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      p->rchild = temp;
      enqueue(queue, temp);
    }
  }
  
}

void preorderTraversal(struct Node *p)
{
  if(p)
  {
    printf("%d ", p->data);
    preorderTraversal(p->lchild);
    preorderTraversal(p->rchild);
  }
}

void inorderTraversal(struct Node *p)
{
  if(p)
  {
    inorderTraversal(p->lchild);
    printf("%d ", p->data);
    inorderTraversal(p->rchild);
  }
}

void postorderTraversal(struct Node *p)
{
  if(p)
  {
    postorderTraversal(p->lchild);
    postorderTraversal(p->rchild);
    printf("%d ", p->data);
  }
}

void iterativePreOrderTraversal(struct Node *p, struct Stack *stack)
{
  struct Stack st;
  createStack(&st, 50);
  while(p || !isStackEmpty(st))
  {
    if(p)
    {
      printf("%d ", p->data);
      push(&st, p);
      p=p->lchild;
    }
    else
    {
      p=pop(&st);
      p=p->rchild;
    }
  }
  *stack = st;
}

void iterativeInOrderTraversal(struct Node *p, struct Stack *stack)
{
  struct Stack st;
  createStack(&st, 50);
  while(p || !isStackEmpty(st))
  {
    if(p)
    {
      push(&st, p);
      p=p->lchild;
    }
    else
    {
      p=pop(&st);
      printf("%d ", p->data);
      p=p->rchild;
    }
  }
  *stack = st;
}

void iterativePostOrderTraversal(struct Node *p, struct Stack *stack)
{
  struct Stack st;
  long int address;
  createStack(&st, 50);
  while(p || !isStackEmpty(st))
  {
    if(p)
    {
      push(&st, p);
      p=p->lchild;
    }
    else
    {
      address=(long int)pop(&st);
      if(address > 0)
      {
        push(&st, (struct Node *)(-address));
        p=((struct Node *)address)->rchild;
      }
      else{
        printf("%d ", ((struct Node *)(-address))->data);
        p=NULL;
      }
    }
  }
  *stack = st;
}

void LevelOrderTraversal(struct Node *p, struct Queue *queue)
{
  struct Queue q;
  createQueue(&q, 50);
  printf("%d ", p->data);
  enqueue(&q, p);

  while(!isEmpty(q))
  {
    p=dequeue(&q);
    if(p->lchild)
    {
      printf("%d ", p->lchild->data);
      enqueue(&q, p->lchild);
    }
    if(p->rchild)
    {
      printf("%d ", p->rchild->data);
      enqueue(&q, p->rchild);
    }
  }
  *queue = q;
}

int countNodes(struct Node *root)
{
  if(root)
    return countNodes(root->lchild) + countNodes(root->rchild) + 1;
  return 0;
}

int tree_height(struct Node *root)
{
  if(!root)
    return 0;
  int x=0;
  int y=0;
  x=tree_height(root->lchild);
  y=tree_height(root->rchild);
  if(x>y)
    return x+1;
  else
    return y+1;
}

int sum_nodes(struct Node *root)
{
  if(root)
    return sum_nodes(root->lchild) + sum_nodes(root->rchild) + root->data;
  return 0;
}

int second_degree_nodes_count(struct Node *root)
{
  int x=0, y=0;
  if(root)
  {
    x=second_degree_nodes_count(root->lchild);
    y=second_degree_nodes_count(root->rchild);
    if(root->lchild && root->rchild)
      return x+y+1;
    else
      return x+y;
  }
  return 0;
}

int main(void)
{
  struct Queue q1 ;
  createBinarytree(&q1);
  printf("########################\n");
  printf("Preorder traversal: ");
  preorderTraversal(q1.root);
  printf("\n");
  printf("Inorder traversal: ");
  inorderTraversal(q1.root);
  printf("\n");
  printf("Postorder traversal: ");
  postorderTraversal(q1.root);
  printf("\n");
  printf("########################\n");
  printf("Iterative Preorder traversal: ");
  struct Stack st1;
  iterativePreOrderTraversal(q1.root, &st1);
  printf("\n");
  free(st1.S);

  printf("Iterative Inorder traversal: ");
  struct Stack st2;
  iterativeInOrderTraversal(q1.root, &st2);
  printf("\n");
  free(st2.S);

  printf("Iterative Postorder traversal: ");
  struct Stack st3;
  iterativePostOrderTraversal(q1.root, &st3);
  printf("\n");
  free(st3.S);

  printf("Levelorder traversal: ");
  struct Queue q2;
  LevelOrderTraversal(q1.root, &q2);
  printf("\n");

  printf("Number of nodes - %d\n", countNodes(q1.root));
  printf("Tree height - %d\n", tree_height(q1.root));
  printf("Sum of nodes - %d\n", sum_nodes(q1.root));
  printf("second_degree_nodes_count - %d\n", second_degree_nodes_count(q1.root));

  free(q2.Q);

  freeList(&q1.root);
  free(q1.Q );

  // printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  // struct Queue q2 ;
  // createBinarytree(&q2);
  // preorderTraversal(q2.root);
  // freeList(&q2.root);
  // free(q2.Q );
  return 0;
}