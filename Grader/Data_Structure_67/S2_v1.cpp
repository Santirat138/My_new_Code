#include<iostream>
#define max 10
using namespace std;
int top=0;
int array[max];
int amount=0;
//----------------- functions -----------------
bool isFull();
bool isEmpty();
void push(int newNum);
int pop();
void showAll();
void showTop();
void showFirstToLast();
void showSize();
//----------------- main -----------------
int main(){
    char chIn;
    int newNum;

    do{
        cin>>chIn;
        if(chIn=='U'){
            cin>>newNum;
            push(newNum);
        }
        else if(chIn=='O'){
            cout<<pop()<<endl;
        }
        else if(chIn=='T'){
            showTop();
        }
        else if(chIn=='P'){
            showFirstToLast();
            cout<<endl;
        }
        else if(chIn=='N'){
            cout<<top<<endl;
        }
    }
    while(chIn!='X');
}
//----------------- functions -----------------
bool isFull(){
    if(top==max-1){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}
void push(int newNum){
    if(!isFull()){
        array[top]=newNum;
        top++;
    }
    else{
        cout<<"Full"<<endl;
    }
}
int pop(){
    if(!isEmpty()){
        int sentNum=array[top-1];
        top--;
        return sentNum;
    }
    else{
        return -1;
    }
}
void showAll(){
    if(!isEmpty()){
        for(int i=top-1;i>=0;i--){
            cout<<array[i]<<endl;
        }
    }
    else{
        cout<<"Empty"<<endl;
    }
}
void showTop(){
    if(!isEmpty()){
        cout<<array[top-1]<<endl;
    }
    else{
        cout<<"Empty"<<endl;
    }
}
void showFirstToLast(){
    if(!isEmpty()){
        for(int i=0;i<top;i++){
            cout<<array[i]<<" ";
        }
    }
    else{
        cout<<"Empty"<<endl;
    }
}
void showSize(){
    if(!isEmpty()){
        cout<<top-1<<endl;
    }
    else{
        cout<<"0"<<endl;
    }
}