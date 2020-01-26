#include <iostream>
#include <list>
#include <utility>
#include <set>
#include <vector>
#define INF 100000
using namespace std;

class Graph {
private:
	//num vertices
	int vert;
	//adjacency list for connected edges AND weights
	list<pair<int, int>> *adj_list;
public:
	Graph(int v)
	{
		vert = v;
		adj_list = new list<pair<int, int>>[v];
	}
	void addEdge(int v, int u, int weight)
	{
		//push tuples of connected edges with weights 
		adj_list[v].push_back(make_pair(u, weight));
	}
	void shortestPath(int startNode)
	{
		//set is ordered and contains only unique values, therefore it can act as priority queue 
		//path_set containts (distance, vertex) pairs, ex., vert B has dist(B) = 6 in relation to starting point
		set<pair<int, int>> path_set;

		//vector to store dist() values, unsure of whether nodes are even reachable therefore init all to infinity
		vector<int> distances(vert, INF); //vector of size vert, each value set to INF (infinity)

		//insert entry point into set to begin search
		path_set.insert(make_pair(0, startNode));
		distances[startNode] = 0; //each element of vector stores respective distance for it (from source, startNode)

		//setup set and continue until it empties and all shortest distances finalised
		while (!path_set.empty())
		{
			//"pop off" or erase first element with shortest distance from path_set
			//path_set iterator goes to first element, deref for tuple 
			pair<int, int> temp = *(path_set.begin());
			path_set.erase(path_set.begin()); //remove it from set as visited

			//get node to begin searching neighbors from (here it iwll be node = startNode)
			int node = temp.second;
			//search neighbors to recalculate dist() values and update priority queue
			for (auto i = adj_list[node].begin(); i != adj_list[node].end(); i++)
			{
				int vertex = (*i).first;
				int weight = (*i).second;
				//check if existing distance to one of neighbor nodes is greater than distance from current node plus edge weight
				//if so, shorter path exists and update
				if (distances[node] + weight < distances[vertex])
				{
					//erase current distance-vertex pair if it exists
					if (distances[vertex] != INF)
						path_set.erase(path_set.find(make_pair(vertex, distances[vertex])));
				}
				//update distance-vertex pair
				distances[vertex] = distances[node] + weight;
				path_set.insert(make_pair(distances[vertex], vertex));
			}
		}
		cout << "Minimum distances to remaining nodes from vertex " << startNode << endl;
		for (int i = 0; i < vert; i++)
		{
			cout << "Vertex " << i << " has a distance of " << distances[i] << endl;
		}
	}
};