#include <stdio.h>
#include <stdlib.h>

typedef struct listNode
{
  int n;
  struct listNode *next;
} * ListNode;

typedef struct list
{
  struct listNode *head;
} * List;

typedef struct graph
{
  int val;
  struct list *array;
} * Graph;

ListNode newListNode(int d)
{
  ListNode newNode = (ListNode)malloc(sizeof(struct listNode));
  newNode->n = d;
  newNode->next = NULL;
  return newNode;
}

Graph newGraph(int v)
{
  Graph newGraph = (Graph)malloc(sizeof(struct graph));
  newGraph->val = v;
  newGraph->array = (List)calloc(v, sizeof(struct list));

  for (int i = 0; i < v; i++)
  {
    newGraph->array[i].head = NULL;
  }
  return newGraph;
}

void insertEdge(Graph g, int first, int second)
{
  ListNode newNode = newListNode(second);
  newNode->next = g->array[first].head;
  g->array[first].head = newNode;

  newNode = newListNode(first);
  newNode->next = g->array[second].head;
  g->array[second].head = newNode;
}

void displayList(Graph g)
{
  for (int i = 0; i < g->val; i++)
  {
    ListNode l = g->array[i].head;
    printf("List of vertex %d\n", i);
    while (l->next)
    {
      printf("%d -> ", l->n);
      l = l->next;
    }
    printf("%d\n", l->n);
  }
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

int main()
{
  int num = 4;
  Graph g = newGraph(num);
  insertEdge(g, 1, 3);
  insertEdge(g, 0, 2);
  insertEdge(g, 1, 2);
  insertEdge(g, 2, 3);
  displayList(g);
  printf("\n");
  int **matrix = (int **)calloc(num, sizeof(int *));
  for (int i = 0; i < num; i++)
  {
    matrix[i] = (int *)calloc(num, sizeof(int));
    for (int j = 0; j < num; j++)
    {
      matrix[i][j] = 0;
    }
  }
  insertEdgeM(matrix, 1, 3);
  insertEdgeM(matrix, 0, 2);
  insertEdgeM(matrix, 1, 2);
  insertEdgeM(matrix, 2, 3);
  displayMatrix(matrix, num);
  return 0;
}