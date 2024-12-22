// Make Test_2 to use class.
#include<iostream>
using namespace std;
//-------------------------- class node
class node{
	public:
		int num;
		node *next;
		node(int numIn){
			num=numIn;
			next=NULL;
		}
};
//-------------------------- class linkList
class linkList{
	public:
		node *head;
		node *tail;
		linkList(){
			head=NULL;
			tail=NULL;
		}
		void addFirst(int newNum);
		void showLL();
		node *goBack(node *nodeIn);
		bool checkPalindrome();
};
void linkList::addFirst(int newNum){
	node *newNode=new node(newNum);
	if(head!=NULL){
		newNode->next=head;
	}
	else{
		tail=newNode;
	}
	head=newNode;
}
void linkList::showLL(){
	for(node *curr=head;curr!=NULL;curr=curr->next){
		cout<<curr->num<<" ";
	}
	cout<<endl;
}
node *linkList::goBack(node *nodeIn){
	node *curr=NULL;
	if(nodeIn!=head){
		for(curr=head;curr->next!=nodeIn;curr=curr->next){}
	}
	return curr;
}
bool linkList::checkPalindrome(){
	node *currLeft=head;
	node *currRight=tail;
	bool status=true;
	while(currLeft!=currRight){
		if(currLeft->num==currRight->num){
			currLeft=currLeft->next;
			if(currLeft==currRight){
				break;
			}
			currRight=goBack(currRight);
		}
		else{
			status=false;
			break;
		}
	}
	return status;
}
//-------------------------- function

//-------------------------- main
int main(){
	linkList *list=new linkList();
	list->addFirst(1);
	list->addFirst(2);
	list->addFirst(6);
	list->addFirst(2);
	list->addFirst(1);
	cout<<list->checkPalindrome();
}
//-------------------------- function
