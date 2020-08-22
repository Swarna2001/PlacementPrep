#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
}*head,*ptr;

Node* push(int item){
    Node *node = new Node();
    node->data = item;
    node->next = NULL;
    if(head == NULL){
        head = node;
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
    return head;
}

int pop(){
    ptr = head;
    int temp;
    if(ptr->next!= NULL){
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        temp = ptr->next->data;
        ptr->next = NULL;
    }
    else{
        temp = head->data;
        head = NULL;
    }
    return temp;
}

int length(){
    int count = 0;
    ptr = head;
    while(ptr != NULL){
        ptr = ptr->next;
        count++; 
    }
    return count;
}

void display(){
    if(head != NULL){
        ptr = head;
        while(ptr != NULL){
            cout<< ptr->data<< " -> ";
            ptr = ptr->next;
        }
    }
    else{
        cout<< "No elements in the stack";
    }
}

int main(){
    cout<< "\n\t Stack Implementation ";
    char choice;
    int ch,item,len;
    do{
        cout<< "\n\t 1. Push Element in the stack ";
        cout<< "\n\t 2. Pop Element from the stack ";
        cout<< "\n\t 3. Length of the stack ";
        cout<< "\n\t 4. Elements in the stack ";
        cout<< "\n\t Enter your choice ";
        cin>> ch;
        switch(ch){
            case 1 : cout<< "\n\t Enter the element to be pushed in stack : ";
                     cin>> item;
                     head = push(item);
                     cout<< "\n\t Items in stack are ";
                     display();
                break;
            
            case 2: item = pop();
                    cout<< "\n\t Item deleted from stack : "<<item;
                    cout<< "\n\t Items in stack are ";
                    display();
                break;
            case 3: len = length();
                    cout<< "\n\t Length of the stack is "<< len;
                break;
            case 4: cout<< "\n\t Items in stack are ";
                    display();
                break;
            default : cout<< "\n\t Wrong Choice";
        }
        cout<< "\n\t Do you want to continue ?(y/n) ";
        cin>> choice;
    }while(choice == 'y');
}