#include <iostream>

using namespace std;

struct Node{
    char data;
    Node* next;
}*head,*ptr,*top;

Node* push(char item){
    Node *node = new Node();
    node->data = item;
    node->next = NULL;
    if(head == NULL){
        head = node;
        top = node;
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
        top = node;
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
        top = ptr;
        ptr->next = NULL;
    }
    else{
        temp = head->data;
        head = top = NULL;
    }
    return temp;
}

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 

void infixTopostfix(string s){
    string post_string;
    int i;
    char temp;
    for (i=0; s[i] != NULL; i++){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            post_string += s[i];
        }

        else if(s[i] == '('){
            push(s[i]);
        }

        else if(s[i] == ')'){
            while( top != NULL && top->data != '('){
                temp = pop();
                post_string += temp;
            }
            if(top->data == '('){
                pop();
            }
            
        }

        else{
            while(top != NULL && prec(s[i]) <= prec(top->data)) {
                char temp; 
                temp = pop(); 
                post_string += temp; 
            } 
            push(s[i]); 
        }
    }

    while(top != NULL) 
    { 
        char c; 
        c = pop(); 
        post_string += c; 
    } 
    
    cout<< "\n\t Postfix expression : "<< post_string << "\n";
}

int main(){
    string s;
    cout<< "Enter the string : ";
    cin>> s;
    infixTopostfix(s);
}