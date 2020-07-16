#include "vector.h"

int main(){
    cout<<"Vecotr Implementation : ";
    int *ptr = new int[2];
    int size = 2,num;
    char choice;

    do{
        cout<<"\n a. Insert an item";
        cout<<"\n b. Delete an item";
        cout<<"\n c. Item at index";
        cout<<"\n d. Set at index";
        cout<<"\n e. Exit";
        cout<<"\n Enter your choice : ";
        cin>> choice;
        switch (choice)
        {
        case 'a':
            /* code */
            cout<<"Enter the number : ";
            cin >>num;
            size = getsize(ptr,size);
            cout<<"\nThe size of the array : " << size <<"\n";
            push(ptr,num);
            cout<<"\n Elements in array : ";
            for(int i=0; i<=getcount(); i++)
                cout<<*(ptr+i)<<" ";
            break;

        case 'b':
            cout<<"Enter the number : ";
            cin >> num;
            del(ptr,num,size);
            for(int i=0; i<=getcount(); i++)
                cout<<*(ptr+i)<<" ";
            break;

        case 'c' :
            cout<<"Enter the index :";
            cin >> num;
            getItem(ptr,num);
            break;
        case 'd':
            int item;
            cout<<"Enter the index : ";
            cin >> num;
            cout<<"Enter the item to be inserted: ";
            cin>>item;
            setItem(ptr,num,item,size);
            for(int i=0; i<=getcount(); i++)
                cout<<*(ptr+i)<<" ";
            break;

        default:
            break;
        }

    }while(choice!='e');
    
}