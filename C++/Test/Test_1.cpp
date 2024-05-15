#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        
        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *nullNode;

        linkList();
        void addFirst(int newNum);
        void showList(node *currNode);
            // New Methods
        void addSortMinMax(int numIn);
};
class hashTable{
    public:
        int key;
        int size;
        linkList *array[];

        hashTable(int sizeIn);
        int findKey(int numIn);
        void insertNum(int newNum);
        void showAll();
            // New Methods
        //void addMinMax(int newNum);
        
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    nullNode=new node(-1);
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
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
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
}
hashTable::hashTable(int sizeIn){
    size=sizeIn;
    array[size]=new linkList();
    for(int i=0;i<size;i++){
        array[i]=new linkList();
    }
}
int hashTable::findKey(int numIn){
    return numIn%size;
}
void hashTable::insertNum(int newNum){
    key=findKey(newNum);
    array[key]->addFirst(newNum);
}
void hashTable::showAll(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<": ";
        array[i]->showList(array[i]->head);
    }
}
void hashTable::sortMinMax(int newNum){

}
int main(){
    hashTable *table1=new hashTable(5);
    table1->insertNum(7);
    table1->insertNum(10);
    table1->insertNum(1);
    table1->insertNum(15);
    table1->insertNum(20);
    table1->showAll();
}