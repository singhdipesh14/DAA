#include <stdio.h>
#include <stdlib.h>

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

int check(int **matrix, int num, int node)
{
	int result = 1;
	for (int i = 0; i < num; i++)
	{
		if (matrix[i][node] == 1)
		{
			result = 0;
		}
	}
	return result;
}

void deleteEdges(int **matrix, int num, int node)
{
	for (int i = 0; i < num; i++)
	{
		matrix[node][i] = 0;
	}
}

void topo(int **matrix, int num)
{
	int *removed = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		removed[i] = 0;
	}
	int popped[num];
	int poppedIndex = 0;
	for (int i = 0; i < num; i++)
	{
		if (removed[i] == 0 && check(matrix, num, i))
		{
			removed[i] = 1;
			popped[poppedIndex++] = i;
			deleteEdges(matrix, num, i);
			i = -1;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (removed[i] == 0)
		{
			printf("The graph is not a Directed Acyclic Graph, topological sort not possible.\n");
			return;
		}
	}
	printf("The graph is a Directed Acyclic Graph, topoplogical sort is possible : ");
	for (int i = 0; i < poppedIndex; i++)
	{
		printf("%d ", popped[i]);
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
	insertEdgeM(matrix, 4, 0);
	insertEdgeM(matrix, 5, 1);
	insertEdgeM(matrix, 5, 2);
	insertEdgeM(matrix, 5, 4);
	insertEdgeM(matrix, 5, 6);
	displayMatrix(matrix, num);
	topo(matrix, num);
	return 0;
}