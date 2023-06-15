#include <stdio.h>
#include <stdlib.h>

struct Queue
{
  struct Node *front;
  struct Node *rear;
};

struct Node
{
  int data;
  struct Node *next;
};

void enqueue(struct Node **front, struct Node **rear, int x)
{
  struct Node *p = *front;
  struct Node *q = *rear;

  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if(temp == NULL)
    printf("Queue is full\n");
  else
  {
    temp->data = x;
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

int dequeue(struct Node **front)
{
  int x=-1;
  struct Node *p = *front;
  if(p == NULL)
    printf("Queue is empty\n");
  else
  {
    struct Node *temp = p;
    *front=p->next;
    x=temp->data;
    free(temp);
  }
  return x;
}

void display(struct Node *front)
{
  while(front)
  {
    printf("%d ", front->data);
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

  struct Queue q2;
  q2.front=NULL;
  q2.rear=NULL;

  // struct Node *front1 = NULL;
  // struct Node *rear1 = NULL;

  enqueue(&q1.front, &q1.rear, 1) ;
  enqueue(&q1.front, &q1.rear, 2) ;
  enqueue(&q1.front, &q1.rear, 3) ;
  enqueue(&q1.front, &q1.rear, 4) ;
  enqueue(&q1.front, &q1.rear, 5) ;

  display(q1.front);

  printf("%d was dequeued\n", dequeue(&q1.front));
  printf("%d was dequeued\n", dequeue(&q1.front));

  display(q1.front);

  freeList(q1.front);

  printf("##########################\n");

  enqueue(&q2.front, &q2.rear, 10) ;
  enqueue(&q2.front, &q2.rear, 11) ;
  enqueue(&q2.front, &q2.rear, 12) ;
  enqueue(&q2.front, &q2.rear, 13) ;
  enqueue(&q2.front, &q2.rear, 14) ;

  display(q2.front);

  printf("%d was dequeued\n", dequeue(&q2.front));
  printf("%d was dequeued\n", dequeue(&q2.front));

  display(q2.front);

  freeList(q2.front);


  return 0;
}