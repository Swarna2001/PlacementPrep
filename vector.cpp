#include <iostream>
#include <stdlib.h>

using namespace std;

int* pointerToVector; 
int currSize = 2;
int numOfFilled = 0;

void addItem(int);
void deleteItem(int);
int findItemAtIndex(int);
void setItemAtIndex(int, int);
void displayVector();
bool vectorIsFull();

int main()
{
	pointerToVector = (int*) malloc(sizeof(int) * 2);
	char choice = 'y';
	while(choice == 'y')
	{
		system("clear");
		int ch = 0;
		cout << "Choose one of the following options " << endl;
		cout << "1. Add an item to the vector " << endl;
		cout << "2. Delete an item from the vector " <<endl;
		cout << "3. Get the item present at given index " <<endl;
		cout << "4. Set the item present at given index " <<endl;
		cout << "5. Display the data in the vector " << endl;
		cout << "Enter your choice (1 / 2 / 3 / 4 / 5) : " << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:
			{
				int dataToBeAdded = 0;
				cout << "Enter the data to be added " << endl;
				cin >> dataToBeAdded;
				addItem(dataToBeAdded);
				break;
			}
			case 2:
			{
				int dataToBeDeleted = 0;
				cout << "Enter the data to be deleted " << endl;
				cin >> dataToBeDeleted;
				deleteItem(dataToBeDeleted);
				break;
			}
			case 3:
			{
				int index;
				cout << "Enter the index : ";
				cin >> index;
				int result = findItemAtIndex(index);
				if(result == -1)
				{
					cout << "The index is invalid " << endl;
				}
				else
				{
					cout << "The element at the specified index is " << result << endl;
				}
				break;
			}
			case 4:
			{
				int index;
				int newElement;
				cout << "Enter the desired index : ";
				cin >> index;
				cout << "Enter the new element to be added : ";
				cin >> newElement;
				setItemAtIndex(index, newElement);
				break;
			}
			case 5:
				displayVector();
				break;
			default:
				cout << "Invalid option chosen" << endl;
		}

		cout << "Do you want to continue (y / n) ? ";
		cin >> choice;
//		cout << choice;
	}

	return 0;
}


/* This function is to check whether a given vector is full or not. It returns a bool value representing true if the vector is full, else false. */
bool vectorIsFull()
{
	if (numOfFilled == currSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/* Add an item to the given vector. If the capacity of the vector is aldready full, then double the size of the array. Then add the given element and free up extra space. */
void addItem(int newData)
{
	if(vectorIsFull())
	{
		int* newVector = (int*) malloc(sizeof(int) * (currSize * 2));
		currSize = currSize * 2;
		for(int i=0; i < numOfFilled; i++)
		{
			newVector[i] = pointerToVector[i];
		}
		newVector[numOfFilled] = newData;
		pointerToVector = newVector;
		numOfFilled += 1;
	}
	else
	{
		pointerToVector[numOfFilled] = newData;
		numOfFilled += 1;
	}
}

/* Delete an item from the given vector */
void deleteItem(int item)
{
	for(int i=0; i < numOfFilled; i++)
	{
		if(pointerToVector[i] == item)
		{
			int* temp1 = (int*) malloc(sizeof(int) * (numOfFilled - 1));
			for(int j=0; j < i; j++)
			{
				temp1[j] = pointerToVector[j];
			}
			for(int j=i+1; j < numOfFilled; j++)
			{
				temp1[j-1] = pointerToVector[j];
			}
			numOfFilled -= 1;
			pointerToVector = temp1;
			break;
		}
	}
}


/* Display the elements of the vector */
void displayVector()
{
	for(int i=0; i < numOfFilled; i++)
	{
		cout << pointerToVector[i] << endl;
	}
}

/* Find the element at a given position */
int findItemAtIndex(int index)
{
	int result = -1;
	if( index < numOfFilled)
	{
		return pointerToVector[index];
	}
	return result;
}

/* Set an element in the vector to a new one at the given specified index */
void setItemAtIndex(int index, int item)
{
	if(index < numOfFilled)
	{
		pointerToVector[index] = item;
	}
	else
	{
		cout << "The specified index is invalid" << endl;
	}
}
