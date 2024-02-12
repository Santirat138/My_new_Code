#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        linkList();
        void addLast(int numIn);
        void showList(node *currNode);
        node *findPrev(node *prevNode, int currNum);
        void makeRev();
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if(tail==NULL){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
}
void linkList::showList(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
}
node *linkList::findPrev(node *prevNode, int currNum){
	if(prevNode->next==NULL){
		return nullNode;
	}
	else{
		if(prevNode->next->num==currNum){
			return prevNode;
		}
		else{
			return findPrev(prevNode->next, currNum);
		}
	}
}
void linkList::makeRev(){
	node *curr=head;
	node *newTail=tail;
	while(curr!=nullNode){
		curr=findPrev(head, newTail->num);
		newTail->next=curr;
		curr->next=NULL;
		newTail=curr;
	}
    head=tail;
    tail=newTail;

}
int main(){
	linkList *list=new linkList();
	for(int i=0;i<=5;i++){
		list->addLast(i);
	}
	list->makeRev();
	list->showList(list->head);
}