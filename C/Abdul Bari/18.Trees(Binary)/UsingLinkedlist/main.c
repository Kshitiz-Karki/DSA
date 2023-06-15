#include <stdio.h>
#include "Queue.h"

void createBinarytree( struct Queue **q , struct TreeNode **tn)
{
  struct Queue *queue = *q;
  struct TreeNode *treeNode = NULL;
  
  int x=-1;
  printf("Enter root value: ");
  scanf("%d", &x);
  treeNode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
  treeNode->data = x;
  treeNode->lchild = treeNode->rchild = NULL;

  enqueue(&queue->front, &queue->rear, treeNode);

  while(queue->front)
  {
    struct TreeNode *p = NULL; 
    struct TreeNode *temp = NULL;
    p=dequeue(&queue->front);
    printf("Enter left child of %d :", p->data);
    scanf("%d", &x);
    if(x != -1)
    {
      temp=(struct TreeNode *)malloc(sizeof(struct TreeNode));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      p->lchild = temp;
      enqueue(&queue->front, &queue->rear, temp);
    }

    printf("Enter right child of %d :", p->data);
    scanf("%d", &x);
    if(x != -1)
    {
      temp=(struct TreeNode *)malloc(sizeof(struct TreeNode));
      temp->data = x;
      temp->lchild = temp->rchild = NULL;
      p->rchild = temp;
      enqueue(&queue->front, &queue->rear, temp);
    }
  }
  *tn = treeNode;
}

void preorderTraversal(struct TreeNode *p)
{
  if(p)
  {
    printf("%d ", p->data);
    preorderTraversal(p->lchild);
    preorderTraversal(p->rchild);
  }
}

void inorderTraversal(struct TreeNode *p)
{
  if(p)
  {
    inorderTraversal(p->lchild);
    printf("%d ", p->data);
    inorderTraversal(p->rchild);
  }
}

void postorderTraversal(struct TreeNode *p)
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
  struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
  q1->front = NULL;
  q1->rear=NULL;

  struct TreeNode *tn1 = NULL;
  
  createBinarytree(&q1, &tn1);
  printf("########################\n");
  printf("Preorder traversal: ");
  preorderTraversal(tn1);
  printf("\n");
  printf("Postorder traversal: ");
  postorderTraversal(tn1);
  printf("\n");
  freeList(tn1);
  free(q1);
  return 0;
}