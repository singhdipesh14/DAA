#include <stdio.h>
#include <stdlib.h>

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

int check(Graph g, int n)
{
	for (int i = 0; i < g->v; i++)
	{
		if (i != n)
		{

			Node cur = g->edges[i].first;
			while (cur)
			{
				if (cur->val == n)
				{
					return 0;
				}
				cur = cur->next;
			}
		}
	}
	return 1;
}

void deleteEdges(Graph g, int n)
{
	Node cur = g->edges[n].first;
	while (cur)
	{
		Node temp = cur;
		cur = cur->next;
		free(temp);
	}
	g->edges[n].first = NULL;
}

void topo(Graph g)
{
	int *removed = (int *)calloc(g->v, sizeof(int));
	for (int i = 0; i < g->v; i++)
	{
		removed[i] = 0;
	}
	int popped[g->v];
	int poppedIndex = 0;
	for (int i = 0; i < g->v; i++)
	{
		if (removed[i] == 0 && check(g, i))
		{
			removed[i] = 1;
			popped[poppedIndex++] = i;
			deleteEdges(g, i);
			i = -1;
		}
	}
	for (int i = 0; i < g->v; i++)
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
	topo(g);
	return 0;
}