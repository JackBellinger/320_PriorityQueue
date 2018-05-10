#include <iostream>
#include "Heap.h"
#include "Student.h"
using namespace std;

int menu()
{
	int response = 0;

	cout << "Menu:" << endl;
	cout << "1. insert" << endl;
	cout << "2. extract max " << endl;
	cout << "3. print max" << endl;
	cout << "4. print heap" << endl;
	cout << "5. quit" << endl;
	cout << "Please input the option you would like: ";
	cin >> response;
	cout << "---------------------------------------" << endl;
	return response;
}
template <class T>
bool validateInput(int response, Heap<T>* heap, bool clearScreen)
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
				heap->insert();
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
	heap->printHeap();
	return quit;		  
}
void testData(Heap<int>* h)
{
		
	int testData[100] = {4, 12, 3, 19, 23, 5, 32, 11, 2, 24};
	h->buildHeap(testData, 10);
	h->printHeap();
}
int main()
{
	Heap<int>* iHeap = new Heap<int>();
	testData(iHeap);
	Heap<Student>* sHeap = new Heap<Student>(10);
	
	cout << "Choose a Heap type" << endl << "0. Student" << endl << "1. Integer" << endl;
	bool isIHeap = 0;
	cin >> isIHeap;
	
	bool clear = true;
	cin >> clear;
	cout << (clear?string(100, '\n'):"");
	bool quit = false;
	while(!quit)//menu asks for which option, which returns the choice into validateInput, which returns if the program should quit
	{
		if(isIHeap)
			quit = validateInput(menu(), iHeap, clear);
		else
			quit = validateInput(menu(), sHeap, clear);
	}
	return 0;
}
