/*
Improve upon Dijsktra via a* which uses an additional heuristic to check if searching right direction.
Heuristic used here is line-of-sight to end node. Global goal will be combination of local distance
and line-of-sight distance. Local goal will be distance only. Priority queue tracks global goal.
Line-of-sight is measured by edge weight to following node added with distance at current. 
Next node condition/update weight condition done with local nodes.
Ideally difference b/w local/global goals SHOULD be zero, indicating destination. Larger the difference,
the longer the path to destination really is, as future edge weights distort. After updating each node,
check global goals in queue, pop off front, then continue.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include "olcConsoleGameEngine.h"

//derive from Game Engine defn
class PathFinding : public olcConsoleGameEngine
{
public:

	PathFinding()
	{
		m_sAppName = L"Path Finding";
	}

private:

	struct sNode
	{
		bool bObstacle = false; //check obstruction node
		bool bVisited = false; //check visited node
		float fGlobalGoal; //global goal distance (to destination)
		float fLocalGoal; //local goal distance (from origin)
		int x, y; //pos node
		vector<sNode*> vecNeighbors; //vector of pointers to sNode structs, essentially adjacency list per node (for neighbors)
		sNode* parent; //connected node for shortest path (keep track of this to return a path)
	};

	sNode *nodes = nullptr;
	int nMapWidth = 16;
	int nMapHeight = 16;

	sNode *nodeStart = nullptr;
	sNode *nodeEnd = nullptr;

protected: //inaccessible outside of class, but available to derived members

	virtual bool OnUserCreate() //ensure pure virtual func signatures match for override
	{

		//create 2D array of nodes
		nodes = new sNode[nMapWidth * nMapHeight]; //create array of nodes equal to grid size

		for (int x = 0; x < nMapWidth; x++)
		{ //col x 

			for (int y = 0; y < nMapHeight; y++)
			{ //row y
				//reference single node from array each time, access its x/y members, set pos based on loop then continue 
				//1D array of nodes, y * nMapWidth + x, used to ref index, refer to txt file for more
				nodes[y * nMapWidth + x].x = x;
				nodes[y * nMapWidth + x].y = y;
				//init nodes as unvisited, non-obs, and no parent
				nodes[y * nMapWidth + x].bObstacle = false;
				nodes[y * nMapWidth + x].parent = nullptr;
				nodes[y * nMapWidth + x].bVisited = false;
			}
		}
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		int nNodeSize = 9;
		int nNodeBorder = 2;

		//L before string indicates wide-character (larger 16-bit encoding vs typical 8-bit)
		//Fill via header, params: (x1, y1, x2, y2, val)
		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

		for (int x = 0; x < nMapWidth; x++)
		{
			for (int y = 0; y < nMapHeight; y++)
			{
				//start from pos*size + border for top-left edges, then go to (pos+1)*size - border for bot-right
				//last two args evaluate to a color, ternary operator used to check for obstacles
				Fill(x*nNodeSize + nNodeBorder, y*nNodeSize + nNodeBorder, (x + 1)*nNodeSize - nNodeBorder, (y + 1)*nNodeSize - nNodeBorder, PIXEL_HALF, nodes[y * nMapWidth + x].bObstacle ? FG_WHITE : FG_BLUE);
			}
		}
		return true;
	}
};

int main()
{
	PathFinding path;
	//160 x 160 chars, each occupies a size of 6 pixels 
	path.ConstructConsole(240, 240, 3, 3);
	path.Start();
	return 0;
}