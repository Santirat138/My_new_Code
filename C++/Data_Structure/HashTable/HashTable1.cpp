// Test hashTable (class).
#include<iostream>
#define maxSize 10
#define nullNum -1
using namespace std;
//------------------------------------ class node
class node{
	public:
		int num;
		node *right;
		node(int newNum);
};
node::node(int newNum){
	num=newNum;
	right=NULL;
}
node *nullNode=new node(nullNum);
//------------------------------------ class linkList
class linkList{
	public:
		node *head;
		linkList();
		void addFirst(int newNum);
		void showLL();
		node *findNum(int targetNum);
		bool deleteNode(int targetNum);
};
linkList::linkList(){
	head=NULL;
}
void linkList::addFirst(int newNum){
	node *newNode=new node(newNum);
	if(head!=NULL){
		newNode->right=head;
	}
	head=newNode;
}
void linkList::showLL(){
	for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
		cout<<currNode->num<<" ";
	}
	cout<<endl;
}
node *linkList::findNum(int targetNum){
	for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
		if(currNode->num==targetNum){
			return currNode;
		}
	}
	return nullNode;
}
bool linkList::deleteNode(int targetNum){
	node *currNode=head;
	if(targetNum==head->num){
		head=head->right;
		currNode->right=NULL;
		return true;
	}
	for(currNode=head;currNode->right!=NULL;currNode=currNode->right){
		if(currNode->right->num==targetNum){
			node *temp=currNode->right;
			currNode->right=temp->right;
			temp->right=NULL;
			cout<<"Delete "<<targetNum<<"."<<endl;
			return true;
		}
	}
	cout<<"Can't delete "<<targetNum<<"."<<endl;
	return false;
}
//------------------------------------ class hashTable
class hashTable{
	public:
		linkList *arrLL[maxSize];
		hashTable();
		int findKey(int numIn);
		void insertNum(int newNum);
		void showTable();
		void deleteNum(int targteNum);
};
hashTable::hashTable(){
	for(int i=0;i<maxSize;i++){
		arrLL[i]=new linkList();
	}
}
int hashTable::findKey(int numIn){
	return numIn%maxSize;
}
void hashTable::insertNum(int newNum){
	int key=findKey(newNum);
	arrLL[key]->addFirst(newNum);
}
void hashTable::showTable(){
	for(int currIdx=0;currIdx<maxSize;currIdx++){
		if(arrLL[currIdx]->head==NULL){
			cout<<"Index "<<currIdx<<" is NULL."<<endl;
		}
		else{
			arrLL[currIdx]->showLL();
		}
	}
}
void hashTable::deleteNum(int targetNum){
	int targetIdx=findKey(targetNum);
	if(arrLL[targetIdx]->deleteNode(targetNum)){
		cout<<"Delete done."<<endl;
	}
	else{
		cout<<"Delete fail."<<endl;
	}
}
//------------------------------------ functions
void mainFunc(hashTable *tableIn);
//------------------------------------ main
int main(){
	hashTable *table=new hashTable();
	mainFunc(table);
}
//------------------------------------ functions
void mainFunc(hashTable *tableIn){
	string cmd;
	int num;
	do{
		cin>>cmd;
		if(cmd=="insert"){
			cin>>num;
			tableIn->insertNum(num);
		}
		else if(cmd=="delete"){
			cin>>num;
			tableIn->deleteNum(num);
		}
		else if(cmd=="showTable"){
			tableIn->showTable();
		}
		else if(cmd=="showUntil"){
			cin>>num;
			if(num<maxSize){
				for(int i=0;i<num;i++){
					if(tableIn->arrLL[i]->head==NULL){
						cout<<"Index "<<i<<" is NULL."<<endl;
					}
					else{
						tableIn->arrLL[i]->showLL();
					}
				}
			}
			else{
				cout<<"Can't show."<<endl;
			}
		}
		else if(cmd=="exit"){
			cout<<"Exit."<<endl;
			break;
		}
		else{
			cout<<"Command "<<cmd<<" is not found."<<endl;
		}
	}
	while(true);
}