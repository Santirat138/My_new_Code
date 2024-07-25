#include <iostream>
#define max 10
#define errVal -1
using namespace std;
int array[max];
int head=0;
int tail=0;
int amount=0;
//------------------ functions ------------------
void enqueue(int newNum){
	if(amount<max){
		array[tail]=newNum;
		tail=(tail+1)%max;
		amount++;
	}
	else{
		cout<<"FULL"<<endl;
	}
}
int dequeue(){
	if(head-tail!=0){
		int sentNum=array[head];
		head=(head+1)%max;
		amount--;
		return sentNum; 
	}
	else{
		return errVal;
	}
}
void print(){
	if(tail<head){
		amount=tail+max-head;
	}
	else{
		amount=tail-head;
	}

	for(int i=head, c=0;c<amount;c++){
		cout<<array[i]<<" ";
		i=(i+1)%max;
	}
}

void mainFunc(){
	char chIn;
	int newNum;
	do{
		cin>>chIn;
		if(chIn=='e'){
			cin>>newNum;
			enqueue(newNum);
		}
		else if(chIn=='d'){
			cout<<dequeue();
			cout<<endl;
		}
		else if(chIn=='p'){
			print();
			cout<<endl;
		}	
		else if(chIn=='n'){
				cout<<amount<<endl;
		}
		else if(chIn=='s'){
			cout<<array[head]<<" "<<array[tail-1]<<endl;
		}
	}
	while(chIn!='x');
}
//------------------ main ------------------
int main() {
	mainFunc();
}