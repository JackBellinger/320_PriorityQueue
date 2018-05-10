#include "Heap.h"
#include "Student.h"

template <class T>
Heap<T>::Heap(int s)
{
	data = new T[s];
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
	cout <<"what would you lke to add," << endl;
	int x = int();
	cin >> x;
	insert(x);
}
template <>
void Heap<Student>::insert()
{
	//cout <<"inserting" << endl;
	Student x = Student();
	x.inputData();
	insert(x);
}
template <class T>
void Heap<T>::insert(T newData)
{
	int i = size;
	while(i > 0 && data[parent(i)] < newData)
	{
		data[i] = data[parent(i)];
		i = parent(i);
	}
	data[i] = newData;
	size++;
	//printHeap();
}
template <class T>
void Heap<T>::max()
{
	cout << " Max: " << data[0];
}
template <class T>
T Heap<T>::extractMax()
{
	if(size < 1)
	{
		cout << "error: heap underflow";
		return data[0];	
	}	
	else
	{
		T max = data[0];
		data[0] = data[size - 1];
		size--;
		heapify(0);
		return max;
	}
}
template <class T>
void Heap<T>::buildHeap(T* A, int s)
{
	//cout << "size: " << size << endl;
	for(int i = 0; i < s; i++)
	{
		//cout << "A[" << i << "] = " << A[i] << ", ";
		data[i] = i<s? A[i] : 0;
	}
	size = s;
	cout << "size: " << size << endl;
	//start at the last internal node and heapify - basically just heapsort the new array
	for(int i = (size/2)-1; i >= 0; i--)
	{
		cout << "heapifying: " << i << 	", ";
		heapify(i);
	}
	cout << endl;
}
template <class T>
void Heap<T>::heapify(int i)
{
	cout << "heapify " << data[i];
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
		cout << "swap " << data[i] << " and " << data[largest] << endl;
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

template <class T>
void Heap<T>::heapSort()
{
	for(int i = 0; i < size; i++)
		cout << extractMax() << ", ";
}
