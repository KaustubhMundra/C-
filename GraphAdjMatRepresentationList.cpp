#include <iostream>
using namespace std;

struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

struct AdjList
{
	struct AdjListNode *head;
};

struct Graph
{
	int V;
	struct AdjList *array;
};

struct AdjListNode* newAdjListNode(int dest)
{
	struct AdjListNode* newNode =(struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* CreateGraph(int V)
{
	struct Graph * Graph=(struct Graph*)malloc(sizeof(struct Graph));
	Graph->V=V;
	Graph->array=(struct AdjList*)malloc(V*sizeof(struct AdjList));
	for (int i = 0; i < V; ++i)
	{
		Graph->array[i].head=NULL;
	}
	return Graph;
}

void addEdge(struct Graph * Graph,int src,int dest)
{
	struct AdjListNode * newnode=newAdjListNode(dest);
	newnode->next=Graph->array[src].head;
	Graph->array[src].head=newnode;

	newnode=newAdjListNode(src);
	newnode->next=Graph->array[dest].head;
	Graph->array[dest].head=newnode;	
}

void printGraph(struct Graph* Graph)
{
    int V;
    for (V = 0; V < Graph->V; ++V)
    {
        struct AdjListNode* pCrawl = Graph->array[V].head;
        printf("\n Adjacency list of vertex %d\n head ", V);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
	int V=5;
	struct Graph* Graph=CreateGraph(V);
	addEdge(Graph, 0, 1);
    addEdge(Graph, 0, 4);
    addEdge(Graph, 1, 2);
    addEdge(Graph, 1, 3);
    addEdge(Graph, 1, 4);
    addEdge(Graph, 2, 3);
    addEdge(Graph, 3, 4);
 
 	printGraph(Graph);

	return 0;
}