#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;

class Minheap {
private:
	vector<int> heap;
	int capacity;
	int size;
	//pass index i for some element, return parent, left, or right nodes
	int parent(int i) { return (i - 1) / 2; }
	// Returns the left child
	int left(int i) { return 2 * i + 1; }
	// Returns the right child
	int right(int i) { return 2 * i + 2; }

public:
	Minheap(int capacity)
	{
		size = 0;
		//declared local variable in method, reference obj to differentiate 
		this->capacity = capacity;
		cout << "capacity is " << this->capacity << endl;
		heap.resize(capacity);
	}
	int getMax()
	{
		if (size == 0)
			cout << "Empty heap " << endl;
		else if (size == 1)
		{
			size--;
			return heap[0];
		}
		else {
			int root = heap[0];
			heap[0] = heap[size - 1];
			size--;
			//after swap, call heapify to maintain heap invariant
			heapifyRoot(0);
			return root;
		}
		
	}
	void insert(int k)
	{
		if (size == capacity)
		{
			cout << "Heap is full " << endl;
			return;
		}
		size++;
		//insert a node at the end 
		int i = size - 1;
		heap[i] = k;
		heapifyUp(i);
	}
	//recursive function to maintain structure after root removal (polling operation)
	//sorts root node (refers to children)
	void heapifyRoot(int i)
	{
		//get indices of left, right children of node i
		//heapify called at root in getMin(), set that to smallest index for now
		int l = left(i);
		int r = right(i);
		int largest = i;

		//set largest node by finding value via heap vector
		if (heap[i] < heap[l])
			largest = l;
		if (heap[i] < heap[r])
			largest = r;

		//largest should equal index i as it's parent node, however if it is not then swap to sort 
		//call recursively to repeat process, "bubbling down" to fix tree
		if (largest != i)
		{
			swap(heap[i], heap[largest]);
			heapifyRoot(largest);
		}
	}
	//sorts any node of tree that is not the root (referes to parent for swap)
	void heapifyUp(int index)
	{
		while (index != 0 && heap[parent(index)] < heap[index])
		{
			//swap vector elements to reorder heap
			swap(heap[index], heap[parent(index)]);
			//want to track i after swap, set it equal to parent node and repeat 
			//continuously "bubbles up" till it reaches lowest point of heap: root (i = 0)
			index = parent(index);
		}
	}
	//enter value in heap to be removed
	void removeElement(int i)
	{
		int j;
		for (j = 0; j < size; j++)
		{
			if (heap[j] == i)
				break;
		}
		cout << "Swapping element at index " << j << " of value " << heap[j] << " with " << heap[size - 1] << endl;
		swap(heap[j], heap[size - 1]);
		size--;
		heapifyUp(j);
		//size--;
	}
	void printHeap()
	{
		int power = 0;
		int value = 1;
		for (int i = 0; i < size; i++)
		{
			//whenever i equals value, it has reached a new level of heap, again as each level has maximum nodes, n, equal to 2^n
			//add newline 
			//works because heaps are balanced 
			if (i == value)
			{
				cout << endl;
				power += 1;
				//left shift operator will shift bin equivalent 1 by an amount equal to var power
				//since binary numbers are position dependant and powers of 2, each shift equal to
				//multiplying 1 by some power of 2
				value += (1 << power);
			}
			cout << " " << heap[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Minheap heap(15);
	char c;
	int j = 0;
	for (int i = 0; i < 15; i++)
	{
		j = j + 5;
		cout << "Inserting element at " << i + 1 << endl;
		heap.insert(j);
		heap.printHeap();
		cout << endl;
	}
	int max;
	heap.removeElement(5);
	heap.printHeap();
	cout << endl;
	max = heap.getMax();
	cout << "Max " << max << endl;
	cin >> c;
}