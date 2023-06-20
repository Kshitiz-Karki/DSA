#include <stdio.h>
#include "Stack.h"



struct bst_node *create_BST_preorder(int preorder[], int size)
{
  struct Node *stack = NULL;
  struct bst_node *t = NULL;
  int i=0;
  struct bst_node *root = (struct bst_node *)malloc(sizeof(struct bst_node));
  root->data = preorder[i++];
  root->lchild = root->rchild = NULL;

  struct bst_node *p = root;
  
  while(i<size)
  {
    if(preorder[i] < p->data)
    {
      t = (struct bst_node *)malloc(sizeof(struct bst_node));
      t->data = preorder[i++] ;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      push(&stack, p);
      p=t;
    }
    else
    {
      if(preorder[i] > p->data && preorder[i] < (!pop(&stack) ? 5000 :  pop(&stack)->data))
      {
        t = (struct bst_node *)malloc(sizeof(struct bst_node));
        t->data = preorder[i++] ;
        t->lchild = t->rchild = NULL;
        p->rchild = t;
        p=t;
      }
      else
        p=pop(&stack);
    }
  }
  return root;
}

void inorder_traversal(struct bst_node *root)
{
  if(root)
  {
    inorder_traversal(root->lchild);
    printf("%d ", root->data);
    inorder_traversal(root->rchild);
  }
}

void free_tree(struct bst_node *root)
{
  if(root)
  {
    free_tree(root->lchild);
    free_tree(root->rchild);
    free(root);
  }
}

int main(void)
{
  int preorder[] = {30, 20, 10, 15, 25, 40, 50, 45};
  struct bst_node *root = create_BST_preorder(preorder, 8);
  inorder_traversal(root);
  free_tree(root);
  return 0;
}