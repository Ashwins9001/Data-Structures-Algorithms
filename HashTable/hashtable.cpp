#include <iostream>
#include <list>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//implement ht w sep chaining
class HashTable {
private:
	//buckets are indices of ht
	int buckets;
	//pointer to a last containing integers
	list<int> *table;
public:
	HashTable(int n)
	{
		buckets = n;
		//point to starting index of dynamically allocated array
		//each array elem contains a list of integers
		//each list implemented as doubly linked list
		table = new list<int>[buckets];
	}
	void insert(int data)
	{
		//bucket to insert data into
		int bucket = data % buckets; 
		//shift pointer to bucket for insertion, deref to list obj, access push_back method
		(table + bucket)->push_back(data);
	}
	void print()
	{
		char c;
		for (int i = 0; i < buckets; i++)
		{
			cout << "Bucket number: " << i << endl;
			//use auto to match iterator to list's data type 
			//iterate through list elements contained at each bucket
			for (auto j : table[i])
			{
				cout << "Value: " << j << " -> ";
			}
			cout << endl;
		}
		cin >> c;
	}

};

int main()
{
	HashTable ht(19);
	ht.insert(3);
	ht.insert(1);
	ht.insert(20);
	ht.insert(60);
	ht.insert(90);
	ht.insert(110);
	ht.insert(32);
	ht.insert(33);
	ht.insert(34);
	ht.insert(35);
	ht.insert(36);
	ht.insert(7);
	ht.insert(38);
	ht.insert(47);
	ht.insert(8);
	ht.insert(21);
	ht.insert(9);
	ht.insert(6);
	ht.insert(555);
	ht.insert(381);
	ht.print();
}