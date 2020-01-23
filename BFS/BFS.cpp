#include <list>
#include <iostream>
#include<vector>
using namespace std;


class Graph {
private:
	int vertices;
	//create pointer to a list/list-pointer
	list<int> *adj_list;
public:
	Graph(int vert)
	{
		//init constructor
		vertices = vert;
		//array containing list<int> at each index, equal to size of vertices
		//list-pointer goes to first index of arr
		adj_list = new list<int>[vert];
	}
	void addEdge(int vert_from, int vert_to)
	{
		//at each array elem, add vertices connected to vert_from via list container
		adj_list[vert_from].push_back(vert_to);
	}
	void printAdjList()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << " For vertex: " << i << " connected vertices are, ";
			for (auto j = adj_list[i].begin(); j != adj_list[i].end(); j++)
			{
				cout << *j << ", ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void BFS(int vert)
	{
		//keep track of visited nodes, init to unvisited
		bool *visited = new bool[vertices];
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
		//queue container to track nodes being searched
		list<int> queue;
		visited[vert] = true;
		queue.push_back(vert);
		while (!queue.empty())
		{
			//repeat till queue emptied, each time pushing new nodes to back and popping/referring to 
			//current nodes in search from front 
			vert = queue.front();
			queue.pop_front();
			cout << "Checking adjacent vertices for node " << vert << " and removing from queue " <<  endl;
			//iterating a POINTER not an integer
			for (auto j = adj_list[vert].begin(); j != adj_list[vert].end(); j++)
			{
				//iterator j will go to vertex passed in and check each adj vert via list
				//for unvisited ones, update bool arr to track and add node to back of stack
				if (!visited[*j])
				{
					cout << "Visit and enqueue " << *j << endl;
					visited[*j] = true;
					queue.push_back(*j);
				}
			}
			for (auto i = queue.begin(); i != queue.end(); i++)
				cout << "Current queue " << *i << ", ";
			cout << endl;
		}
		
 	}
};
int main() {
	char c;
	Graph g(6);

	// Create some edges to the vertices
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

	// Print adj list
	g.printAdjList();

	// Perform BFS and print result
	g.BFS(2);
	cin >> c;
}

