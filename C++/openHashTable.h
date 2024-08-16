#include<iostream>
#define maxSize 15
using namespace std;
//----------------- class node -----------------
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
//----------------- class linklist -----------------
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int newNum);
        void showLL();
};
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->right=head;
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void linkList::showLL(){
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
}
//----------------- class hashTable -----------------
class hashTable{
    public:
        linkList *array[maxSize];
        hashTable();
        int findKey(int numIn);
        void insertNum(int newNum);
        void showTable();
};
hashTable::hashTable(){
    for(int i=0;i<maxSize;i++){
        array[i]=new linkList();
    }
}
int hashTable::findKey(int numIn){
    return numIn%maxSize;
}
void hashTable::insertNum(int newNum){
    int key=findKey(newNum);
    array[key]->addFirst(newNum);
}
void hashTable::showTable(){
    for(int i=0;i<maxSize;i++){
        array[i]->showLL();
        cout<<endl;
    }
}