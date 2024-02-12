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
        linkList();
        void addLast(int newNum);
        void removeDup();
        void showList(node *currNode);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail==NULL){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
}
void linkList::removeDup(){
	node *curr=head;
	node *check;
	while((curr!=NULL)&&(curr->next!=NULL)){
		if(curr->next->num!=curr->num){
			curr=curr->next;
		}
		else if(curr->next->num==curr->num){
			check=curr;
			while((check!=tail)&&(check->next->num==check->num)){
				check=check->next;
			}
			if((check!=tail)&&(check->next->num!=check->num)){
				curr->next=check->next;
				check->next=NULL;
				curr=curr->next;
			}
			else if(check==tail){
				tail=curr;
				curr->next=NULL;
			}
		}
	}
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
int main(){
    linkList *list=new linkList();
    list->addLast(0);
    list->addLast(1);
    list->addLast(1);
    list->addLast(1);
    list->addLast(2);
    list->addLast(3);
    list->addLast(3);
    list->addLast(4);
    list->removeDup();
    list->showList(list->head);
}