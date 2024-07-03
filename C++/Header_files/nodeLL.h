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
//------------- link list -------------
class linkList{
	public:
		node *head;
		linkList();
		void addFirst(int newNum);
		void showList();
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
void linkList::showList(){
	node *currNode=head;
	while(currNode!=NULL){
		cout<<currNode->num<<" ";
		currNode=currNode->right;
	}
}