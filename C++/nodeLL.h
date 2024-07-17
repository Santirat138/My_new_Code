#include<iostream>
using namespace std;
//------------- node -------------
class node{
	public:
		int num;
		node *right;
		node(int numIn);
};
node::node(int numIn){
	num=numIn;
	right=NULL;
}
node *nullNode=new node(-1);
//------------- link List -------------
class linkList{
	public:
		node *head;
		node *tail;
		linkList();
		void addFirst(int newNum);
		void showList();
		node *findPrevNode(node *nodeIn);
		void addLast(int newNum);
		void addSort(int newNum);
		node *findNum(int targNum);
		void deleteNode(node *targNode);
		void deleteNum(int targNum);
};
linkList::linkList(){
	head=NULL;
	tail=NULL;
}
void linkList::addFirst(int newNum){
	node *newNode=new node(newNum);
	if(head!=NULL){
		newNode->right=head;
	}
	else{
		tail=newNode;
	}
	head=newNode;
}
void linkList::showList(){
	node *currNode=head;
	while(currNode!=NULL){
		cout<<currNode->num<<" ";
		currNode=currNode->right;
	}
	cout<<endl;
}
node *linkList::findPrevNode(node *nodeIn){
	if((nodeIn!=nullNode)||(nodeIn!=head)){
		node *prevNode=head;
		while(prevNode->right!=nodeIn){
			prevNode=prevNode->right;
		}
		return prevNode;
	}
	else{
		return nullNode;
	}
}
void linkList::addLast(int newNum){
	node *newNode=new node(newNum);
	if(tail!=NULL){
		tail->right=newNode;
	}
	else{
		head=newNode;
	}
	tail=newNode;
}
void linkList::addSort(int newNum){
	node *newNode=new node(newNum);
	if((head==NULL)&&(tail==NULL)){
		head=newNode;
		tail=newNode;
	}
	else if(head==tail){
		if(newNum<head->num){
			addFirst(newNum);
		}
		else if(newNum>head->num){
			addLast(newNum);
		}
	}
	else{
		node *compNode=head;
		while(compNode!=tail){
			if((newNum<compNode->num)&&(newNum<compNode->right->num)){
				addFirst(newNum);
				break;
			}
			else if((newNum>compNode->num)&&(newNum<compNode->right->num)){
				newNode->right=compNode->right;
				compNode->right=newNode;
				break;
			}
			else if((newNum>compNode->num)&&(newNum>compNode->num)){
				compNode=compNode->right;
			}
		}
		if(compNode==tail){
			if(newNum>compNode->num){
				addLast(newNum);
			}
		}
	}
}
node *linkList::findNum(int targNum){
	node *currNode;
	if(head!=NULL){
		currNode=head;
		while(currNode!=NULL){
			if(currNode->num==targNum){
				return currNode;
			}
			else{
				currNode=currNode->right;
			}
		}
	}
	else{
		return nullNode;
	}
}
void linkList::deleteNode(node *targNode){
	if((targNode==head)&&(targNode==tail)){
		head=NULL;
		tail=NULL;
	}
	else if((targNode==head)&&(targNode!=tail)){
		node *temp=head;
		head=head->right;
		temp=NULL;
	}
	else if((targNode!=head)&&(targNode!=tail)){
		node *prevNode=findPrevNode(targNode);
		prevNode->right=targNode->right;
		targNode->right=NULL;
	}
	else if((targNode!=head)&&(targNode==tail)){
		tail=findPrevNode(tail);
		tail->right=NULL;
	}
}
void linkList::deleteNum(int targNum){
	node *delNode=findNum(targNum);
	deleteNode(delNode);
}
//------------- hash table -------------
class hashTable{
	public:
		int size;
		linkList *arrayLL[];
		hashTable(int sizeIn);
		int findKey(int numIn);
		void insertNum(int newNum);
		void showTable();
		void deleteNum(int targNum);
};
hashTable::hashTable(int sizeIn){
	size=sizeIn;
	for(int i=0;i<size;i++){
		arrayLL[i]=new linkList();
	}
}
int hashTable::findKey(int numIn){
	return numIn%size;
}
void hashTable::insertNum(int newNum){
	int key=findKey(newNum);
	arrayLL[key]->addSort(newNum);
}
void hashTable::showTable(){
	for(int i=0;i<size;i++){
		arrayLL[i]->showList();
	}
}
void hashTable::deleteNum(int targNum){
	int key=findKey(targNum);
	arrayLL[key]->deleteNum(targNum);
}
