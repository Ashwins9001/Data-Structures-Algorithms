#pragma once
#include <iostream>
#include <cstddef>
#include <assert.h>
using namespace std;

struct Node 
{
	int data;
	Node *next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class LinkedList
{
private:
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}

	void add_node(int d)
	{
		Node *new_node = new Node(d);
		Node *tmp = head;
		//if empty list
		if (tmp == NULL){head = new_node;}
		else {
			//tmp ptr to Node struct, deref it to access member ptr next, traverse to end, add
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new_node;
		}
	}

	void print_nodes()
	{
		Node *tmp = head;
		//tmp ptr to Node struct, deref it to access member ptr next, traverse to end, add
		while (tmp->next != NULL)
		{
			cout << tmp->data << " -> ";
			tmp = tmp->next;
		}
		cout << tmp->data << endl;
	}

	void returnPairs()
	{
		if (head == NULL || head->next == NULL) cout << "Empty list " << endl;
		Node *curr = head;
		Node *tmp = curr;
		while (curr != NULL && curr->next != NULL)
		{
			//point to first node
			tmp = curr;
			//inc to second node
			curr = curr->next;
			//next ptr should go to third adj node, still pointing to first node
			tmp->next = curr->next;
			//second node now goes to first node
			curr->next = tmp;
			//move on in process
			//if done curr = NULL
			cout << "curr: " << curr->data << ", tmp: " << tmp->data << endl;
			curr = tmp->next;
			//ensure another PAIR exists
			if (curr != NULL && curr->next != NULL) tmp->next = curr->next;
		}
	}
};