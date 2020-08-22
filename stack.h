#include <iostream>
using namespace std;

class Node
{
	public :
		char data;
		Node* next;
};

class Stack
{
	public :
		Stack();
		Node* top;
		int numOfElements;
		void pushItem(char);
		char popItem();
		int lengthOfStack();
		char topItem();
		bool isEmpty();
};

/* This is the default constructor of the Stack object */
Stack :: Stack()
{
	top = NULL;
	numOfElements = 0;
}

/* This function is used to push an element into the top of the stack.
   It takes an integer parameter "item" as an argument.
*/
void Stack :: pushItem(char item)
{
	numOfElements += 1;

	Node* newNode = new Node();
	newNode->data = item;
	newNode->next = NULL;

	newNode->next = top;
	top = newNode;
}

/* This function is used to remove the element at the top of the stack */
char Stack :: popItem()
{
	if(isEmpty())
	{
		return(-1);
	}

	numOfElements -= 1;

	Node* temp = top;
	top = top->next;
	return temp->data;
}

/* This function returns the number of elements present in the stack */
int Stack :: lengthOfStack()
{
	return numOfElements;
}

/* This function reads the element present at the top of the stack and returns that value */
char Stack :: topItem()
{
	if(isEmpty())
	{
		return(-1);
	}
	else
	{
		return(top->data);
	}
}

/* This function checks if the stack is empty or not */
bool Stack :: isEmpty()
{
	if(numOfElements == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}




