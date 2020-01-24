#include <iostream>
#include <list>
using namespace std;


class Graph {
private:
	int vertices;
	list<int> *adj_list;
public:
	Graph(int vertex)
	{
		vertices = vertex;
		adj_list = new list<int>[vertices];
	}
	void addEdge(int vertexFrom, int vertexTo)
	{
		adj_list[vertexFrom].push_back(vertexTo);
	}
	//func init visited array and then calls DFS
	void visited(int start)
	{
		bool *visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
			visited[i] = false;
		DFS(start, visited);

	}
	//DFS goes to next node in adjacency list from start, recursively calls itself then when visited all nodes, backtracks to start and ends 
	void DFS(int vertex, bool *visited)
	{
		cout << "Visiting node " << vertex << endl;
		visited[vertex] = true;
		for (auto j = adj_list[vertex].begin(); j != adj_list[vertex].end(); j++)
		{
			if (!visited[*j])
			{
				cout << "Going to node " << *j << " from node " << vertex << endl;
				DFS(*j, visited);
 			}
		}
	}
	int getVertices()
	{
		return vertices;
	}

};

int main()
{
	char c;
	Graph g(6);
	
	// Connections for vertex 0
	g.addEdge(0, 1);
	g.addEdge(0, 2);

	// Connections for vertex 1
	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	// Connections for vertex 2
	g.addEdge(2, 0);
	g.addEdge(2, 4);

	// Connections for vertex 3
	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	// Connections for vertex 4
	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	// Connections for vertex 5
	g.addEdge(5, 3);
	g.addEdge(5, 4);

	// Perform DFS and print result
	g.visited(0);

	cin >> c;
}