#include <iostream>

using namespace std;

struct Node{
    char data;
    Node* next;
}*head,*ptr;

Node* push(char item){
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

char pop(){
    ptr = head;
    char temp;
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

void check(char item){
    if(head == NULL){
        push(item);
        cout<< "\n\t Items in stack are ";
        display();
    }
    else{
        char temp;
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        if((ptr->data == '(' && item == ')') || (ptr->data == '{' && item == '}') || (ptr->data == '[' && item == ']')){
            temp = pop();
            cout<<"\n\t" <<temp<< " popped from the list ";
            cout<< "\n\t Items in stack are ";
            display();
        }
        else{
            push(item);
            cout<< "\n\t Items in stack are ";
            display();
        }
    }
    
}

int main(){
    int i,len;
    string s;
    cout<< "Enter the string : ";
    cin>> s;
    for(i=0; s[i] != NULL ; i++){
        if(s[i] == '[' || s[i] == '{' || s[i] == '(' || s[i] == ']' || s[i] == '}' || s[i] == ')'){
            check(s[i]);
        }
    }
    len = length();
    if(len > 0){
        cout<< "\n\t Unbalanced string ";
    }
    else{
        cout<< "\n\t Balanced string ";
    }
}