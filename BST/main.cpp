#include <iostream>
#include <cstdlib>
#include "bst.cpp"
using namespace std;

int main(int argc, char* argv[]) {
	char c;
	int treeKeys[15] = { 5, 30, 22, 39, 18, 7, 11, 56, 93, 92, 33, 2, 3, 6, 24 };
	BST myTree;
	cout << "Printing the tree in order before adding numbers " << endl;
	myTree.printInOrder();
	for (int i = 0; i < 15; i++)
	{
		myTree.addLeaf(treeKeys[i]);
	}
	cout << "Printing the tree in order after adding numbers " << endl;
	myTree.printInOrder();

	myTree.printChildren(myTree.returnRootKey());
	cout << myTree.findSmallest() << endl;
	cin >> c;
}