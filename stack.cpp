#include "stack.h"
#include <iostream>
using namespace std;

int main()
{
	Stack myStack;

	char flag = 'y';
	while(flag == 'y')
	{
		system("clear");

		int choice = 0;

		cout << "Choose one of the options given below : " << endl;
		cout << "1. Insert an element into the stack" << endl;
		cout << "2. Pop an element from the stack" << endl;
		cout << "3. Read the element present at the top of the stack" << endl;
		cout << "4. Calculate the number of elements present in the stack" << endl;
		cout << "5. Check if the given stack is empty or not " << endl;

		cout << "Enter your choice below (1 / 2 / 3 / 4 / 5) : " << endl;
		cin >> choice;

		switch(choice)
		{
			case 1:
			{
				int item1 = 0;
				cout << "Enter the data you would like to add into the stack : " << endl;
				cin >> item1;
				myStack.pushItem(item1);
				cout << "Data added into the stack successfully" << endl;
				break;
			}
			case 2:
			{
				int item2 = 0;
				item2 = myStack.popItem();
				if(item2 == -1)
				{
					cout << "ERROR : THE STACK IS EMPTY. REQUESTED OPERATION CANNOT BE PERFORMED" << endl;
				}
				else
				{
					cout << "The top element was successfully popped out from the stack" << endl;
					cout << "The popped out element is " << item2 << endl;
				}
				break;
			}
			case 3:
			{
				int item3 = 0;
				item3 = myStack.topItem();
				if(item3 == -1)
				{
					cout << "ERROR : THE STACK IS EMPTY. REQUESTED OPERATION CANNOT BE PERFORMED" << endl;
				}
				else
				{
					cout << "The element present at the top of the stack is " << item3 << endl;
				}
				break;
			}
			case 4:
			{
				int num = 0;
				num = myStack.lengthOfStack();
				cout << "The number of elements present in the stack is " << num << endl;
				break;
			}
			case 5:
			{
				if(myStack.isEmpty())
				{
					cout << "The given stack is empty" << endl;
				}
				else
				{
					cout << "The given stack is not empty" << endl;
				}
				break;
			}
			default:
				cout << "ERROR : INVALID OPTION CHOSEN" << endl;
				break;
		}

		cout << "Do you want to continue ? (y / n)" << endl;
		cin >> flag;
	}

	return(0);
}
