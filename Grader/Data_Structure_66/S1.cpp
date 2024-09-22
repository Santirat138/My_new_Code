#include<iostream>
#define MAXSIZE 20
using namespace std;
//------------------- class
class stack{
    public:
        int array[MAXSIZE];
        int top;
        stack(){
            top=0;
        }
        bool isEmpty();
        bool isFull();
        int pop();
        void push(int newNum);
};
bool stack::isEmpty(){
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}
bool stack::isFull(){
    if(top==MAXSIZE){
        return true;
    }
    else{
        return false;
    }
}
int stack::pop(){
    
}
void stack::push(int newNum){

}
//------------------- functions
//------------------- main
int main(){

}