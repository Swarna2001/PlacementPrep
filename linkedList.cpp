#include<iostream>
using namespace std;
#include "linkedList.h"

int main()
{
	LinkedList myList;
	myList.head = NULL;

	char choice = 'y';
	while(choice == 'y')
	{
		system("clear");

		cout << "Choose one of the options below " << endl;
		cout << "1. Insert a new element at the head of the linked list " << endl;
		cout << "2. Insert a new element at the end of the linked list " << endl;
		cout << "3. Insert a new element at the specified position of the linked list " << endl;
		cout << "4. Delete an item from the linked list " << endl;
		cout << "5. Display the elements of the linked list " << endl;
		cout << "6. Get the data present at the beginning of the list " << endl;
		cout << "7. Get the data present at the end of the list" << endl;
		cout << "8. Delete the item at the beginning of the list" << endl;
		cout << "9. Delete the item at the end of the list " << endl;
		cout << "10. Search for an item in the linked list" << endl;

		int currChoice = 0;
		cout << "Enter your choice : " << endl;
		cin >> currChoice;

		if(currChoice == 1)
		{
			int data;
			cout << " Enter the data to be inserted : " << endl;
			cin >> data;
			myList.pushFront(data);
		}
		else if(currChoice == 2)
		{
			int data;
			cout << "Enter data to be inserted : " << endl;
			cin >> data;
			myList.pushBack(data);
		}
		else if(currChoice == 3)
		{
			int data, pos;
			cout << "Enter the data to be inserted : " << endl;
			cin >> data;
			cout << "Enter the position where the data to be inserted : " << endl;
			cin >> pos;
			myList.insertNodeAtPosition(pos, data);
		}
		else if(currChoice == 4)
		{
			int key;
			cout << "Enter the key to be deleted : " << endl;
			cin >> key;
			myList.erase(key);
		}
		else if(currChoice == 5)
		{
			myList.printList();
		}
		else if(currChoice == 6)
		{
			int ans = myList.topFront();
			if(ans != -1)
			{
				cout << "The element at the beginning of the list is " << ans << endl;
			}
		}
		else if(currChoice == 7)
		{
			int ans = myList.topBack();
			if(ans != -1)
			{
				cout << "The element at the end of the list is " << ans << endl;
			}
		}
		else if(currChoice == 8)
		{
			myList.popFront();
		}
		else if(currChoice == 9)
		{
			myList.popBack();
		}
		else if(currChoice == 10)
		{
			int data;
			cout << "Enter the key to be searched : " << endl;
			cin >> data;
			if(myList.find(data))
			{
				cout << "The key is present in the linked list" << endl;
			}
			else
			{
				cout << "The key is not present in the linked list" << endl;
			}
		}
		else
		{
			cout << "You have chosen an invalid option " << endl;
		}

		cout << "Do you want to continue (y/n) ? " << endl;
		cin >> choice;

	}

/*	LinkedList myList;
	myList.head = new Node();

	Node* second = NULL;
	Node* third = NULL;

	second = new Node();
	third = new Node();

	myList.head->data = 1;
	myList.head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	//cout << myListhead->data << head->next->data << head->next->next->data << endl;

//	myList.printList();
	myList.insertNodeAtFirst(4);
	myList.insertNodeAtEnd(5);
	myList.insertNodeAtPosition(2, 6);
	myList.insertNodeAtPosition(3, 7);
	myList.insertNodeAtPosition(8, 8);
	myList.insertNodeAtPosition(0, 0);
	myList.printList();
*/	return 0;
}
