#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Node *create_tree(int key)
{
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  root->data = key;
  root->lchild = root->rchild = NULL;
  return root;
}

void insert(struct Node *root, int key)
{
  if(!root) return;
  struct Node *x = root;
  struct Node *tail = NULL;
  while(x)
  {
    tail=x;
    if(key>x->data)
      x=x->rchild;
    else if(key<x->data)
      x=x->lchild;
    else
      return;
  }
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = key;
  temp->lchild = temp->rchild = NULL;
  
  if(key<tail->data) tail->lchild = temp;
  else tail->rchild = temp;
}

struct Node *recursive_insert(struct Node *root, int key)
{
  struct Node *x = root;
  if(!x)
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->lchild = temp->rchild = NULL;
    return temp;
  }
  if(key<x->data)
    x->lchild = recursive_insert(x->lchild, key);
  if(key>x->data)
    x->rchild = recursive_insert(x->rchild, key);
  return x;
}

struct Node *search(struct Node *x, int key)
{
  // struct Node *x = root;
  while(x)
  {
    if(x->data == key)
      return x;
    else if(key > x->data)
      x=x->rchild;
    else
      x=x->lchild;
  }
  printf("Key not found\n");
  return NULL;
}

struct Node *recursive_search(struct Node *x, int key)
{
  if(x)
  {
    if(key > x->data)
      return recursive_search(x->rchild, key);
    if(key < x->data)
      return recursive_search(x->lchild, key);
    return x;
  }
  else{
    printf("Key not found\n");
    return NULL;
  }
}

int height(struct Node *p)
{
  if(!p) return 0;
  int x = height(p->lchild);
  int y = height(p->rchild);
  return x>y ? x+1 : y+1;
}

struct Node *inorder_predecessor(struct Node *p)
{
  while(p && p->rchild)
    p=p->rchild;
  return p;
}

struct Node *inorder_successor(struct Node *p)
{
  while(p && p->lchild)
    p=p->lchild;
  return p;
}

struct Node *recursive_delete(struct Node *p, int key)
{
  struct Node *q = NULL;
  if(!p)
    return NULL;
  
  if(!p->lchild && !p->rchild)
  {
    free(p);
    return NULL;
  }

  if(key < p->data)
    p->lchild = recursive_delete(p->lchild, key);
  else if(key > p->data)
    p->rchild = recursive_delete(p->rchild, key);
  else
  {
    if(height(p->lchild) > height(p->rchild))
    {
      q=inorder_predecessor(p->lchild);
      p->data = q->data;
      p->lchild=recursive_delete(p->lchild, q->data);
    }
    else
    {
      q=inorder_successor(p->rchild);
      p->data = q->data;
      p->rchild=recursive_delete(p->rchild, q->data);
    }
  }
  return p;
}

void free_tree(struct Node *root)
{
  if(root)
  {
    free_tree(root->lchild);
    free_tree(root->rchild);
    free(root);
  }
}

void inorder_traversal(struct Node *root)
{
  if(root)
  {
    inorder_traversal(root->lchild);
    printf("%d ", root->data);
    inorder_traversal(root->rchild);
  }
}

int main(void)
{
  struct Node *tree1 = create_tree(50);
  // insert(tree1, 5);
  // insert(tree1, 20);
  // insert(tree1, 8);
  // insert(tree1, 30);

  recursive_insert(tree1, 10);
  recursive_insert(tree1, 40);
  recursive_insert(tree1, 20);
  recursive_insert(tree1, 30);

  recursive_delete(tree1, 20);

  inorder_traversal(tree1);
  printf("\n");
  
  int key = 20;
  printf("Search: %d\n", search(tree1, key) ? search(tree1, key)->data : -1);
  printf("Recursive search: %d\n", recursive_search(tree1, key) ? recursive_search(tree1, key)->data : -1);
  
  free_tree(tree1);
  return 0;
}