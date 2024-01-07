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
        node *nullNode;

        linkList(char headChar);
        void addFirst(char newChar);
        void showList(node *currNode);
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
linkList::linkList(char headChar){
    head=new node(headChar);
    nullNode=new node('-');
}
void linkList::addFirst(char newChar){
    node *newNode=new node(newChar);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
}
void linkList::showList(node *currNode){
    if(currNode==NULL){
        cout<<" End."<<endl;
    }
    else{
        cout<<currNode->cha<<" ";
        showList(currNode->next);
    }
}
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    for(int i=0;i<size;i++){
        array[i]=new linkList('-');
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
    for(int i=1;i<size;i++){
        cout<<"Index "<<i<<" : ";
        array[i]->showList(array[i]->head);
    }
}
int main(){
    hashTable *table1=new hashTable(27);
    table1->insertChar('a');
    table1->insertChar('v');
    table1->insertChar('x');
    table1->insertChar('a');
    table1->insertChar('f');
    table1->insertChar('g');
    table1->insertChar('z');
    table1->insertChar('y');
    table1->showAll();
}