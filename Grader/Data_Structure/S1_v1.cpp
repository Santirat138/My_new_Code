#include<iostream>
#define max 20
#define errCh '-'
using namespace std;
int size;
int top=0;
char arrayCh[max];
//------------ functions ------------
bool isFull(){
    if(top==max){
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
/* void setArrayCh(string strIn){
    size=strIn.length();
    for(int i=0;i<size;i++){
        arrayCh[i]=strIn[i];
    }
    top=size-1;
} */
void push(char newCh){
    if(!isFull()){
        arrayCh[top]=newCh;
        top++;
        size++;
    }
    else{
        cout<<"Full"<<endl;
    }
}
char pop(){
    if(!isEmpty()){
        char sentChar=arrayCh[top-1];
        top--;
        size--;
        return sentChar;
    }
    else{
        return errCh;
    }
}
void mainFunc(){
    int orgSize=size;
    for(int i=0;i<orgSize;i++){
        if(arrayCh[i]=='('){
            push(arrayCh[i]);
        }
        else if(arrayCh[i]==')'){
            pop();
        }
    }
    if(!isEmpty()){
        cout<<"False";
    }
    else{
        cout<<"True";
    }
}
//------------ main ------------
int main(){
    push('(');
    push('(');
    push('1');
    push('+');
    push('3');
    push(')');
    push(')');
    mainFunc();
}