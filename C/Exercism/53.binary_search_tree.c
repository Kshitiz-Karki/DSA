#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;

struct node {
   node_t *right;
   node_t *left;
   int data;
};

node_t *build_tree(int *tree_data, size_t tree_data_len);
void free_tree(node_t *tree);
int *sorted_data(node_t *tree);

void inorder_traversal(node_t *ptr)
{
  if(ptr)
  {
    inorder_traversal(ptr->left);
    printf("%d ", ptr->data);
    inorder_traversal(ptr->right);
  }
}

int tree_size(node_t *ptr)
{
  static int i=0;
  if(ptr)
  {
    tree_size(ptr->left);
    i++;
    tree_size(ptr->right);
  }
  return i;
}

int *sorted_data(node_t *tree)
{
  int tree_len = tree_size(tree);
  int *result = (int *)calloc(tree_len, sizeof(int));
  node_t *stack[tree_len];
  int stack_index = 0;
  int result_index = 0;

  while(1)
  {
    if(tree)
    {
      stack[stack_index++] = tree;
      tree = tree->left;
    }
    else if(stack_index > 0)
    {
      tree = stack[--stack_index];
      result[result_index++] = tree->data;
      tree = tree->right;
    }
    else
      break;
  }
  return result;
}

int main(void)
{
  // int arr[] = { 4, 2, 6, 1, 3, 5, 7 };
  int arr[] = { 2, 1 };
  size_t size = sizeof(arr)/sizeof(int);
  node_t *tree = build_tree(arr, size);
  inorder_traversal(tree);
  int tree_len = tree_size(tree);
  printf("tree_len - %d\n", tree_len);
  printf("\n#####################\n");
  int *data = sorted_data(tree);
  printf("\n#####################\n");
  for(int i=0; i<tree_len; i++)
    printf("%d ", data[i]);
  free_tree(tree);
  free(data);
  return 0;
}

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
  node_t *root = (node_t *)malloc(sizeof(node_t));
  root->data = tree_data[0];
  root->left = root->right = NULL;
  
  node_t *tail_node, *temp, *current_node = NULL;

  printf("root before - %p\n", root);
  printf("current_node before - %p\n", current_node);

  for(size_t i=1; i<tree_data_len; i++)
  {
    current_node = root;
    while(current_node)
    {
      tail_node = current_node;
      if(tree_data[i] <= current_node->data)
        current_node = current_node->left;
      else
        current_node = current_node->right;
    }
    temp = (node_t *)malloc(sizeof(node_t));
    temp->data = tree_data[i];
    temp->left = temp->right = NULL;

    if(tree_data[i] <= tail_node->data)
      tail_node->left = temp;
    else
      tail_node->right = temp;
  }
  printf("root after - %p\n", root);
  printf("current_node after - %p\n", current_node);
  return root;
}

void free_tree(node_t *tree)
{
  if(tree)
  {
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
  }
}