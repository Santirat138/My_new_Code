#include<iostream>
#define nullStr "_"
#define nullNum -1
using namespace std;
//----------------- class info
class name{
	public:
		string fName;
		string lName;
};
class info{
	public:
		int id;
		name rName;
		int age;
};
//----------------- class node
class node{
	public:
		info data;
		node *prev;
		node *next;
		node(int idIn, string rNameIn, string lNameIn, int ageIn){
			data.id=idIn;
			data.rName.fName=rNameIn;
			data.rName.lName=lNameIn;
			data.age=ageIn;
			prev=nullptr;
			next=nullptr;
		}
};
//----------------- class linkList
class linkList{
	public:
		node *head;
		node *tail;
		linkList(){
			head=nullptr;
			tail=nullptr;
		}
		void linkNode(node *node1, node *node2);
		void addFirst(int idIn, string rNameIn, string lNameIn, int ageIn);
		void addLast(int idIn, string rNameIn, string lNameIn, int ageIn);
		void showLL();
		void sortId();// Bubble sort.
		void sortAge(); // Selection sort
};
void linkList::linkNode(node *node1, node *node2){
	node1->next=node2;
	node2->prev=node1;
}
void linkList::addFirst(int idIn, string rNameIn, string lNameIn, int ageIn){
	node *newNode=new node(idIn, rNameIn, lNameIn, ageIn);
	if(head!=nullptr){
		linkNode(newNode, head);
	}
	else{
		tail=newNode;
	}
	head=newNode;
}
void linkList::addLast(int idIn, string rNameIn, string lNameIn, int ageIn){
	node *newNode=new node(idIn, rNameIn, lNameIn, ageIn);
	if(tail!=nullptr){
		linkNode(tail, newNode);
	}
	else{
		head=newNode;
	}
	tail=newNode;
}
void linkList::showLL(){
	for(node *curr=head;curr!=nullptr;curr=curr->next){
		cout<<curr->data.id<<" : "<<curr->data.rName.fName<<" "<<curr->data.rName.lName<<"  ("<<curr->data.age<<")"<<endl;
	}
	cout<<endl;
}
void linkList::sortId(){
	node *currNode;
	node *lastNode=nullptr;
	bool swapped=true;
	while(swapped){
		currNode=head;
		swapped=false;
		while(currNode->next!=lastNode){
			if(currNode->data.id>currNode->next->data.id){
				swap(currNode->data, currNode->next->data);
				swapped=true;
			}
			currNode=currNode->next;
		}
		lastNode=currNode;
	}
}
void linkList::sortAge(){
	node *currNode;
	node *minNode=head;
	node *sortedNode=head;
	while(sortedNode->next!=nullptr){
		currNode=sortedNode->next;
		minNode=sortedNode;
		while(currNode!=nullptr){
			if(currNode->data.age<minNode->data.age){
				minNode=currNode;
			}
			currNode=currNode->next;
		}
		swap(sortedNode->data, minNode->data);
		sortedNode=sortedNode->next;
	}
}
//----------------- main
int main(){
	linkList *ll=new linkList();
	ll->addFirst(1001, "Aaa", "Bbb", 20);
	ll->addFirst(1002, "Bbb", "Ccc", 19);
	ll->addFirst(1003, "Bbb", "Ccc", 18);
	ll->addFirst(1004, "Bbb", "Ccc", 17);
	ll->showLL();
	ll->sortAge();
	ll->showLL();
}