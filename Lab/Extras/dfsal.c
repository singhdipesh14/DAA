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

void dfs(Graph g, int **Stack, int *top, int *capacity)
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
			Node now = g->edges[cur].first;
			while (now)
			{
				if (visited[now->val] == 0)
				{
					visited[now->val] = 1;
					printf("pushed : %d\n", now->val);
					p = (char)('0' + now->val);
					result[resultIndex++] = p;
					push(Stack, top, capacity, now->val);
					display(*Stack, *top);
					flag = 1;
					break;
				}
				else
				{
					now = now->next;
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
			for (int i = 0; i < g->v && flag; i++)
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
	int top = -1, capacity = 2;
	int *Stack = (int *)calloc(capacity, sizeof(int));
	dfs(g, &Stack, &top, &capacity);
	return 0;
}