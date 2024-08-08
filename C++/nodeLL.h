#include<iostream>
using namespace std;
//------------- class -------------
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
class linkList{
	public:
		node *head;
		node *tail;
		linkList();
};
linkList::linkList(){
	head=NULL;
	tail=NULL;
}
//------------- functions -------------
void addFirst(linkList *list, int newNum){
	node *newNode=new node(newNum);
	if(list->head!=NULL){
		newNode->right=list->head;
	}
	else{
		list->tail=newNode;
	}
	list->head=newNode;
}
void addLast(linkList *list, int newNum){
	node *newNode=new node(newNum);
	if(list->tail!=NULL){
		list->tail->right=newNode;
	}
	else{
		list->head=newNode;
	}
	list->tail=newNode;
}
void showLL(linkList *list){
	node *currNode=list->head;
	while(currNode!=NULL){
		cout<<currNode->num<<" ";
		currNode=currNode->right;
	}
	cout<<endl;
}
void addBefore(linkList *list, int targNum, int newNum){
	node *newNode=new node(newNum);
	node *befNode=list->head;
	if(befNode!=NULL){
		if(list->head->num==targNum){
			addFirst(list, newNum);
		}
		else{
			bool numFound=false;
			while(befNode!=NULL){
				if(befNode->right->num==targNum){
					newNode->right=befNode->right;
					befNode->right=newNode;
					numFound=true;
					break;
				}
				else{
					befNode=befNode->right;
				}
			}
			if(!numFound){
				cout<<"Not found."<<endl;
			}
		}
	}
	else{
		cout<<"can't add."<<endl;
	}
}
void addAfter(linkList *list, int targNum, int newNum){
	node *newNode=new node(newNum);
	node *aftNode=list->head;
	if(aftNode!=NULL){
		if(list->tail->num==targNum){
			addLast(list, newNum);
		}
		else{
			bool numFound=false;
			while(aftNode!=NULL){
				if(aftNode->num==targNum){
					numFound=true;
					newNode->right=aftNode->right;
					aftNode->right=newNode;
					break;
				}
				else{
					aftNode=aftNode->right;
				}
			}
			if(!numFound){
				cout<<"Not found."<<endl;
			}
		}
	}
	else{
		cout<<"Can't add."<<endl;
	}
}
void deleteFirst(linkList *list){
	node *delNode=list->head;
	if((delNode!=NULL)&&(delNode->right!=NULL)){
		list->head=list->head->right;
		delNode->right=NULL;
	}
	else{
		cout<<"Can't delete."<<endl;
	}
}
void deleteLast(linkList *list){
	node *currNode=list->head;
	if((currNode!=NULL)&&(currNode->right!=NULL)){
		while(currNode->right!=list->tail){
			currNode=currNode->right;
		}
		list->tail=currNode;
		currNode->right=NULL;
	}
	else{
		cout<<"Can't delete."<<endl;
	}
}
void deleteNode(linkList *list, int targNum){
	node *currNode=list->head;
	if(currNode!=NULL){
		if((list->head->num==targNum)&&(list->tail->num==targNum)){
			list->head=NULL;
			list->tail=NULL;
		}
		else if((list->head->num==targNum)&&(list->tail->num!=targNum)){
			deleteFirst(list);
		}
		else if((list->head->num!=targNum)&&(list->tail->num!=targNum)){
			bool numFound=false;
			while(currNode!=NULL){
				if(currNode->right->num==targNum){
					currNode->right=currNode->right->right;
					numFound=true;
					break;
				}
				else{
					currNode=currNode->right;
				}
			}
			if(!numFound){
				cout<<"Not found."<<endl;
			}
		}
		else if((list->head->num!=targNum)&&(list->tail->num==targNum)){
			deleteLast(list);
		}
	}
	else if(currNode==NULL){
		cout<<"Can't delete."<<endl;
	}
}
