#include <iostream>
#include "Heap.h"
#include "Student.h"
#include <chrono>
#include <ctime>
using namespace std;

void generateForwardSorted(int* array, double length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = i;
	}
}

void generateBackwardSorted(int* array, double length)
{
	
	for(int i = 0; i < length; i++)
	{
		array[i] = length - 1 - i;
	}
}
void generateRandomArray(int* array, double length)
{
	for(int i = 0; i < length; i++)
	{
		array[i] = rand() % (int)length;
	}	
}
void printArray(int* array, double length)
{
	for(int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
bool validateAscendingSort(int* array, double length)
{//checks if every element is greater than the previous
	for(int i = 1; i < length; i++)
		if(array[i - 1] > array[i])
		{	
			cout << array[i-1] << " > " << array[i] << endl;
			return false;
		}
	return true;
}
void timeHeapSort(Heap<int>* h, int* array, int length)
{
    // The "auto" type determines the correct type at compile-time
    auto start = std::chrono::system_clock::now();
    
   h->heapSort(array, length); 
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "finished at " << std::ctime(&end_time) 
         << "elapsed time: " << elapsed_seconds.count() << " s"
         << endl; // "\nNumber of swaps: " << swaps << "\n";
   //double checks that the array is sorted correctly
   if(validateAscendingSort(array, length))
	cout << "Array is Sorted Correctly";
    else
    	cout << "Array is not Sorted Correctly";
}


int menu()
{
	int response = 0;

	cout << "Menu:" << endl;
	cout << "1. insert" << endl;
	cout << "2. extract max " << endl;
	cout << "3. print max" << endl;
	cout << "4. print heap" << endl;
	cout << "5. test + time heap" << endl;
	cout << "6. quit" << endl;
	cout << "Please input the option you would like: ";
	cin >> response;
	cout << "---------------------------------------" << endl;
	return response;
}
void testHeap();
template <class T>
bool doMenu(int response, Heap<T>* heap, bool clearScreen)
/* returns a bool determining if the program should quit or not, 
 * true if the program should quit
*/
{
	bool quit = false;
	if(response >= 1 && response <= 5)
	{
		switch(response)
		{
			case 1:
			{
				//heap->insert();
				cout << (clearScreen?string(100, '\n'):"");
				break;
			}
			case 2:
			{
				cout << (clearScreen?string(100, '\n'):"");
				cout << heap->extractMax() << endl;
				break;
			}
			case 3:
			{
				heap->max();
				break;
			}
			case 4:
			{
				heap->printHeap();
				break;
			}
			case 5:
			{
				testHeap();
				break;
			}
			case 6:
			{
				cout << "back";
				quit = true;
				break;
			}
			
		}//end switch
	}
	else
	{
		cout << (clearScreen?string(100, '\n'):"");
		cout << "Please enter a valid integer" << endl << endl;
	}
	cout << endl;
	//heap->printHeap();
	return quit;		  
}
void testHeap()
{
	int numGenerators = 3;
        void(*generators[3])(int*, double);
        generators[0] = generateForwardSorted;
        generators[1] = generateBackwardSorted;
        generators[2] = generateRandomArray;
        string generatorNames[3] = {"Ascending Order", "Descending order", "Random order" };

//loop through all the different sizes, generated array types, and sorting algorithms and test the runtime and # swaps of each
        for(int SIZE = 10; SIZE <= 10000; SIZE *= 10)
        {
                int array[SIZE];
		Heap<int>* h = new Heap<int>(SIZE);

                for(int g = 0; g < numGenerators; g++)
		{        //for(int x = 0; x < 10; x++)used for more samples of random arrays
                                generators[g](array, SIZE);
                                cout << endl << endl
                                << "Array with " << SIZE
                                << " elements is in "
                                << generatorNames[g] <<
                                " and will be sorted by HeapSort" << endl;

                         	timeHeapSort(h, array, SIZE);
		}
		//delete [] array;

        }

}
int main()
{
	Heap<int>* iHeap = new Heap<int>();
	//testData(iHeap);
	Heap<Student>* sHeap = new Heap<Student>(10);
	
	cout << "Choose a Heap type" << endl << "0. Student" << endl << "1. Integer" << endl;
	bool isIHeap = 0;
	cin >> isIHeap;
	cout << "clear screen?";
	bool clear = true;
	cin >> clear;
	cout << (clear?string(100, '\n'):"");
	bool quit = false;
	while(!quit)//menu asks for which option, which returns the choice into doMenu, which returns if the program should quit
	{
		if(isIHeap)
			quit = doMenu(menu(), iHeap, clear);
		else
			quit = doMenu(menu(), sHeap, clear);
	}
	return 0;
}
