#include<iostream>
#define errChar '_'
#define maxSize 20
using namespace std;
//-------------- global variable --------------
int top=0;
int tempTop=0;
char arrayCh[maxSize];
char temp[maxSize];
int arraySize;

//-------------- functions --------------------
string deleteSpacebar(string strIn);
bool isEmpty();
bool isFull();
void push(char charIn);
char pop();
void pushString(string strIn);
//-------------- main -------------------------
int main(){
    string strIn;
    getline(cin, strIn);
    string str=deleteSpacebar(strIn);
    pushString(str);
}
//-------------- functions --------------------
string deleteSpacebar(string strIn){
    string oldStr=strIn;
    string newStr;
    for(int i=0;i<oldStr.length();i++) {
        if(oldStr[i]!=' ') {
            newStr=newStr+oldStr[i];
        }
    }
    return newStr;
}
bool isEmpty(){
    if(top==0){
        return true;
    }
    else{
        return false;
    }
}
bool isFull(){
    if(top==maxSize-1){
        return true;
    }
    else{
        return false;
    }
}
void push(char charIn){
    if(!isFull()){
        arrayCh[top]=charIn;
        top++;
    }
    else{
        cout<<"Full"<<endl;
    }
}
char pop(){
    if(!isEmpty()){
        char sentChar=arrayCh[top-1];
        top--;
        return sentChar;
    }
    else{
        return errChar;
    }
}
void pushString(string strIn){
    bool isError;
    arraySize=strIn.length();
    for(int i=0;i<arraySize;i++){
        if(strIn[i]==' '){
            i++;
        }
        if((strIn[i]==')')&&(isEmpty())){
            isError=true;
            break;
        }
        else if(strIn[i]=='('){
            push('(');
        }
        else if(strIn[i]==')'){
            temp[tempTop]=pop();
            tempTop++;
        }
    }
    if(isEmpty()&&(!isError)){
        cout<<"Pass"<<endl;
    }
    else if((isError)||(tempTop!=0)){
        cout<<"Error"<<endl;
    }
}