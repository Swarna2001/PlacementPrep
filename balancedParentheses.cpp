#include "stack.h"
#include <iostream>
using namespace std;

#define MAX 20

bool checkBalanced(char inputString[])
{
	Stack tempStack;

	bool flag = false;
	char item;
	int currPos = 0;

	item = inputString[0];

	while(item != '$')
	{

		if(item == '(' || item == '{' || item == '[')
		{
			tempStack.pushItem(item);
		}
		else if(item == ')' || item == '}' || item == ']')
		{
			char topItem = tempStack.popItem();
			if( (topItem == '(' && item == ')') ||
			    (topItem == '{' && item == '}') ||
			    (topItem == '[' && item == ']'))
			{
			}
			else
			{
				break;
			}
		}

		currPos += 1;
		item = inputString[currPos];
	}


	if(tempStack.top == NULL)
	{
		flag = true;
	}
	else
	{
		flag = false;
	}

	return(flag);
}


int main()
{
	char givenString[MAX];
	cout << "Enter the expression ( specify $ at the end): " << endl;
	cin >> givenString;

	if(checkBalanced(givenString))
	{
		cout << "The given expression is balanced" << endl;
	}
	else
	{
		cout << "The given expression is unbalanced" << endl;
	}
	return(0);
}

