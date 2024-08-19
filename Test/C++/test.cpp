#include<iostream>
#define nullCh '_'
#define maxSize 10
using namespace std;
//------------------ variables
bool err=false;
int top=0;
int array[maxSize];
int trash[maxSize];
//------------------ functions
void push(char chIn);
char pop();
void show();
void checkStr(string strIn);
//------------------ main
int main(){
    checkStr(")1+5(");
}
//------------------ functions
void push(char chIn){
    if(top<maxSize){
        array[top]=chIn;
        top++;
    }
    else{
        err=true;
        cout<<"Can't push."<<endl;
    }
}
char pop(){
    if(top>0){
        char tempCh=array[top-1];
        top--;
        return tempCh;
    }
    else{
        err=true;
        return nullCh;
    }
}
void show(){
    for(int i=top-1;i>0;i--){
        cout<<array[i]<<endl;
    }
    cout<<endl;
}
void checkStr(string strIn){
    for(int i=0;i<strIn.length();i++){
        if(strIn[i]=='('){
            push('(');
        }
        if(strIn[i]==')'){
            trash[i]=pop();
        }
    }
    if((top==0)&&(!err)){
        cout<<"Pass"<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }
}