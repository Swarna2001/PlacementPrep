#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
}*head,*tail,*ptr;

void enQueue(int item){
    Node* node = new Node;
    node->data = item;
    node->next = NULL;
    if(head == NULL){
        head = tail = node;
        node->next = node;
    }
    else{
        tail->next = node;
        tail = node;
        node->next = head;
    }
}

void deQueue(){
    if(head == NULL){
        cout<< "\n\t No elements in the queue ";
    }
    else if(head == tail){
        head = tail = NULL ;
    }
    else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void display(){
    if(head != NULL){
        cout<< "\n\t The elements in the queue are : ";
        ptr = head;
        while(ptr != tail){
            cout<< ptr->data<< " -> ";
            ptr = ptr->next;
        }
        cout<< ptr->data;
    }
    else{
        cout<< "\n\t No elements in queue ";
    }
    
}

int main(){
    cout<< "\n\t Queue Implemetation ";
    char choice;
    int ch,item;
    do{
        cout<< "\n\t 1. EnQueue";
        cout<< "\n\t 2. DeQueue";
        cout<< "\n\t 3. Display";
        cout<< "\n\t Enter your choice : ";
        cin>> ch;
        switch (ch)
        {
        case 1: cout<< "\n\t Enter the item to be inserted in the queue : ";
                cin>> item;
                enQueue(item);
                display();
            /* code */
            break;
        case 2: deQueue();
                display();
            break;
        case 3: display();
            break;
        default:
            break;
        }
        cout<< "\n\t Do you want to continue ?";
        cin>> choice;
    }while(choice == 'y');
}