#include <stdio.h>
#include <stdlib.h>

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
  struct Node *front1 = NULL;
  struct Node *rear1 = NULL;

  enqueue(&front1, &rear1, 1) ;
  enqueue(&front1, &rear1, 2) ;
  enqueue(&front1, &rear1, 3) ;
  enqueue(&front1, &rear1, 4) ;
  enqueue(&front1, &rear1, 5) ;

  display(front1);

  printf("%d was dequeued\n", dequeue(&front1));
  printf("%d was dequeued\n", dequeue(&front1));

  display(front1);

  freeList(front1);
  return 0;
}