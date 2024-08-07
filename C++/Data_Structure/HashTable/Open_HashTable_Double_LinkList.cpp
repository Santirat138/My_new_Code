#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;

        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        int amount;

        linkList();
        void connectNode(node *n1, node *n2);
        void addFirst(int numIn);
        void addLast(int numIn);
        void addSortMinMax(int numIn);
        void showHT(node *currNode);
        void showTH(node *currNode);
        void showList();
        void deleteFirst();
        void deleteLast();
        void countNode(node *currNode, int currAmount);
        node *findMidNum(node *currNode, int currPos);
		node *biFindNum(int numIn);
        void deleteNum(int numIn);
        
};
class hashTable{
    public:
        int num;
        int key;
        int size;
        linkList *arrayLL[];

        hashTable(int sizeIn);
        int setKey(int numIn);
        void insertNum(int newNum);
        void showAll();
        node *findNum(int numIn);
        void deleteNum(int numIn);
};
class stack{
    public:
        node *top;
        node *nullNode;

        stack();
        void push(int newNum);
};
class stackHashTable{
    public:

        
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=head;
    nullNode=new node(-1);
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::addFirst(int numIn){
    node *newNode=new node(numIn);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        connectNode(tail, newNode);
    }
    tail=newNode;
}
void linkList::addSortMinMax(int numIn){
    node *compNode=head;
    node *newNode=new node(numIn);
    if(compNode==NULL){
        head=newNode;
        tail=head;
    }
    else if(head==tail){
        if(numIn<head->num){
            addFirst(numIn);
        }
        else if(numIn>head->num){
            addLast(numIn);
        }
    }
    else{
        while(compNode!=NULL){
            if(compNode->next!=NULL){
                if((numIn<compNode->num)&&(numIn<compNode->next->num)){
                    addFirst(numIn);
                    break;
                }
                else if((numIn>compNode->num)&&(numIn<compNode->next->num)){
                    connectNode(newNode, compNode->next);
                    connectNode(compNode, newNode);
                    break;
                }
                else if((numIn>compNode->num)&&(numIn>compNode->next->num)){
                    compNode=compNode->next;
                }
            }
            else if(compNode->next==NULL){
                if(numIn>compNode->num){
                    addLast(numIn);
                }
                else if(numIn<compNode->num){
                    connectNode(compNode->prev, newNode);
                    connectNode(newNode, compNode);
                }
                break;
            }
        }
    }
    countNode(head, 0);
}
void linkList::showHT(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showHT(currNode->next);
    }
}
void linkList::showTH(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showTH(currNode->prev);
    }
}
void linkList::showList(){
    cout<<"Head --> Tail. ";
    showHT(head);
    cout<<"Tail --> Head. ";
    showTH(tail);
    cout<<endl<<endl;
}
void linkList::deleteFirst(){
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    amount--;
}
void linkList::deleteLast(){
    node *temp=tail;
    tail=tail->prev;
    temp->prev=NULL;
    tail->next=NULL;
    amount--;
}
void linkList::countNode(node *currNode, int currAmount){
	if(currNode==NULL){
		amount=currAmount;
	}
	else{
		countNode(currNode->next, currAmount+1);
	}
}
node *linkList::findMidNum(node *currNode, int currPos){
	if(currPos==amount/2){
		return currNode;
	}
	else{
		return findMidNum(currNode->next, currPos+1);
	}
}
node *linkList::biFindNum(int numIn){
	node *middleNode=findMidNum(head, 0);
	node *currNode=middleNode;
	if(numIn<middleNode->num){
		// Find left.
		while(currNode!=NULL){
			if(currNode->num==numIn){
				return currNode;
			}
			else{
				currNode=currNode->prev;
			}
		}
	}
	else if(numIn>middleNode->num){
		// Find right.
		while(currNode!=NULL){
			if(currNode->num==numIn){
				return currNode;
			}
			else{
				currNode=currNode->next;
			}
		}
	}
	else if(numIn==middleNode->num){
		return currNode;
	}
	return nullNode;
}
void linkList::deleteNum(int numIn){
    node *delNode=biFindNum(numIn);
    if(delNode==head){
        deleteFirst();
    }
    else if(delNode==tail){
        deleteLast();
    }
    else{
        connectNode(delNode->prev, delNode->next);
        delNode->prev=NULL;
        delNode->next=NULL;
        amount--;
    }
}
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    //arrayLL[size]=new linkList();
    for(int i=0;i<size;i++){
        arrayLL[i]=new linkList();
    }
}
int hashTable::setKey(int numIn){
    num=numIn;
    key=numIn%size;
    return key;
}
void hashTable::insertNum(int newNum){
    setKey(newNum);
    arrayLL[key]->addSortMinMax(newNum);
}
void hashTable::showAll(){
    cout<<endl;
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<endl;
        arrayLL[i]->showList();
    }
    cout<<endl;
}
node *hashTable::findNum(int numIn){
    int currKey=setKey(numIn);
    if(arrayLL[currKey]->head!=NULL){
        cout<<"Found in index "<<key<<"."<<endl;
        return arrayLL[currKey]->biFindNum(numIn);
    }
    else{
        return arrayLL[currKey]->nullNode;
    }
}
void hashTable::deleteNum(int numIn){
    int currKey=setKey(numIn);
    arrayLL[currKey]->deleteNum(numIn); 
}
stack::stack(){
    top=NULL;
    nullNode=new node(-1);
}
void stack::push(int newNum){
    
}
int main(){
    hashTable *table1=new hashTable(5);
    table1->insertNum(5);
    table1->insertNum(50);
    table1->insertNum(7);
    table1->insertNum(3);
    table1->insertNum(15);
    table1->showAll();
    
}