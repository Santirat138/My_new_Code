// Test queue.
#include<iostream>
#define max 5
#define nullNum -1
using namespace std;
//----------------- variables -----------------
int head=0;
int tail=0;
int arrayQueue[max];
//----------------- functions -----------------
int count();
bool isFull();
bool isEmpty();
void enqueue(int newNum);
void showAll();
int dequeue();
//----------------- main ----------------------
int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    showAll();
    cout<<dequeue()<<endl;
    showAll();
}
//----------------- functions -----------------
int count(){
    if(tail<head){
        return tail+max-head;
    }
    else{
        return tail-head;
    }
}
bool isFull(){
    if(count()==max-1){
        return true;
    }
    else{
        return false;
    }
}
bool isEmpty(){
    if(tail==0){
        return true;
    }
    else{
        return false;
    }
}
void enqueue(int newNum){
    if(!isFull()){
        arrayQueue[tail]=newNum;
        tail=(tail+1)%max;
    }
    else{
        cout<<"Full"<<endl;
    }
}
void showAll(){
    if(!isEmpty()){
        for(int i=head;i<tail;i++){
            cout<<i<<" "<<arrayQueue[i]<<endl;
        }
    }
    else{
        cout<<"Empty"<<endl;
    }
}
int dequeue(){
    if(!isEmpty()){
        int sentNum=arrayQueue[head];
        head--;
        return sentNum;
    }
    else{
        return nullNum;
    }
}