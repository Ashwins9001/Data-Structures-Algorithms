#pragma once
class BST {
private:
	struct node{
		int data;
		node* left;
		node* right;
	};

	node* root;
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
};