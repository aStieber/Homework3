#include <iostream>
#include <string>
#include "ll.h"
#include "arr.h"
using namespace std;
//clang++ main.cpp -std=c++11 && ./a.out


template<typename Container>
class stack
{
public:
	void push(int x)
	{
		mContainer.push_back(x);
	}
	void pop()
	{
		try
		{
			cout << mContainer.pop_back() << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
	void printit()
	{
		mContainer.print();
	}

private:
	Container mContainer;
};

template<typename Container>
class queue
{
public:
	void push(int x)
	{
		mContainer.push_back(x);
	}
	void pop()
	{
		try
		{
			cout << mContainer.pop_front() << endl;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
	void printit()
	{
		mContainer.print();
	}

private:
	Container mContainer;
};


int decider()//0:arraystack 1:arrayqueue 2:linkedliststack 3: linkedlistqueue
{
	int entry;
	int entry2;
	while (true)
	{
		cout << "1: Create Stack\n2: Create Queue\n3: Exit\n";
		cin >> entry;

		if (entry == 1 || entry == 2)
		{
			cout << "1: Array\n2: Singly linked list\n";
			cin >> entry2;
		}
		else
		{
			cout << "Quitting.\n";
			exit(EXIT_SUCCESS);
		}

		if (entry == 1 && entry2 == 1){return 0;}		//Array Stack
		else if (entry == 2 && entry2 == 1){return 1;}	//Array Queue
		else if (entry == 1 && entry2 == 2){return 2;}	//Linked List Stack		
		else if (entry == 2 && entry2 == 2){return 3;}	//Linked List Queue
		else
		{
			cout << "One or both entries invalid. Restarting.\n";
		}
	}
}

template<typename Container>
void Runner(Container& dS, string question)
{
	int uEntry;
	while (true)
	{
		cout << question;
		cin >> uEntry;

		switch(uEntry)
		{
			case 1:
				int pushvar;
				cout << "Enter the number to add: ";
				cin >> pushvar;

				dS.push(pushvar);
				break;

			case 2:
				dS.pop();
				break;

			case 3: 
				dS.printit();
				break;

			default:
				cout << "Quitting.\n";
				exit(EXIT_SUCCESS);
		}
	}
}


int main() {
	switch (decider())	//0:arraystack 1:arrayqueue 2:linkedliststack 3: linkedlistqueue
	{
		case 0:
		{
			stack<array> dataStructure;
			Runner(dataStructure, "1: PUSH\n2: POP\n3: PRINT STACK\n4: EXIT\n");
			break;	
		}
		case 1:
		{
			queue<array> dataStructure;
			Runner(dataStructure, "1: ENQUEUE\n2: DEQUEUE\n3: PRINT QUEUE\n4: EXIT\n");
			break;
		}
		case 2:
		{
			stack<linked_list> dataStructure;
			Runner(dataStructure, "1: PUSH\n2: POP\n3: PRINT STACK\n4: EXIT\n");
			break;
		}
		case 3:
		{
			queue<linked_list> dataStructure;
			Runner(dataStructure, "1: ENQUEUE\n2: DEQUEUE\n3: PRINT QUEUE\n4: EXIT\n");
			break;
		}
	}
		
	
	return 0;
}