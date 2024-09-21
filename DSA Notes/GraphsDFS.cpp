#include <stdio.h>
#include <stdlib.h>

//this struct to represent the node
struct AdjListNode
{
	int dest;
	AdjListNode* next;
};

//represent an adjency list
struct AdjList
{
	AdjListNode* head;
};

//represent the graph duh
struct Graph
{
	int v; //Vertices or Nodes, this counts how many nodes in this graph
	AdjList* arr;
};

//Create the Node
AdjListNode* AddNode(int dest)
{
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->dest = dest;
	newNode->next = NULL;
	return newNode;
}

//Create the graphs of Nodes or Vertices
Graph* CreateGraph(int v)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->v = v;
	
	//create an array size of v
	graph->arr = (AdjList*)malloc(v * sizeof(AdjList));
	
	//Initialize each list as empty by set the head value as a NULL
	for(int i = 0; i < v; i++)
	{
		graph->arr[i].head = NULL;
	}
	
	return graph;
}

//Add edge or connection
void AddEdge(Graph* graph, int src, int dest)
{
	//Undirected Graphs
	//Edge from src to dest
	AdjListNode* newNode = AddNode(dest); //Create a newNode
	newNode->next = graph->arr[src].head; //newNode->next points to the head(NULL)
	graph->arr[src].head = newNode; //Update the head to the newNode
	
	//Edge dest to src
	//Disabling it to switch to directed graphs
	
	
	AdjListNode* newNode2 = AddNode(src);
	newNode2->next = graph->arr[dest].head;
	graph->arr[dest].head = newNode2;
	
	
}

//Print the graph
void PrintGraph(Graph* graph)
{
	//Loop for each list
	for(int i = 0; i < graph->v; i++)
	{
		AdjListNode* curr = graph->arr[i].head;
		printf("\nAdjacency list of vertex \n%d", i);
		//Traverse for each edge from src
		while(curr != NULL)
		{
			printf(" -> %d", curr->dest);
			curr = curr->next;
		}
		printf("\n");
	}
}

//AdjencyMatix edition
//Note: adjMatrix[source][destination]
void AdjencencyMatrix(Graph* graph, int** adjMatrix)
{
	//initialize everything to 0's
	for(int i = 0; i < graph->v; i++)
	{
		for(int j = 0; j < graph->v; j++)
		{
			adjMatrix[i][j] = 0;
		}	
	}
	
	// Traverse the adjencency list and fill the matrix
	for(int i = 0; i < graph->v; i++)
	{
		AdjListNode* curr = graph->arr[i].head;
		while(curr != NULL)
		{
			adjMatrix[i][curr->dest] = 1;
			curr = curr->next;
		}
	}
	
}

//Print the Adjcency Matrix
void PrintAdjMatrix(int v, int** adjMatrix)
{
	for(int i = 0; i < v; i++)
	{
		for(int j = 0; j < v; j++)
		{
			printf("%d ", adjMatrix[i][j]);
		}
		printf("\n");
	}
}

//The DFS Ulitily function
void DFSUtil(int v, int* visited, Graph* graph, int target)
{
	//Set the starting point as a visited
	visited[v] = 1;
	printf("%d", v);
	
	//create a copy of the list to traverse the list
	AdjListNode* adjList = graph->arr[v].head;
	
	//traversing the list
	while(adjList != NULL)
	{
		//Check is the target found
		if(target == adjList->dest)
		{
			printf("\nFound!");
			return;
		}
		
		int connectedVertex = adjList->dest;
		if(visited[connectedVertex] != 1)
		{
			//go to connected vertex
			DFSUtil(connectedVertex, visited, graph, target);
		}
		adjList = adjList->next;
	}
}

//DFS Mechanism
void DFS(Graph* graph, int v, int target = 0)
{
	//Create the visited array to store the visited value
	int* visited = (int*)malloc(v * sizeof(int));
	
	//make all the visited to 0 because it's unvisited DUH
	for(int i = 0; i < v; i++)
	{
		visited[i] = 0;
	}
	
	//The algorithm
	DFSUtil(v, visited, graph, target);
}

int main(void)
{
	
	int graphSize = 5;
	Graph* graph = CreateGraph(graphSize);
	AddEdge(graph, 0, 2);
	AddEdge(graph, 1, 2);
	AddEdge(graph, 2, 3);
	AddEdge(graph, 3, 4);
	
	PrintGraph(graph);
	
	//Manually Allocate for 2D array
	int** adjMat = (int**)malloc(graphSize * sizeof(int*));
	for(int i = 0; i < graphSize; i++)
	{
		adjMat[i] = (int*)malloc(graphSize * sizeof(int));
	}
	
	//Create a adjencency matrix
	AdjencencyMatrix(graph, adjMat);
	
	PrintAdjMatrix(graphSize, adjMat);
	
	int target = 0;
	printf("Enter target: ");
	scanf("%d", &target);
	DFS(graph, 0, target);
}