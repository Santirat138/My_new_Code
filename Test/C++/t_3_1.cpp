// Test stack.
#include<iostream>
#define max 5
#define errVal -1
using namespace std;
int top=0;
int array[max];
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
void push(int newNum){
    if(!isFull()){
        array[top]=newNum;
        top++;
    }
    else{
        cout<<"FULL"<<endl;
    }
}
int pop(){
    if(!isEmpty()){
        int sentNum=array[top];
        top--;
        return array[top];
    }
    else{
        return errVal;
    }
}
//----------------- main -----------------
int main(){
    push(1);
    push(2);
    push(3);
    cout<<pop()<<" ";
    cout<<pop()<<" ";
    cout<<pop()<<" ";

}