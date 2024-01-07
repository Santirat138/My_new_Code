// Find key in hash table for char.
#include<iostream>
using namespace std;
class node{
    public:
        char cha;
        node *next;

        node(char charIn);
};
class linkList{
    public:
        node *head;

        linkList();
        void addFirst(char newChar);
        void showList();
    };
class hashTable{
    public:
        int key;
        int size;
        linkList *array[];

        hashTable(int sizeIn);
        int findKey(char charIn);
        void insertChar(char newChar);
        void showAll();
};

node::node(char charIn){
    cha=charIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
}
void linkList::addFirst(char newChar){
    node *newNode=new node(newChar);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
}
void linkList::showList(){
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->cha<<" ";
        currNode=currNode->next;
    }
    cout<<endl;
}
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    array[size]=new linkList[size];
    for(int i=0;i<size;i++){
        array[i]=new linkList();
    }
}
int hashTable::findKey(char charIn){
    return (charIn-96)%size;
}
void hashTable::insertChar(char newChar){
    key=findKey(newChar);
    array[key]->addFirst(newChar);
}
void hashTable::showAll(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<" : ";
        array[i]->showList();
    }
}
int main(){
    hashTable *table1=new hashTable(26);
    table1->insertChar('a');
    table1->insertChar('v');
    table1->insertChar('x');
    table1->insertChar('a');
    table1->showAll();
}