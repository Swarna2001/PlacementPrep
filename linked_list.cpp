#include <iostream>

using namespace std;

/* structure to create a node of linked list*/

struct Node {
    int data;
    Node *next;
}*head,*ptr;

/* Function th check the length of the linked list*/

int check_length(){
    int length = 0;
    if(head == NULL)
        return length;
    else{
        ptr = head;
        while(ptr != NULL){
            ptr = ptr->next;
            length++;
        }
    }
    return length;
}


/* Function to insert an item in the linked list */

Node* insert(Node* head,int item,int pos){
    Node* node = new Node();
    node->data = item;
    node->next = NULL;
    if(head == NULL && pos == 1){
        head = node;
    }
    else if(pos == 1){
        node->next = head;
        head = node;
    }
    else{
        int count = 1;
        ptr = head;
        while(count < pos-1){
            ptr = ptr->next;
            count++;
        }
        node->next = ptr->next;
        ptr->next = node;
    }
    return head;

}

/* Function to delete an item at an index */

void del(int pos){
    int count = 1;
    Node *temp;
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    else{
        ptr = head;
        while(count < pos-1){
            count++;
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}

/* To check whether an item is present in the linked list */

void search(int item){
    ptr = head;
    while(ptr != NULL){
        if(ptr->data == item){
            cout<< "\n\t Item Found\n";
            return;
        }
        ptr = ptr->next;
    }
    cout<< "\n\t Item not Found\n";
    return;
}

/* Function to reverse the linked list */

void reverse(){
    Node* temp;
    ptr = head;
    while(ptr != NULL)
    {
        head  = insert(head,ptr->data,1);
        ptr = ptr->next;
    }
    int length = check_length();
    for(int i = 1; i<= length/2; i++){
        del(check_length());
    }
}

/* Function to display the contents of the linked list */

void display(){
    ptr = head;
    while(ptr != NULL){
        cout<< ptr->data<< " ";
        ptr = ptr->next;
    }
}

int main(){
    char choice;
    int pos, item, length;
    do{
        cout<< "Linked List Implemetation ";
        cout<< "\n\t a. Insert at position ";
        cout<< "\n\t b. Delete at position ";
        cout<< "\n\t c. Search ";
        cout<< "\n\t d. Reverse ";
        cout<< "\n\t e. Exit";
        cout<< "\n\t Enter your choice : ";
        cin>> choice;
        switch (choice)
        {
            case 'a': 
                cout<< "\n\t Enter the position (index starts a 1):";
                cin >> pos;
                cout<< "\n\t No. of elements in the list : "<<check_length();
                if(pos > check_length()+1){
                    cout<< "\n\t Invalid Index";
                }
                else{
                    cout<< "\n\t Enter the item to be inserted : ";
                    cin>> item;
                    head = insert(head,item,pos);
                }
                cout<< "\n\t Elements of the list : ";
                display();
                cout<< "\n";
                break;
            
            case 'b' :
                cout<< "\n\t Enter the position (index starts a 1):";
                cin >> pos;
                cout<< "\n\t No. of elements in the list : "<<check_length();
                if(pos > check_length()){
                    cout<< "\n\t Invalid Index";
                }
                else{
                    del(pos);
                }
                cout<< "\n\t Elements of the list : ";
                display();
                cout<< "\n";
                break;
            case 'c' :
                cout<< "\n\t Enter the element to be searched for : ";
                cin>> item;
                search(item);
                break;
            case 'd' :
                reverse();
                cout<< "\n\t Elements of the list : ";
                display();
                cout<< "\n";
                break;
            case 'e':
                break;
            default:
                cout<< "\n\t Wrong choice !!! ";
                break;
        }

    }while(choice != 'e');
}



