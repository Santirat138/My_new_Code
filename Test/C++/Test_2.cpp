// Test stack ((1+1-(5).
#include<iostream>
#define MAX 15
#define NULLCH '_'
#define NULLSTR "_"
using namespace std;
//------------------------ class stack
class stack{
    public:
        int top=0;
        char array[MAX];
        bool isFull();
        bool isEmpty();
        void push(char chIn);
        char pop();
};
bool stack::isFull(){
    if(top==MAX){
        return true;
    }
    return false;
}
bool stack::isEmpty(){
    if(top==0){
        return true;
    }
    return false;
}
void stack::push(char chIn){
    if(!isFull()){
        array[top]=chIn;
        top++;
    }
    else{
        cout<<"Full"<<endl;
    }
}
char stack::pop(){
    if(!isEmpty()){
        char temp=array[top-1];
        top--;
        return temp;
    }
    else{
        return NULLCH;
    }
}
//------------------------ class myBox
class myBox{
    public:
        stack stackMain;
        stack stackTemp;
        void checkSyntax(string strIn);
};
void myBox::checkSyntax(string strIn){
    int strSize=strIn.length();
    int tempI=0;
    for(int i=0;i<strSize;i++){
        if(strIn[i]==' '){
            i++;
        }
        if(strIn[i]=='('){
            stackMain.push('(');
        }
        else if(strIn[i]==')'){
            if(stackMain.isEmpty()){
                cout<<"False."<<endl;
                return ;
            }
            stackTemp.array[tempI]=stackMain.pop();
            tempI++;
        }
    }
    if(stackTemp.isEmpty()&&stackMain.isEmpty()){
        cout<<"True."<<endl;
    }
    else{
        cout<<"False."<<endl;
    }
}
//------------------------ main
int main(){
    myBox box;
    box.checkSyntax("(5+8)");
}