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

void display(struct Node *front)
{
  while(front)
  {
    // printf("%p ", front->treeNode);
    printf("%d ", front->treeNode->data);
    front = front->next;
  }
  printf("\n");
}

void freeList(struct Node *front)
{
  struct Node *temp = NULL;
  while(front)
  {
    temp = front;
    front=front->next;
    free(temp);
  }
}

int main (void)
{
  struct Queue q1;
  q1.front=NULL;
  q1.rear=NULL;

  struct TreeNode tn1;
  tn1.data = 10;
  tn1.lchild = NULL;
  tn1.rchild = NULL;

  struct TreeNode tn2;
  tn2.data = 20;
  tn2.lchild = NULL;
  tn2.rchild = NULL;

  struct TreeNode tn3;
  tn3.data = 30;
  tn3.lchild = NULL;
  tn3.rchild = NULL;

  struct TreeNode tn4;
  tn4.data = 40;
  tn4.lchild = NULL;
  tn4.rchild = NULL;

  enqueue(&q1.front, &q1.rear, &tn1) ;
  enqueue(&q1.front, &q1.rear, &tn2) ;
  enqueue(&q1.front, &q1.rear, &tn3) ;
  enqueue(&q1.front, &q1.rear, &tn4) ;

  printf("q1 - %p\n", q1);

  display(q1.front);

  printf("%p was dequeued\n", dequeue(&q1.front));
  printf("%p was dequeued\n", dequeue(&q1.front));

  display(q1.front);
  freeList(q1.front);
  return 0;
}