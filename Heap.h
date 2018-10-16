#ifndef HEAP_H
#define HEAP_H
template<class T>
class pQNode
{
	int key;
	T data;
};


template <class T>
class Heap
{
public:
	T* data;
	int size;
	int arraySize;
	
	int leftChild(int);
	int rightChild(int);
	int parent(int);
	void swap(int, int);
	

	Heap(int = 100);
	
	void buildHeap(T*, int);
	void heapify(int);
	void increaseSize();
	
	void max();
	void peek();
	T extractMax();
	
	void insert(T);
	void insert();

	void printHeap();
	
	void heapSort(T*, int);
	
	T operator [](int);
private:
	void increaseKey();
};


#endif
