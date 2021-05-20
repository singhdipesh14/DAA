#include <stdio.h>
#include <stdlib.h>

int isEmpty(int top)
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(int top, int capacity)
{
	if (top == capacity - 1)
	{
		return 1;
	}
	return 0;
}

void push(int **Stack, int *top, int *capacity, int key)
{
	if (isFull(*top, *capacity))
	{
		*Stack = (int *)realloc(*Stack, sizeof(int) * (*capacity) * 2);
		*capacity *= 2;
	}
	(*top)++;
	(*Stack)[*top] = key;
}

int pop(int **Stack, int *top)
{
	int temp = (*Stack)[*top];
	(*top)--;
	return temp;
}

void display(int *Stack, int top)
{
	if (isEmpty(top))
	{
	}
	else
	{
		printf("stack : ");
		int i;
		for (i = 0; i <= top; i++)
		{
			printf("%d ", *(Stack + i));
		}
		printf("\n");
	}
}

void insertEdgeM(int **matrix, int first, int second)
{
	matrix[first][second] = 1;
}

void displayMatrix(int **matrix, int n)
{
	for (int i = -1; i < n; i++)
	{
		if (i != -1)
			printf("%d -> ", i);
		for (int j = 0; j < n; j++)
		{
			if (i == -1)
			{
				if (j == 0)
				{
					printf("\t");
				}
				printf("%d\t", j);
				continue;
			}
			if (j == 0)
			{
				printf("\t");
			}
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void dfs(int **matrix, int num, int **Stack, int *top, int *capacity)
{
	int *visited = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		visited[i] = 0;
	}
	char result[100];
	int resultIndex = 0;
	char popped[100];
	int poppedIndex = 0;
	push(Stack, top, capacity, 0);
	printf("pushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resultIndex++] = p;
	display(*Stack, *top);
	visited[0] = 1;
	int cur = *Stack[*top];
	int flag, ele;
	while (1)
	{
		if (!(isEmpty(*top)))
		{
			flag = 0;
			for (int i = 0; i < num; i++)
			{
				if (visited[i] == 0 && matrix[cur][i] == 1)
				{
					visited[i] = 1;
					printf("pushed : %d\n", i);
					p = (char)('0' + i);
					result[resultIndex++] = p;
					push(Stack, top, capacity, i);
					display(*Stack, *top);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				ele = pop(Stack, top);
				p = (char)('0' + ele);
				popped[poppedIndex++] = p;
				printf("popped : %d\n", ele);
				display(*Stack, *top);
			}
			cur = (*Stack)[*top];
		}
		else
		{
			flag = 1;
			for (int i = 0; i < num && flag; i++)
			{
				if (visited[i] == 0)
				{
					visited[i] = 1;
					printf("pushed : %d\n", i);
					p = (char)('0' + i);
					result[resultIndex++] = p;
					push(Stack, top, capacity, i);
					display(*Stack, *top);
					flag = 0;
					cur = (*Stack)[*top];
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	while (!(isEmpty(*top)))
	{
		int rem = pop(Stack, top);
		p = (char)('0' + rem);
		popped[poppedIndex++] = p;
		printf("popped : %d\n", rem);
		display(*Stack, *top);
	}
	printf("The dfs is : ");
	for (int i = 0; i < resultIndex; i++)
	{
		printf("%c ", result[i]);
	}
	printf("\nThe traversal stack is : ");
	for (int i = 0; i < poppedIndex; i++)
	{
		printf("%c ", popped[i]);
	}
	printf("\n");
	for (int i = 0; i < poppedIndex - 1; i++)
	{
		for (int j = i + 1; j < poppedIndex; j++)
		{
			if (matrix[((int)(popped[i] - '0'))][((int)(popped[j] - '0'))] == 1)
			{
				printf("The graph is not a Directed Acyclic Graph, topological sort not possible.\n");
				return;
			}
		}
	}
	printf("The graph is a Directed Acyclic Graph, topoplogical sort is possible : ");
	for (int i = poppedIndex - 1; i >= 0; i--)
	{
		printf("%c ", popped[i]);
	}
	printf("\n");
}

int main()
{
	int num = 7;
	int **matrix = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
		matrix[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++)
		{
			matrix[i][j] = 0;
		}
	}
	insertEdgeM(matrix, 0, 1);
	insertEdgeM(matrix, 1, 2);
	insertEdgeM(matrix, 2, 3);
	insertEdgeM(matrix, 3, 6);
	insertEdgeM(matrix, 6, 4);
	insertEdgeM(matrix, 6, 0);
	insertEdgeM(matrix, 5, 1);
	insertEdgeM(matrix, 5, 2);
	insertEdgeM(matrix, 5, 6);
	insertEdgeM(matrix, 5, 4);
	displayMatrix(matrix, num);
	int top = -1, capacity = 2;
	int *Stack = (int *)calloc(capacity, sizeof(int));
	dfs(matrix, num, &Stack, &top, &capacity);
	return 0;
}