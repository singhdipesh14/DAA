#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val, bf;
	struct node *left;
	struct node *right;
} * Node;

void inorder(Node first)
{
	if (first)
	{
		inorder(first->left);
		printf("{%d BF : %d}", first->val, first->bf);
		inorder(first->right);
	}
}
void preorder(Node first)
{
	if (first)
	{
		printf("{%d BF : %d}", first->val, first->bf);
		preorder(first->left);
		preorder(first->right);
	}
}
void postorder(Node first)
{
	if (first)
	{
		postorder(first->left);
		postorder(first->right);
		printf("{%d BF : %d}", first->val, first->bf);
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(Node n)
{
	if (n == NULL)
	{
		return -1;
	}
	return max(height(n->left), height(n->right)) + 1;
}

int BF(Node n)
{
	return height(n->left) - height(n->right);
}

void updateBF(Node head)
{
	if (head)
	{
		head->bf = BF(head);
		updateBF(head->left);
		updateBF(head->right);
	}
}

void insert(Node *head, int val)
{
	Node n = (Node)malloc(sizeof(struct node));
	n->val = val;
	n->left = n->right = NULL;
	if (*head == NULL)
	{
		*head = n;
		updateBF(*head);
		printf("**inserted**\n");
		return;
	}
	Node cur = *head;
	Node prev = NULL;
	while (cur)
	{
		prev = cur;
		if (cur->val > val)
		{
			cur = cur->left;
		}
		else if (cur->val < val)
		{
			cur = cur->right;
		}
		else
		{
			printf("**cannot insert duplicate element**\n");
			return;
		}
	}
	if (prev->val > val)
	{
		prev->left = n;
		updateBF(*head);
		printf("**inserted**\n");
		return;
	}
	else
	{
		prev->right = n;
		updateBF(*head);
		printf("**inserted**\n");
		return;
	}
}

int main()
{
	Node first = NULL;
	int choice = 0, ele;
	while (choice < 5)
	{
		printf("Please enter your choice : 1) Insert Element 2) Print Inorder 3) Print Preorder 4) Print Postorder 5) Exit\n :  ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted : ");
			scanf("%d", &ele);
			insert(&first, ele);
			break;
		case 2:
			printf("The inorder is : ");
			inorder(first);
			printf("\n");
			break;
		case 3:
			printf("The preorder is : ");
			preorder(first);
			printf("\n");
			break;
		case 4:
			printf("The postorder is : ");
			postorder(first);
			printf("\n");
			break;
		case 5:
			continue;
			break;
		default:
			printf("Invalid key, try again\n");
			choice = 0;
		}
	}
	return 0;
}