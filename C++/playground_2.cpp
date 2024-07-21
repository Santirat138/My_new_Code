#include<iostream>
using namespace std;
//------------------ node ------------------
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
//------------------ link list ------------------
class linkList{
    public:
        node *head;
        node *tail;
        node *midNode;
        node *nullNode;
        int amount;
        linkList();
        void addFirst(int newNum);
        void showList();
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
    midNode=nullNode;
    nullNode=new node(-1);
    amount=0;
}
void linkList::addFirst(int newNum){
	node *newNode=new node(newNum);
	if(head!=NULL){
		newNode->right=head;
	}
	else{
		tail=newNode;
        midNode=tail;
	}
	head=newNode;
    amount++;
}
void linkList::showList(){
	node *currNode=head;
	while(currNode!=NULL){
		cout<<currNode->num<<" ";
		currNode=currNode->right;
	}
	cout<<endl;
}
//------------------ main ------------------
int main(){

}