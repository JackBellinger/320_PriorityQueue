#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap
{
private:
	T* data;
	int numNodes = 0;
	int size;
	
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	void swap(int, int);
	

public:
	Heap(int = 15);
	
	void buildHeap(T*);
	void heapify(int);
	void heapSort();
	T extractMax();
	void insert(T);
	void insert();
	void printHeap();

};


#endif
