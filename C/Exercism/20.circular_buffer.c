#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef int buffer_value_t;

typedef struct{
  int front;
  int size;
  int start;
  int len;
  buffer_value_t *queue;
}circular_buffer_t;

circular_buffer_t *new_circular_buffer(int size)
{
  circular_buffer_t *buffer=(circular_buffer_t *)malloc(sizeof(circular_buffer_t));
  if(!buffer) return NULL;
  buffer->size = size;
  buffer->start = buffer->len = buffer->front = 0;
  buffer->queue = (buffer_value_t *)malloc(size * sizeof(buffer_value_t));
  if(!buffer->queue) return NULL;
  return buffer;
}

int write(circular_buffer_t *buffer, buffer_value_t x)
{
  if(buffer->len == buffer->size)
  {
    //buffer is full, cannot write
    errno = ENOBUFS;
    return EXIT_FAILURE;
  }
  buffer->queue[(buffer->start + buffer->len++)%buffer->size] = x;
  return EXIT_SUCCESS;
}

int read(circular_buffer_t *buffer, buffer_value_t *x)
{
  if(!buffer->len)
  {
    //buffer is empty, cannot read
    errno = ENODATA;
    return EXIT_FAILURE;
  }
  *x=buffer->queue[buffer->start];
  buffer->start = (buffer->start+1)%buffer->size;
  --buffer->len;
  buffer->front = (buffer->front+1) % buffer->size;
  return EXIT_SUCCESS;
}

int overwrite(circular_buffer_t *buffer, buffer_value_t x)
{
  if(buffer->len == buffer->size)
  {
    buffer->queue[buffer->start] = x;
    buffer->start = (buffer->start+1)%buffer->size;
  }
  else
    buffer->queue[(buffer->start + buffer->len++)%buffer->size] = x;
  return EXIT_SUCCESS;
}

void delete_buffer(circular_buffer_t *buffer)
{
  free(buffer->queue);
  free(buffer);
}

void clear_buffer(circular_buffer_t *buffer)
{
  buffer->len = 0;
}

void display(circular_buffer_t *buffer)
{
  // printf("start - %d\n", buffer->start);
  // printf("front - %d\n", buffer->front);
  // printf("len - %d\n", buffer->len);
  // printf("size - %d\n", buffer->size);

  int i = buffer->front;
  do
  {
    printf("%d ", buffer->queue[i]); 
    i++;
  }
  while(i < buffer->len);
  printf("\n");
}

int main(void)
{
  int x = 0;
  int *ptr = &x;
  circular_buffer_t *buffer = new_circular_buffer(2);
  write(buffer, 1);
  write(buffer, 2);
  display(buffer);
  printf("###########################\n");
  overwrite(buffer, 3);
  display(buffer);
  printf("###########################\n");
  read(buffer, ptr);
  display(buffer);
  printf("###########################\n");
  // printf("x - %d\n", x);
  // printf("*ptr - %d\n", *ptr);
    // display(buffer);


  delete_buffer(buffer);
  return 0;
}





