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

void enQueue_front(int item){
    Node* node = new Node;
    node->data = item;
    node->next = NULL;
    if(head == NULL){
        head = tail = node;
        tail->next = node;
    }
    else{
        node->next = head;
        head = node;
        tail->next = head;
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

void deQueue_last(){
    if(head == NULL){
        cout<< "\n\t No elements in the queue ";
    }
    else if(head == tail){
        head = tail = NULL ;
    }
    else{
        ptr = head;
        while(ptr->next != tail){
            ptr = ptr->next;
        }
        Node *temp = tail;
        ptr->next = head;
        tail = ptr;
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
        cout<< "\n\t 1. EnQueue in last ";
        cout<< "\n\t 2. DeQueue from front ";
        cout<< "\n\t 3. EnQueue in front ";
        cout<< "\n\t 4. DeQueue from last";
        cout<< "\n\t 5. Display";
        cout<< "\n\t Enter your choice : ";
        cin>> ch;
        switch (ch)
        {
        case 1: cout<< "\n\t Enter the item to be inserted in the queue : ";
                cin>> item;
                enQueue(item);
                display();
            break;
        case 2: deQueue();
                display();
            break;
        case 3: cout<< "\n\t Enter the item to be inserted in the queue : ";
                cin>> item;
                enQueue_front(item);
                display();
            break;
        case 4: deQueue_last();
                display();
            break;
        case 5: display();
            break;
        default:
            break;
        }
        cout<< "\n\t Do you want to continue ?";
        cin>> choice;
    }while(choice == 'y');
}