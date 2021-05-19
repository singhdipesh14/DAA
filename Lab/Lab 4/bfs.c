#include <stdio.h>
#include <stdlib.h>

int isEmpty(int front, int rear)
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

int isFull(int front, int rear, int capacity)
{
	if ((rear + 1) % capacity == front)
	{
		return 1;
	}
	return 0;
}

void display(int *Queue, int front, int rear, int capacity)
{
	if (isEmpty(front, rear))
	{
	}
	else
	{
		printf("queue : ");
		for (int i = (front + 1) % capacity; i != (rear + 1) % capacity; i = (i + 1) % capacity)
		{
			printf("%d ", Queue[i]);
		}
		printf("\n");
	}
}

void push(int **Queue, int *front, int *rear, int *capacity, int key)
{
	if (isFull(*front, *rear, *capacity))
	{
		int *newQueue = (int *)calloc((*capacity) * 2, sizeof(int));
		int i, j;
		for (i = 1, j = (*front + 1) % (*capacity); j != (*rear + 1) % (*capacity); j = (j + 1) % (*capacity), i++)
		{
			newQueue[i] = (*Queue)[j];
		}
		int *temp = *Queue;
		*Queue = newQueue;
		*capacity = *capacity * 2;
		*front = 0;
		*rear = --i;
		free(temp);
	}
	*rear = (*rear + 1) % (*capacity);
	(*Queue)[*rear] = key;
}

int pop(int **Queue, int *front, int *rear, int *capacity)
{
	int temp = (*Queue)[(*front + 1) % (*capacity)];
	*front = (*front + 1) % (*capacity);
	return temp;
}
void insertEdgeM(int **matrix, int first, int second)
{
	matrix[first][second] = 1;
	matrix[second][first] = 1;
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

void bfs(int **matrix, int num, int **Queue, int *front, int *rear, int *capacity)
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
	push(Queue, front, rear, capacity, 0);
	printf("pushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resultIndex++] = p;
	display(*Queue, *front, *rear, *capacity);
	visited[0] = 1;
	int cur = *Queue[*front];
	int flag, ele;
	while (1)
	{
		if (!(isEmpty(*front, *rear)))
		{
			for (int i = 0; i < num; i++)
			{
				if (visited[i] == 0 && matrix[cur][i] == 1)
				{
					visited[i] = 1;
					char p = (char)('0' + i);
					result[resultIndex++] = p;
					push(Queue, front, rear, capacity, i);
					printf("pushed : %d\n", i);
					display(*Queue, *front, *rear, *capacity);
				}
			}
			ele = pop(Queue, front, rear, capacity);
			p = (char)('0' + ele);
			popped[poppedIndex++] = p;
			printf("popped : %d\n", ele);
			display(*Queue, *front, *rear, *capacity);
			cur = (*Queue)[(*front + 1) % (*capacity)];
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
					push(Queue, front, rear, capacity, i);
					display(*Queue, *front, *rear, *capacity);
					cur = (*Queue)[(*front + 1) % (*capacity)];
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	while (!(isEmpty(*front, *rear)))
	{
		ele = pop(Queue, front, rear, capacity);
		p = (char)('0' + ele);
		popped[poppedIndex++] = p;
		printf("popped : %d\n", ele);
		display(*Queue, *front, *rear, *capacity);
	}
	printf("The bfs is : ");
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
}

int main()
{
	int num = 9;
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
	insertEdgeM(matrix, 2, 3);
	insertEdgeM(matrix, 4, 2);
	insertEdgeM(matrix, 2, 5);
	insertEdgeM(matrix, 6, 5);
	insertEdgeM(matrix, 4, 7);
	insertEdgeM(matrix, 0, 8);
	insertEdgeM(matrix, 2, 8);
	insertEdgeM(matrix, 6, 8);
	insertEdgeM(matrix, 6, 7);
	displayMatrix(matrix, num);
	int front = 0, rear = 0, capacity = 2;
	int *Queue = (int *)calloc(capacity, sizeof(int));
	bfs(matrix, num, &Queue, &front, &rear, &capacity);
	return 0;
}