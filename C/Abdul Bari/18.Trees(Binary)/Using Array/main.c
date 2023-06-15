#include <stdio.h>
#include "Queue.h"

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

int main(void)
{
  struct Queue q1 ;
  createBinarytree(&q1);
  printf("########################\n");
  printf("Preorder traversal: ");
  preorderTraversal(q1.root);
  printf("\n");
  printf("Postorder traversal: ");
  postorderTraversal(q1.root);
  printf("\n");
  freeList(&q1.root);
  free(q1.Q );

  // printf("\n$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
  // struct Queue q2 ;
  // createBinarytree(&q2);
  // preorderTraversal(q2.root);
  // freeList(&q2.root);
  // free(q2.Q );
  return 0;
}