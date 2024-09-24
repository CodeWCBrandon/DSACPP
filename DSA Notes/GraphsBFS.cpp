#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

#define DEBUG_MODE 1

#if DEBUG_MODE == 1
#define Debug(x, y) printf(x, y)
#else
#define Debug(x, y)
#endif 

//The nodes
struct AdjListNode
{
	int dest; // the destination
	AdjListNode* next;
};

//The list
struct AdjList
{
	AdjListNode* head; //head of the list
};

//The graph
struct Graph
{
	int v;
	AdjList* arr;
};

AdjListNode* AddNode(int dest)
{
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	
	return newNode;
}

Graph* CreateGraph(int v)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;
	
	
	graph->arr = (AdjList*)malloc(v * sizeof(AdjList));
	
	for(int i = 0; i < v; i++)
	{
		graph->arr[i].head = NULL; 
	}
	
	return graph;
}

void AddEdge(Graph* graph, int src, int dest)
{
	//Undirected graphs
	//from src to dest
	AdjListNode* newNode = AddNode(dest);
	newNode->next = graph->arr[src].head;
	graph->arr[src].head = newNode;
	
	//from dest to src
	
	AdjListNode* newNode1 = AddNode(src);
	newNode1->next = graph->arr[dest].head;
	graph->arr[dest].head = newNode1;
}
 
 void PrintGraph(Graph* graph, int v)
 { 	
 	for(int i = 0; i < v; i++)
 	{
 		AdjListNode* curr = graph->arr[i].head;
 		printf("%d: ", i);
 		while(curr != NULL)
		{
			printf("%d, ", curr->dest);
			 	
			curr = curr->next;
		}	
		printf("\n");
	}
 }
 
void AdjMatrix(Graph* graph, int** arr)
{
	//Set everything to zero
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	for(int i = 0; i < SIZE; i++)
 	{
 		AdjListNode* curr = graph->arr[i].head;
		while(curr != NULL)
		{
			arr[i][curr->dest] = 1;
			curr = curr->next;
		}
	}
}

void PrintAdjMatrix(int** arr)
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void BFS(Graph* graph, int src, int target)
{
	int size = graph->v;
	int visited[size] = {0};
	visited[src] = 1;
	
	//double pointer
	int a = 0;
	int b = 0;
	
	int queue[size] = {-1};
	
	queue[b] = src;
	b++;
	
	
	while(queue[a] != -1)
	{
		AdjListNode* curr = graph->arr[queue[a]].head;
		while(curr != NULL)
		{
			if(curr->dest == target)
			{
				printf("%d Found!!", target);
				return;
			}
			
			if(visited[curr->dest] == 0)
			{
				visited[curr->dest] = 1;	
				
				printf("%d\n", curr->dest);
				
				queue[b] = curr->dest;
				b++;									
			}

			curr = curr->next;
		}
		a++;
	}
}

int main(void)
{
	Graph* graph = CreateGraph(SIZE);
	
	AddEdge(graph, 0, 3);
	AddEdge(graph, 4, 2);
	AddEdge(graph, 1, 2);
	AddEdge(graph, 4, 1);
	AddEdge(graph, 0, 4);
	
	PrintGraph(graph, SIZE);
	
	int** adjMat = (int**)malloc(SIZE * sizeof(int*));
	for(int i = 0; i < SIZE; i++)
	{
		adjMat[i] = (int*)malloc(SIZE * sizeof(int));
	}
	
	AdjMatrix(graph, adjMat);
	
	printf("\n\n");
	PrintAdjMatrix(adjMat);
	
	BFS(graph, 0, 2);
}