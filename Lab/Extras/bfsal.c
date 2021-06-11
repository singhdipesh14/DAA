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

typedef struct node
{
	int val;
	struct node *next;
} * Node;

typedef struct list
{
	Node first;
} * List;

typedef struct graph
{
	int v;
	List edges;
} * Graph;

Graph createGraph(int v)
{
	Graph newGraph = (Graph)malloc(sizeof(struct graph));
	newGraph->v = v;
	newGraph->edges = (List)calloc(v, sizeof(struct list));
	for (int i = 0; i < v; i++)
	{
		newGraph->edges[i].first = NULL;
	}
	return newGraph;
}

void insertEdge(Graph g, int from, int to)
{
	Node atob = (Node)malloc(sizeof(struct node));
	atob->val = to;
	atob->next = NULL;
	if (g->edges[from].first == NULL)
	{
		g->edges[from].first = atob;
		return;
	}
	Node cur = g->edges[from].first;
	if (cur->val > to)
	{
		atob->next = g->edges[from].first;
		g->edges[from].first = atob;
		return;
	}
	Node prev = NULL;
	while (cur && to > cur->val)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = atob;
	atob->next = cur;
	return;
}

void displayGraph(Graph g)
{
	for (int i = 0; i < (g->v); i++)
	{
		printf("Node: %d, the edge list is as follows : ", i);
		Node cur = g->edges[i].first;
		while (cur)
		{
			printf("%d ", cur->val);
			cur = cur->next;
		}
		printf("\n");
	}
}

void bfs(Graph g, int **Queue, int *front, int *rear, int *capacity)
{
	int *visited = (int *)calloc(g->v, sizeof(int));
	for (int i = 0; i < g->v; i++)
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
			Node now = g->edges[cur].first;
			while (now)
			{
				if (visited[now->val] == 0)
				{
					visited[now->val] = 1;
					char p = (char)('0' + now->val);
					result[resultIndex++] = p;
					push(Queue, front, rear, capacity, now->val);
					printf("pushed : %d\n", now->val);
					display(*Queue, *front, *rear, *capacity);
				}
				else
				{
					now = now->next;
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
			for (int i = 0; i < g->v && flag; i++)
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
	Graph g = NULL;
	int v;
	printf("Enter the number of vertices : ");
	scanf("%d", &v);
	g = createGraph(v);
	int from, to;
	while (1)
	{
		printf("Enter the from to edge, enter -1 to exit : ");
		scanf("%d %d", &from, &to);
		if (from == -1 || to == -1)
		{
			break;
		}
		if (from >= v || to >= v)
		{
			printf("Invalid vertices, try again.\n");
			continue;
		}
		insertEdge(g, from, to);
	}
	printf("The graph is : \n");
	displayGraph(g);
	printf("\n");
	int front = 0, rear = 0, capacity = 2;
	int *Queue = (int *)calloc(capacity, sizeof(int));
	bfs(g, &Queue, &front, &rear, &capacity);
	return 0;
}