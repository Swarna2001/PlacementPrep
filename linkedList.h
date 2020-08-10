#include<iostream>
#include<stdlib.h>
using namespace std;

/* The below class represent the nodes of the linked list .
   The data member "data" represent the value of data stored in the node.
   The data member "Node*" reprsent the next Node in the linked list, this node is pointing to.
*/
class Node
{
	public:
		int data;
		Node* next;
};

/* The below class represents the linked list.
   The data member "head" is a pointer that points to the node at the beginning of the linked list.
   The other are all member functions whose usage is described with their implementations.
*/
class LinkedList
{
	public:
		Node* head;
		void printList();
		void pushFront(int);
		int topFront();
		void popFront();
		void pushBack(int);
		int topBack();
		void popBack();
		bool empty();
		bool find(int);
		void erase(int);
		void insertNodeAtPosition(int, int);
};

/* The member function "insertNodeAtPosition" takes in two arguments.
   The first argument "pos" refers to the position at which the new data is to be inserted.(The starting node is designated position 1)
   The second argument "data" refers to the new data to be inserted.
*/
void LinkedList :: insertNodeAtPosition(int pos, int data)
{
	/* Starting node is designated position as 1. If given position is below that, it is invalid. */
	if(pos <= 0)
	{
		cout << "The given position is invalid" << endl;
	}
	else
	{
		/* currPos is a variable that is used to track the position of the node we are currently in */
		int currPos = 1;

		/* temp is a temporary pointer that is used to travers the linked list */
		Node* temp = this->head;

		/* We keep traversing till we reach either the end of the list or at the specified position */
		while(temp->next != NULL and currPos != pos)
		{
			temp = temp->next;
			currPos += 1;
		}
		currPos += 1;

		/* if position is beyond the end of list, it is invalid */
		if(temp->next == NULL and currPos != pos)
		{
			cout << "The given position is invalid " << endl;
		}
		else
		{
			/* adding the node at the specified position */
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}

/* This member function is used to add an new node to the linked list at the end.
   The argument "key" refers to the new data to be added to the list.
*/
void LinkedList :: pushBack(int key)
{
	/* Create a new node object to store the new data */
	Node* newNode = new Node();
	newNode->data = key;
	newNode->next = NULL;

	/* if the list is empty, simply update the head pointer */
	if(this->head == NULL)
	{
		this->head = newNode;
		return;
	}

	/* we traverse to the end of the list */
	Node* temp = this->head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}

	/* append the newly created node to the end of the list */
	temp->next = newNode;
}

/* This member function is used to add a new node to the starting of the linked list.
   The argument "key" refers to the new data to be added to the list.
*/
void LinkedList :: pushFront(int key)
{
	/* Create a new node object to store the "data" */
	Node* newNode = new Node();
	newNode->data = key;

	if(this->empty())
	{
		newNode->next = NULL;
		this->head = newNode;
	}
	else
	{
		/* Make the newNode pointing to the current head. Update the head pointer */
		newNode->next = this->head;
		this->head = newNode;
	}
}

/* This member function is to display the contents of the linked list */
void LinkedList :: printList()
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

/* This member function is used to return the element at the front of the list */
int LinkedList :: topFront()
{
	if(this->empty())
	{
		cout << "ERROR - List is empty" << endl;
		return(-1);
	}
	return this->head->data;
}

/* This member function is used to remove the element at the front of the list */
void LinkedList :: popFront()
{
	if(this->empty())
	{
		cout << "ERROR - List is empty" << endl;
		return;
	}
	Node* temp = this->head;
	this->head = this->head->next;
	free(temp);
	cout << "Item at the front has been successfully popped out" << endl;
}

/* This member function is used to return the element at the end of the list */
int LinkedList :: topBack()
{
	if(this->empty())
	{
		cout << "ERROR - List is empty" << endl;
		return(-1);
	}

	Node* temp = this->head;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp->data;
}

/* This member function is used to remove the element at the end of the list */
void LinkedList :: popBack()
{
	if(this->empty())
	{
		cout << "ERROR = List is empty" << endl;
		return;
	}

	if(this->head->next == NULL)
	{
		Node* temp = this->head;
		this->head = NULL;
		free(temp);
	}
	else
	{
		Node* temp = this->head;
		while(temp->next->next != NULL)
		{
			temp = temp->next;
		}
		Node* curr = temp->next;
		temp->next = NULL;
		free(curr);
	}
}

/* This member function is used to search for a given key in the linked list */
bool LinkedList :: find(int key)
{
	Node* temp = this->head;
	bool flag = false;
	while(temp != NULL)
	{
		if(temp->data == key)
		{
			flag = true;
			break;
		}
		temp = temp->next;
	}
	return flag;
}

/* This member function is used to remove a given key from the list */
void LinkedList :: erase(int key)
{
	if(find(key))
	{
		if(this->head->data == key)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			free(temp);
			return;
		}

		Node* temp = this->head->next;
		Node* prev = this->head;
		while(temp!=NULL)
		{
			if(temp->data == key)
			{
				prev->next = temp->next;
				free(temp);
				break;
			}
			prev = prev->next;
			temp = temp->next;
		}
	}
	else
	{
		cout << "INVALID KEY ERROR - Key is not present in the linked list" << endl;
	}
}

/* This function is used to check if the given list is empty or not */
bool LinkedList :: empty()
{
	if(this->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

