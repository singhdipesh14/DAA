#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  struct node *left;
  struct node *right;
  int val;
} * Node;

void inorder(Node tree)
{
  if (tree)
  {
    inorder(tree->left);
    printf("%d\t", tree->val);
    inorder(tree->right);
  }
}

void preorder(Node tree)
{
  if (tree)
  {
    printf("%d\t", tree->val);
    preorder(tree->left);
    preorder(tree->right);
  }
}

void postorder(Node tree)
{
  if (tree)
  {
    postorder(tree->left);
    postorder(tree->right);
    printf("%d\t", tree->val);
  }
}

void insert(Node *tree, int val)
{
  Node n = malloc(sizeof(struct node));
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  if (*tree == NULL)
  {
    *tree = n;
    return;
  }
  Node cur = *tree;
  Node prev = *tree;
  while (cur)
  {
    prev = cur;
    if ((cur->val) < val)
    {
      cur = cur->right;
    }
    else if ((cur->val) > val)
    {
      cur = cur->left;
    }
  }
  if (val > prev->val)
  {
    prev->right = n;
  }
  if (val < prev->val)
  {
    prev->left = n;
  }
}

void search(Node *tree, int val)
{
  if (*tree == NULL)
  {
    printf("\n**Element not found**\n");
    insert(tree, val);
    return;
  }
  Node cur = *tree;
  while (cur)
  {
    if (cur->val == val)
    {
      printf("\n**Key Found**\n");
      return;
    }
    else if (cur->val > val)
    {
      cur = cur->left;
    }
    else if (cur->val < val)
    {
      cur = cur->right;
    }
  }
  printf("\n**Element not Found**\n");
  insert(tree, val);
}

int main()
{
  int choice = 0, inp;
  Node tree = NULL;
  while (choice < 5)
  {
    printf("1)Search for item\n2)Inorder\n3)Preorder\n4)Postorder\n5)Exit\n");
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the value to be searched : ");
      scanf("%d", &inp);
      search(&tree, inp);
      break;
    case 2:
      printf("\n");
      if (tree == NULL)
      {
        printf("Tree is Empty, nothing to print.\n");
        continue;
      }
      inorder(tree);
      printf("\n");
      break;
    case 3:
      printf("\n");
      if (tree == NULL)
      {
        printf("Tree is Empty, nothing to print.\n");
        continue;
      }
      preorder(tree);
      printf("\n");
      break;
    case 4:
      printf("\n");
      if (tree == NULL)
      {
        printf("Tree is Empty, nothing to print.\n");
        continue;
      }
      postorder(tree);
      printf("\n");
      break;
    default:
      continue;
    }
  }
  return 0;
}