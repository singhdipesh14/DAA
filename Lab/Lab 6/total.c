#include <stdio.h>
#include <stdlib.h>

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

int cnt(Node head)
{
	if (head)
	{
		return 1 + cnt(head->right) + cnt(head->left);
	}
	return 0;
}

int main()
{
	Node head = insert();
	printf("The inorder is : ");
	inorder(head);
	int res = cnt(head);
	printf("\nThe number of nodes is : %d\n", res);
	return 0;
}