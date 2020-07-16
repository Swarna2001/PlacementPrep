#include <iostream>
using namespace std;

static int count = 0;
int getsize(int*& ptr,int size){

    if(count == size){
        int *temp = new int[2*size];
        for(int i=0; i<size; i++){
            temp[i] = ptr[i];
        }
        delete [] ptr;
        ptr = temp;
        size = 2*size;
    }
    
    return size;
}

int getcount(){
    return count-1;
}

void push(int*& ptr,int item){
     ptr[count] = item;
     count++;
}

void del(int*& ptr,int item,int size){
    int flag = -1;
    for(int i=0;i<=getcount();i++){
        if(ptr[i] == item){
            flag = i;
            break;
        }
    }
    if(flag == -1){
        cout<<"Element Not Found";
    }
    else{
        int *temp = new int[size];
        for(int i=0; i<flag; i++){
                temp[i] = ptr[i];
        }
        for(int i = flag+1,j=flag; i<=getcount(); i++,j++){
                temp[j] = ptr[i];
        }
        delete [] ptr;
        ptr = temp;
        count--;
    }
}

void getItem(int*& ptr,int num){
     if(num > getcount()){
        cout<<"No value aasigned ";
    }
    else
    {
        cout<<ptr[num];
    }
    
}

void setItem(int*& ptr,int num,int item,int size){
    if(num >= size){
        cout<<"Invalid Index";
    }
    else{
        int *temp = new int[size];
        for(int i=0; i<num; i++){
                temp[i] = ptr[i];
        }
        temp[num] = item;
        for(int i = num+1,j=num; j<=getcount(); i++,j++){
                temp[i] = ptr[j];
        }
        delete [] ptr;
        ptr = temp;
        count++;
    }
}
