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
//------------------ class hashTable
class hashTable{
	public:
		int hashSize=10;
        linkList *llArr[10];
		hashTable(){
			for(int i=0;i<hashSize;i++){
				llArr[i]=new linkList();
			}
		}
		int getKey(int numIn){
			return numIn%hashSize;
		}
		void addNum(int newNum){
			llArr[getKey(newNum)]->addFirst(newNum);
		}
		void showTable(){
			for(int i=0;i<hashSize;i++){
				llArr[i]->showLL();
			}
		}
};
//------------------ main
int main(){
	hashTable hashT;
	hashT.addNum(2);
	hashT.addNum(4);
	hashT.addNum(6);
	hashT.addNum(1);
	hashT.addNum(9);
	hashT.addNum(22);
	hashT.addNum(222);
	hashT.showTable();
}