#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  struct Node *front;
  struct Node *rear;
};

struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
};

struct Node
{
  struct TreeNode *treeNode;
  struct Node *next;
};

void enqueue(struct Node **front, struct Node **rear, struct  TreeNode *x)
{
  struct Node *p = *front;
  struct Node *q = *rear;

  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if(temp == NULL)
    printf("Queue is full\n");
  else
  {
    temp->treeNode = x;
    temp->next = NULL;
    if(p == NULL)
      *front = *rear = temp;
    else
    {
      q->next = temp;
      *rear = temp;
    }
  }
}

struct  TreeNode * dequeue(struct Node **front)
{
  struct  TreeNode *x = NULL;
  struct Node *p = *front;
  if(p == NULL)
    printf("Queue is empty\n");
  else
  {
    struct Node *temp = p;
    *front=p->next;
    x=temp->treeNode;
    free(temp);
  }
  return x;
}

void freeList(struct TreeNode *p)
{
  if(p)
  {
    freeList(p->lchild);
    freeList(p->rchild);
    free(p);
  } 
}

#endif