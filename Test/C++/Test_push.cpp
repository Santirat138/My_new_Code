#include<iostream>
#define MAX 10
using namespace std;
//------------------------ class myStack
class myStack{
	public:
		string stack[MAX];
		int top=0;
};
//------------------------ functions
bool isEmpty(myStack stackIn){
	if(stackIn.top==0){
		return true;
	}
	return false;
}

myStack push1(myStack stackIn, string strIn){
	stackIn.stack[stackIn.top]=strIn;
	stackIn.top++;
	return stackIn;
}

void push2(myStack stackIn, string strIn){
	stackIn.stack[stackIn.top]=strIn;
	stackIn.top++;
}

string pop(myStack stackIn){
	if(!isEmpty(stackIn)){
		string tempStr=stackIn.stack[stackIn.top-1];
		stackIn.top--;
		return tempStr;
	}
}
void showStack(myStack stackIn){
	for(int i=stackIn.top-1;i>=0;i--){
		cout<<stackIn.stack[i]<<endl;
	}
	cout<<endl;
}
//------------------------ main
int main(){
	myStack stack1;
	myStack stack2;
	stack1=push1(stack1, "A");
	stack1=push1(stack1, "B");
	stack1=push1(stack1, "C");
	showStack(stack1);
}