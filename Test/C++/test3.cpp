// Test hash table.
#include<iostream>
using namespace std;
//------------------ class node
class node{
	public:
		int num;
		node *next;
		node(int numIn){
			num=numIn;
			next=NULL;
		}
};
//------------------ class linkList
class linkList{
	public:
		node *head=NULL;
		void addFirst(int newNum){
			node *newNode=new node(newNum);
			if(head!=NULL){
				newNode->next=head;
			}
			head=newNode;
		}
		void showLL(){
			for(node *curr=head;curr!=NULL;curr=curr->next){
                cout<<curr->num<<" ";
            }
            cout<<endl;
		}
};

//------------------ main
int main(){
	linkList *llArr[10];
	llArr[0]->addFirst(1);
	
}