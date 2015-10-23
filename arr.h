#include <iostream>
using namespace std;

class array
{
private:
	int* myArray;
	int arraySize = 4;
	int varCount = 0;

	void arrayDoubler()
	{
		if (arraySize == varCount)
		{
			int* myArray2 = new int[(arraySize*2)];
			for (int i = 0; i < arraySize; ++i)
			{
				myArray2[i] = myArray[i];
			}
			delete [] myArray;
			myArray = myArray2;
			arraySize = arraySize*2;
		}	
	}
	
public:
	array()	//constructor
	{
		myArray = new int[4];
	}

	~array()
	{
		delete [] myArray;
	}
	int pop_front()
	{
		if (varCount == 0)
		{
			throw "Array is empty!";
		}
		int output = myArray[0];
		for (int i = 0; i < varCount; ++i)
		{
			myArray[i] = myArray[(i+1)];
		}
		varCount--;
		return output;
	}
	void push_back(int& x)
	{
		arrayDoubler();
		myArray[varCount] = x;
		varCount++;
	}
	int pop_back()
	{
		if (varCount != 0)
		{
			int output = myArray[varCount-1];
			varCount--;
			return output;
		}
		else
		{
			throw "Array is empty!";
		}
		
	}
	void print()
	{
		for (int i = 0; i < varCount; ++i)
		{
			cout << myArray[i] << " ";
		}
		cout << endl;
	}
};