// Link list in array.
#include<iostream>
using namespace std;
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
class linkList{
    public:
        node *head;
        linkList();
        void addFirst(int newNum);
        void show(node *currNode);
};
linkList::linkList(){
    head=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->right=head;
    }
    head=newNode;
}
void linkList::show(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        show(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
class hashTable{
    public:
        linkList *list;
        linkList array[5];
        int size;
        hashTable(int sizeIn);
        int findKey(int numIn);
        void insertNum(int newNum);
        void show(int currIdx);
};
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i].head=NULL;
    }
}
int hashTable::findKey(int numIn){
    return numIn%size;
}
void hashTable::insertNum(int newNum){
    int key=findKey(newNum);
    array[key].addFirst(newNum);
}
void hashTable::show(int currIdx){
    if(currIdx<size){
        array[currIdx].show(array[currIdx].head);
        show(currIdx+1);
    }
    else{
        cout<<"End."<<endl;
    }
}
//-------------- functions --------------

//-------------- main --------------
int main(){
    hashTable *table=new hashTable(5);
    table->insertNum(1);
    table->insertNum(12);
    table->insertNum(13);
    table->insertNum(15);
    table->insertNum(150);
    table->insertNum(100);
    table->show(0);
}
//-------------- functions --------------