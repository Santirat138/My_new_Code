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
//----------------- main -----------------
int main(){

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

}