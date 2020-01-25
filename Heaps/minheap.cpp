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
	int getMin()
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
			heapify(0);
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
		int i = size - 1;
		heap[i] = k;
		
		while (i != 0 && heap[parent(i)] > heap[i])
		{
			//swap vector elements to reorder heap
			swap(heap[i], heap[parent(i)]);
			//want to track i after swap, set it equal to parent node and repeat 
			//continuously "bubbles up" till it reaches lowest point of heap: root (i = 0)
			i = parent(i);
		}
	}
	//recursive function to maintain structure after root removal (polling operation)
	void heapify(int i)
	{
		//get indices of left, right children of node i
		//heapify called at root in getMin(), set that to smallest index for now
		int l = left(i);
		int r = right(i);
		int smallest = i;

		//set smallest node by finding value via heap vector
		if (heap[i] > heap[l])
			smallest = l;
		if (heap[i] > heap[r])
			smallest = r;

		//smallest should equal index i as it's parent node, however if it is not then swap to sort 
		//call recursively to repeat process, "bubbling down" to fix tree
		if (smallest != i)
		{
			swap(heap[i], heap[smallest]);
			heapify(smallest);
		}
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
	for (int i = 0; i < 15; i++)
	{
		cout << "Inserting element at " << i + 1 << endl;
		heap.insert(rand() % 100);
		heap.printHeap();
		cout << endl;
	}
	cin >> c;
}