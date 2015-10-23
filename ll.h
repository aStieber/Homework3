#include <iostream>
using namespace std;

class linked_list
{
	struct LinkedListNode
	{
		int data;
		LinkedListNode* next_node;
	};
private:
	int varCount = 0;
public:
	LinkedListNode head = new LinkedListNode;
	linked_list()//constructor
	{
		head->next_node = nullptr;
	}

	int pop_front()
	{
		if (varCount == 0)
		{
			throw "No more nodes in list!";
		}
		int x = head->next_node->data;
		LinkedListNode* tmpdel = head;
		head = head->next_node;	
		delete tmpdel;
		varCount--;

		return x;
	}

	void push_back(int input)
	{
		LinkedListNode* tmp = head;
		LinkedListNode* entry = new LinkedListNode;
		entry->data = input;
		entry->next_node = nullptr;
		if (varCount == 0)
		{
			head->next_node = entry;
		}
		else
		{		
			for (int i = 0; i < varCount; ++i)
			{
				tmp = tmp->next_node;
			}
			tmp->next_node = entry;
		}
		varCount++;
	}

	int pop_back()
	{
		if (varCount == 0)
		{
			throw "No more nodes in list!";
		}
		
		LinkedListNode* tmp = head->next_node;
		if (varCount == 1)
		{
			int x = tmp->data;
			delete tmp;
			head->next_node = nullptr;
			varCount--;
			return x;
		}

		for (int i = 0; i < (varCount-2); ++i)
		{
			tmp = tmp->next_node;
		}
		
		LinkedListNode* tmpdel = tmp->next_node;
		int x = tmpdel->data;
		delete tmpdel;
		tmp->next_node = nullptr;
		varCount--;
		return x;
	}

	void print()
	{
		LinkedListNode* tmp = head->next_node;
		for (int i = 0; i < varCount; ++i)
		{
			cout << tmp->data << " ";
			tmp = tmp->next_node;
		}
		cout << endl;
	}
};