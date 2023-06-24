//In computer science, an AVL tree (named after inventors Adelson-Velsky and Landis) is a self-balancing binary search tree. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property.

//Source: Wikipedia

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
};

struct Node *create_tree(int key)
{
  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  root->data = key;
  root->height = 1;  //taking 1 instead of 0
  root->lchild = root->rchild = NULL;
  return root;
}

int calculate_node_height(struct Node *p)
{
  int height_left_sub_tree = p && p->lchild ? p->lchild->height : 0;
  int height_right_sub_tree = p && p->rchild ? p->rchild->height : 0;

  return height_left_sub_tree > height_right_sub_tree ? height_left_sub_tree+1 : height_right_sub_tree+1;  
}

int calculate_balance_factor(struct Node *p)
{
  int height_left_sub_tree = p && p->lchild ? p->lchild->height : 0;
  int height_right_sub_tree = p && p->rchild ? p->rchild->height : 0;

  return height_left_sub_tree - height_right_sub_tree;
}

struct Node *LLRotation(struct Node *p, struct Node** root)
{
  struct Node *pl = p->lchild; // pl = p's left child
  struct Node *plr = pl->rchild; // plr = p's left's right child

  pl->rchild = p;
  p->lchild = plr;

  p->height = calculate_node_height(p);
  pl->height = calculate_node_height(pl);

  if(*root == p)
    *root = pl;
  return pl;
}

struct Node *LRRotation(struct Node *p, struct Node** root)
{
  struct Node *pl = p->lchild;
  struct Node *plr = pl->rchild;

  pl->rchild = plr->lchild;
  p->lchild = plr->rchild;

  plr->lchild = pl;
  plr->rchild = p;

  plr->height = calculate_node_height(plr);
  p->height = calculate_node_height(p);
  pl->height = calculate_node_height(pl);

  if(*root = p)
    *root = plr;
  return plr;
}

struct Node *RRRotation(struct Node *p, struct Node** root)
{
  return NULL;
}

struct Node *RLRotation(struct Node *p, struct Node** root)
{
  return NULL;
}

struct Node *recursive_insert(struct Node **root, int key)
{
  struct Node *p = *root;
  if(!p)
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = key;
    temp->height = 1;  //taking 1 instead of 0
    temp->lchild = temp->rchild = NULL;
    return temp;
  }
  if(key<p->data)
    p->lchild = recursive_insert(&p->lchild, key);
  if(key>p->data)
    p->rchild = recursive_insert(&p->rchild, key);

  //while returning, height of each node gets updated from initial value of 1 to expected value
  p->height = calculate_node_height(p);

  //code for performing rotation
  //find balance factor of node p
  if(calculate_balance_factor(p) == 2 /*means the node is imbalance on left side since the value is positive*/ && calculate_balance_factor(p->lchild) == 1)
    return LLRotation(p, root);
  else if (calculate_balance_factor(p) == 2 /*means the node is imbalance on left side since the value is positive*/ && calculate_balance_factor(p->lchild) == -1)
    return LRRotation(p, root);
  else if (calculate_balance_factor(p) == -2 /*means the node is imbalance on left side since the value is positive*/ && calculate_balance_factor(p->lchild) == -1)
    return RRRotation(p, root);
  else if (calculate_balance_factor(p) == -2 /*means the node is imbalance on left side since the value is positive*/ && calculate_balance_factor(p->lchild) == 1) 
    return RLRotation(p, root); 

  return p;
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

void free_tree(struct Node *root)
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
  // struct Node *root = create_tree(10);
  // recursive_insert(&root, 5);
  // recursive_insert(&root, 2);

  struct Node *root = create_tree(50);
  recursive_insert(&root, 10);
  recursive_insert(&root, 20);

  inorder_traversal(root);
  printf("\n");

  free_tree(root);

  return 0;
}