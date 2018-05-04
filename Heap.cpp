#include "Heap.h"
#include "Student.h"
template <class T>
Heap<T>::Heap(int s)
{
	size = s;
	data = new T[size];
}
template <class T>
void Heap<T>::insert()
{
	//cout <<"inserting" << endl;
	T x = T();
	insert(x);
}
template <>
void Heap<int>::insert()
{
	cout <<"what would you lke to add?" << endl;
	int x = int();
	cin >> x;
	insert(x);
}
template <>
void Heap<Student>::insert()
{
	//cout <<"inserting" << endl;
	Student x = Student('a', 'b', 1);
	insert(x);
}
template <class T>
void Heap<T>::insert(T newData)
{
	int i = numNodes;
	while(i > 0 && data[parent(i)] < newData)
	{
		data[i] = data[parent(i)];
		i = parent(i);
	}
	data[i] = newData;
	numNodes++;
	//printHeap();
}
template <class T>
T Heap<T>::extractMax()
{
	if(numNodes < 1)
	{
		cout << "error: heap underflow";
		return data[0];	
	}	
	else
	{
		T max = data[0];
		data[0] = data[numNodes - 1];
		numNodes--;
		heapify(0);
		return max;
	}
}
template <class T>
void Heap<T>::buildHeap(T* A)
//be careful when using this if the array is empty, I'm not sure if sizeof will return the size of the datatype if the A[0] is null
{
	data = A;
	size = sizeof(A)/sizeof(A[0]);
	for(int i = (size/2)-1; i > 0; i--)
		heapify(i);
}
template <class T>
void Heap<T>::heapify(int i)
{
	int L = leftChild(i);
	int R = rightChild(i);
	int largest;

	if( L <= size && data[i] < data[L])
		largest = L;
	else
		largest = i;
	if( R <= size && data[largest] < data[R])
		largest = R;

	if(largest != i)
	{
		swap(i, largest);
		heapify(largest);
	} 
}
template <class T>
int Heap<T>::leftChild(int i)
{
	return (2*i+ 1);
}
template <class T>
int Heap<T>::rightChild(int i)
{
	return 2*i+2;
}
template <class T>
int Heap<T>::parent(int i)
{
	if(i%2 == 0)
		return (i-1)/2;
	else
		return i/2;
}
template <class T>
void Heap<T>::swap(int x, int y)
{
	T temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}

template <class T>
void Heap<T>::printHeap()
{
	for(int i = 0; i < size; i++)
		cout << data[i] << ", ";
	cout << endl << endl;
}
