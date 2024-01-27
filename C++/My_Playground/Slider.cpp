// Array Linklist
// Bisection search in hashTable.
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

        linkList();
        void connectNode(node *n1, node *n2);
        void addSort(int numIn, node *compNode);
        void showList(node *currNode);
        void biSearch();
};
class hashTable{
    public:
        int size;
        linkList *arrayLL[];

        hashTable(int sizeIn);
        int findKey(int numIn);
        void insertNum(int newNum);
        void showAll();
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::addSort(int numIn, node *compNode){
    node *newNode=new node(numIn);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else if(head==tail){
        if(numIn<head->num){
            connectNode(newNode, head);
            head=newNode;
        }
        else if(numIn>tail->num){
            connectNode(tail, newNode);
            tail=newNode;
        }
    }
    else{
        if(compNode!=tail){
            if((numIn<compNode->num)&&(numIn<compNode->next->num)){
                connectNode(compNode, head);
                head=newNode;
            }
            else if((numIn>compNode->num)&&(numIn<compNode->next->num)){
                connectNode(newNode, compNode->next);
                connectNode(compNode, newNode);
            }
            else if((numIn>compNode->num)&&(numIn>compNode->next->num)){
                addSort(numIn, compNode->next);
            }
        }
        else if(compNode==tail){
            if(numIn<tail->num){
                connectNode(tail->prev, newNode);
                connectNode(newNode, tail);
            }
            else if(numIn>tail->num){
                connectNode(tail, newNode);
                tail=newNode;
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

hashTable::hashTable(int sizeIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        arrayLL[i]=new linkList();
    }
}
int hashTable::findKey(int numIn){
    return numIn%size;
}
void hashTable::insertNum(int newNum){
    int key=findKey(newNum);
    arrayLL[key]->addSort(newNum, arrayLL[key]->head);
}
void hashTable::showAll(){

}
int main(){

}