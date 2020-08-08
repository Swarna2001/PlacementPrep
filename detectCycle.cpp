#include<iostream>
using namespace std;

#include "linkedList.h"

/* This function is used to check if there are cycles present in the guven linked list.
   It uses the hare and tortoise algorithm to find that out.
*/

bool checkCycle(Node* ptr)
{
	if(ptr == NULL || ptr->next == NULL)
	{
		return(false);
	}

	Node* tortoise = ptr;
	Node* hare = ptr->next;

	while(hare != NULL && hare->next != NULL)
	{
		if(tortoise == hare)
		{
			return(true);
		}
		tortoise = tortoise->next;
		hare = hare->next->next;
	}

	return(false);
}

int main()
{
	LinkedList currList;
	currList.head = NULL;

	int n;
	cout << "Enter the number of elements of the linked list : " << endl;
	cin >> n;

	for(int i=0; i<n; i++)
	{
		int elt;
		cout << "Enter the element of the linked list : " << endl;
		cin >> elt;
		currList.pushBack(elt);
	}


	char choice = 'y';
	cout << "Do you want to create a cycle ? (y/n) " << endl;
	cin >> choice;
	if(choice == 'y')
	{
		int pos;
		cout << "Enter the place at which you want the cycle to start : " << endl;
		cout << "(the elements are nmbered as 1, 2, ....)" << endl;
		cin >> pos;
		if(n == 0 or n == 1 or pos < 0 or pos > n-2)
		{
			cout << "INVALID POSITION" << endl;
			return(0);
		}
		Node* tail = currList.head;
		while(tail->next !=NULL)
		{
			tail = tail->next;
		}
		Node* startCycle = currList.head;
		int start = 1;
		while(start != pos)
		{
			startCycle = startCycle->next;
			start += 1;
		}
		tail->next = startCycle;
	}

	cout << "RUNNING OUT THE HARE AND TORTOISE ALGORITHM TO CHECK FOR CYCLES..." << endl;

	if(checkCycle(currList.head))
	{
		cout << "A cycle is present in the given list " << endl;
	}
	else
	{
		cout << "No cycles are present in the given list " << endl;
	}

	return(0);
}
