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
};