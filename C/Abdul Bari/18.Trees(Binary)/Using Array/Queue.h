#ifndef Queue_h
#define Queue_h

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Queue
{
  int size;
  int front;
  int rear;
  struct Node **Q; //Node pointer to array Q
  struct Node *root;
};

void createQueue(struct Queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (struct Node **)malloc(size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
  if((q->rear+1)%q->size == q->front)
    printf("Queue is full\n");
  else
  {
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
  }
}

struct Node *dequeue(struct Queue *q)
{
  struct Node *x = NULL;
  if(q->rear == q->front)
    printf("Queue is empty\n");
  else
  {
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isEmpty(struct Queue q)
{
  return q.front == q.rear;
}

void freeList(struct Node **p)
{
  if(*p)
  {
    
    freeList(&(*p)->lchild);
    freeList(&(*p)->rchild);
    free((*p));
  } 
}

#endif