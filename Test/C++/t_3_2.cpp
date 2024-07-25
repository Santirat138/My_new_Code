// Test stack.
#include<iostream>
#define max 10
#define errCh '-'
using namespace std;
int top=0;
char arrayCh[max];
//----------------- functions -----------------
bool isFull(){
    if(top>=max-1){
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
void push(char newCh){
    if(!isFull()){
        top++;
        arrayCh[top]=newCh;
    }
    else{
        cout<<"Full"<<endl;
    }
}
char pop(){
    if(!isEmpty()){
        char sentCh=arrayCh[top];
        top--;
        return sentCh;
    }
    else{
        return errCh;
    }
}
//----------------- main -----------------
int main(){
    push('p');
    push('l');
    push('e');
    push('u');

}