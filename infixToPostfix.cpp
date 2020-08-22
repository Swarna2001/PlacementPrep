#include "stack.h"

#include <iostream>
using namespace std;

bool isOperand(char ch)
{
	if(ch == '^' || ch == '*' || ch == '+' || ch == '/' || ch == '-')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getPrecedenceValue(char symbol)
{
	if(symbol == '^')
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

void convertInfixToPrefix(char infixString[], char postfixString[])
{
	Stack myStack;
	myStack.pushItem('(');

	int i, j;
	char item;
	char x;

	i = j = 0;
	item = infixString[i];
	while(item != '\0')
	{

		if(item == '(')
		{
			myStack.pushItem(item);
		}
		else if(isdigit(item) || isalpha(item))
		{
			postfixString[j] = item;
			j++;
		}
		else if(isOperand(item))
		{
			x = myStack.popItem();
			while(isOperand(x) && getPrecedenceValue(x) >= getPrecedenceValue(item))
			{
				postfixString[j] = x;
				j++;
				x = myStack.popItem();
			}
			myStack.pushItem(x);
			myStack.pushItem(item);
		}
		else if(item == ')')
		{
			x = myStack.popItem();
			while(x != '(')
			{
				postfixString[j] = x;
				j++;
				x = myStack.popItem();
			}
		}
		else
		{
			cout << "ERROR - INVALID INFIX EXPRESSION" << endl;
			exit(1);
		}

		i++;

		item = infixString[i];
	}

	if(myStack.top == NULL)
	{
		postfixString[j] = '\0';
		return;
	}
	else
	{
		cout << "INVALID INFIX EXPRESSION" << endl;
		exit(1);
	}
}

int main()
{
	int n;
	cout << "Enter the length of your infix expression : ";
	cin >> n;

	char infixExpression[n+2];
	char postfixExpression[n];

	cout << "Enter your infix expression character by character : " << endl;

	for(int i = 0; i < n; i++)
	{
		cin >> infixExpression[i];
	}

	infixExpression[n] = ')';
	infixExpression[n+1] = '\0';

	convertInfixToPrefix(infixExpression, postfixExpression);

	cout << "The postfix expression is : " << endl;

	int j = 0;
	char item = postfixExpression[j];

	while(item != '\0')
	{
		cout << item;
		j++;
		item = postfixExpression[j];
	}
	cout << "\n";

}
