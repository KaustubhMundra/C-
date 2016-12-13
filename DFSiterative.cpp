#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
	int v;
	list <int> *adj;
public:
	Graph(int v);
	void addEdge(int a,int b);
	void DFS();
};

Graph::Graph(int v)
{
	this->v=v;
	adj=new list<int>[v];
}

void Graph::addEdge(int a, int b)
{
	adj[a].push_back(b);
}

void Graph::DFS()
{
	vector <bool> visited(v,false);

	for (int i = 0; i < v; i++)
        if (!visited[i])
        {

			stack <int> stack;
			stack.push(i);
			
			
			while(!stack.empty())
			{
				i=stack.top();
				stack.pop();

				if(!visited[i])
				{
					cout << i << " ";
					visited[i]=true;
				}

				for (auto j = adj[i].begin(); j != adj[i].end(); ++j)
				{
					if(!visited[*j])
					{
						stack.push(*j);
					}
				}
			}

		}
}

int main(int argc, char const *argv[])
{
	Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
 	
	return 0;
}