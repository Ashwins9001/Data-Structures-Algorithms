package binarytree;

import java.util.LinkedList;
import java.util.Queue;

public class BinaryTree {
	Node root;
	public void addNode(int keyIn)
	{
		Node newNode = new Node(keyIn);
		if(root == null)
			root = newNode;
		else 
		{
			Node focusNode = root;
			Node parent;
			while(true)
			{
				//set parent to level root
				parent = focusNode;
				//check left/right children
				if(keyIn < focusNode.key)
				{
					focusNode = focusNode.leftChild;
					//if left child is NULL, add node there 
					if(focusNode == null)
					{
						parent.leftChild = newNode;
						return;
					}
				}
				if(keyIn > focusNode.key)
				{
					focusNode = focusNode.rightChild;
					if(focusNode == null)
					{
						parent.rightChild = newNode;
						return;
					}
				}
			}
		}
	}
	public static void main(String[] args) 
	{
		BinaryTree theTree = new BinaryTree();
		theTree.addNode(10);
		theTree.addNode(19);
		theTree.addNode(5);
		theTree.addNode(21);
		theTree.addNode(17);
		theTree.addNode(6);
		theTree.addNode(1); //45
		int sumEvenGrandparents =  sumEvenGrandParent(theTree.root);
		System.out.println(sumEvenGrandparents);
	}
	public static void inOrderTraversal(Node focusNode)
	{
		if(focusNode != null)
		{
			inOrderTraversal(focusNode.leftChild);
			System.out.println(focusNode.key);
			inOrderTraversal(focusNode.rightChild);
			//System.out.println(focusNode.key);
		}
	}
	
	public static int sumEvenGrandParent(Node root)
	{
		int sum = 0;
		Queue<Node> q = new LinkedList();
		q.add(root);
		
		while(!q.isEmpty())
		{
			Node top = q.poll();
			//check left side of top node, on following iteration itll be one of its children being polled 
			if(top.leftChild != null)
			{
				//add leftChild to queue to continue traversal
				q.add(top.leftChild);
				//if even, check if grandchild exists then sum
				if(top.key % 2 == 0)
				{
					if(top.leftChild.leftChild != null)
						sum += top.leftChild.leftChild.key;
					if(top.leftChild.rightChild != null)
						sum += top.leftChild.rightChild.key;
				}
			}
			if(top.rightChild != null)
			{
				q.add(top.rightChild);
				if(top.key % 2 == 0)
				{
					if(top.rightChild.rightChild != null)
						sum += top.rightChild.rightChild.key;
					if(top.rightChild.leftChild != null)
						sum += top.rightChild.leftChild.key;
				}
			}
		}
		return sum;
	}
}
class Node {
	int key;
	
	Node leftChild;
	Node rightChild;
	
	Node(int keyIn)
	{
		key = keyIn;
	}
}
	