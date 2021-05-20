#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
} * Node;

void inorder(Node n)
{
	if (n)
	{
		inorder(n->left);
		printf("%d ", n->val);
		inorder(n->right);
	}
}

Node insert()
{
	int val;
	int check;
	printf("Enter the element : ");
	scanf("%d", &val);
	Node n = (Node)malloc(sizeof(struct node));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	printf("Do you want to insert left child of %d? (1 for Yes, 0 for No) : ", val);
	scanf("%d", &check);
	if (check)
		n->left = insert();
	printf("Do you want to insert right child of %d? (1 for Yes, 0 for No) : ", val);
	scanf("%d", &check);
	if (check)
		n->right = insert();
	return n;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(Node head)
{
	if (head == NULL)
	{
		return 0;
	}
	return max(height(head->left), height(head->right)) + 1;
}

void diameter(Node cur, int *max)
{
	if (cur)
	{
		int curDia = height(cur->left) + height(cur->right) + 1;
		if (curDia > *max)
		{
			*max = curDia;
		}
		diameter(cur->left, max);
		diameter(cur->right, max);
	}
}

int main()
{
	Node head = insert();
	printf("The inorder is : ");
	inorder(head);
	int diam = INT_MIN;
	diameter(head, &diam);
	printf("\nThe diameter of the binary tree is : %d\n", diam);
	return 0;
}