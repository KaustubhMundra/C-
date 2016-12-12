#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int v;
	list <int> *adj;
	void DFSUtil(int s, bool visited[]);
public:
	Graph(int v);
	void addEdge(int v,int w);
	void DFS();
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
}

void Graph::DFSUtil(int s, bool visited[])
{
	visited[s] = true;
    cout << s << " ";

    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);

}

void Graph::DFS()
{
	bool *visited=new bool[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i]=false;
	}
	for (int i = 0; i < v; ++i)
	{
		if(!visited[i])
		{
		DFSUtil(i,visited);
		}
	}
	
}


int main(int argc, char const *argv[])
{
	Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.addEdge(5,3);
    //g.addEdge(4,6);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
		
	return 0;
}