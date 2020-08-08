#include <iostream>

using namespace std;

static int count  = 0;

/* Structure to create a node in the linked list */

struct Node {
    int data;
    Node *next;
}*head,*ptr,*tail;

/* Function to insert a node */

void insert(int item){
    Node* node = new Node();
    node->data = item;
    node->next = NULL;
    if(head == NULL){
        head = tail = node;
    }
    else{
        ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
        tail = node;
    }
    count++;
}

/* Function to create a loop for testing */

void create_loop(int item){
    int i = 1;
    ptr = head;
    while(i < item){
        ptr = ptr->next;
        i++;
    } 
    tail->next = ptr;
    tail = ptr;
}

/* Function to implement the hare and tortoise algorithm and find the starting of the loop */

void hare_tortoise(){
    Node *p, *q;
    p = q = head;
    while(p && q && q->next){
        p = p->next;
        q = q->next->next;
        if(p == q){
            cout<< "Loop exists";
            q = head;
            while(p != q){
                p = p->next;
                q = q->next;
            }
            cout<< "\n\t Starting data of the loop is : "<< p->data;
            return;
        }
    }
    cout<< "No loop exists";
    return;
}

/* Function to display the contents of the linked list  */

void display(){
    ptr = head;
    int i = 1;
    while(ptr != NULL && i != count+1){
        cout<<ptr->data <<" -> ";
        ptr = ptr->next;
        i++;
    }
    cout<< tail->data;
}

int main(){
    char choice;
    int item;
    do{
        cout<< "\n\t Enter the element you want to insert : ";
        cin>> item;
        insert(item);
        cout<< "\n\t Want to insert more elements : ";
        cin>> choice;
    }while(choice == 'y'); 
    cout<< count <<"\n";       
    display();
    cout<< "\n";
    cout<< "\n\t Want to create loop : (y/n)";
    cin>> choice;
    if(choice == 'y'){
        cout<< "Enter the starting index of the loop : ";
        cin>> item;
        create_loop(item);
    }
    display();
    cout<< "\n";
    hare_tortoise();
}