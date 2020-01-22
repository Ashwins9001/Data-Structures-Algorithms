#pragma once
using namespace std;
class BST {
private:
	struct node{
		int data;
		node* left;
		node* right;
	};

	node* root;
	void addLeafPrivate(int dataIn, node* Ptr)
	{
		if (root == NULL)
			root = CreateLeaf(dataIn);
		else if (dataIn < Ptr->data)
		{
			if (Ptr->left != NULL)
				addLeafPrivate(dataIn, Ptr->left); //recursively traverse down to left node, then check again 
			else
				Ptr->left = CreateLeaf(dataIn); //create a leaf, returns node ptr, left-member of existing node now points to newly created
		}
			
		else if (dataIn > Ptr->data) 
		{
			if (Ptr->right != NULL)
				addLeafPrivate(dataIn, Ptr->right);  
			else
				Ptr->right = CreateLeaf(dataIn); 
		}
		else //dataIn = data at node
		{
			cout << "Data in " << dataIn << " has already been added to tree " << endl;
		}
	}
	void printInOrderPrivate(node* Ptr)
	{
		if (root != NULL)
		{
			if (Ptr->left != NULL)
				printInOrderPrivate(Ptr->left);
			cout << Ptr->data << " ";
			if (Ptr->right != NULL)
				printInOrderPrivate(Ptr->right);
		}
		else
			cout << "Tree is empty" << endl;
	}
	node* returnNodePrivate(int dataIn, node* Ptr)
	{
		if (Ptr != NULL)
		{
			if (Ptr->data == dataIn)
				return Ptr;
			else
			{
				if (dataIn < Ptr->data)
					returnNodePrivate(dataIn, Ptr->left);
				else if (dataIn > Ptr->data)
					returnNodePrivate(dataIn, Ptr->right);
			}
		}
		else
			return NULL;
	}
	int findSmallestPrivate(node* Ptr)
	{
		if (root == NULL)
		{
			cout << "Tree is empty " << endl; return -1;
		}
		else
		{
			if (Ptr->left != NULL)
				return findSmallestPrivate(Ptr->left);
			else
				return Ptr->data;
		}
			
	}
public:
	BST(){root = NULL;}
	node* CreateLeaf(int dataIn) 
	{
		node* n = new node;
		//-> = *n.data : deref pointer to obj and access srtuct member
		n->data = dataIn;
		n->left = NULL;
		n->right = NULL;
		//return pointer to node struct, which has defn of data and its left/right pointers 
		return n;
	}
	void addLeaf(int dataIn)
	{
		addLeafPrivate(dataIn, root); //keep pointer assignment private
	}
	void printInOrder()
	{
		printInOrderPrivate(root);
	}
	node* returnNode(int dataIn) //return a node pointer which can be referenced from private var as input to func 
	{
		return returnNodePrivate(dataIn, root);
	}
	int returnRootKey()
	{
		if (root != NULL)
			return root->data;
		else
			return -1000;
	}
	void printChildren(int dataIn)
	{
		node* Ptr = returnNode(dataIn); //returns pointer to node containing data/key
		if (Ptr != NULL)
		{
			cout << "Parent node is " << Ptr->data << endl;
			//print out children of node with matching data 
			Ptr->left == NULL ?
				cout << "left child = NULL " << endl :
				cout << "left child = " << Ptr->left->data << endl;
			Ptr->right == NULL ?
				cout << "right child = NULL " << endl :
				cout << "right child = " << Ptr->right->data << endl;
		}
		else
			cout << "Data is " << dataIn << " is not in tree" << endl;
	}
	int findSmallest()
	{
		return findSmallestPrivate(root);
	}
};