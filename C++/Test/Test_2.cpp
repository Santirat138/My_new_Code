// Copy Test_1
#include<iostream>
using namespace std;
class node{
    public:
        char ch;
        node *next;

        node(char charIn);
};
class linkList{
    public:
        node *head;
        node *nullNode;

        linkList(char headChar);
        void addFirst(char charIn);
        void showList(node *currNode);
};
class hashTable{
    public:
        int size;
        int key;
        string txt;
        linkList *arrayChar[];

        hashTable();
        int findKey(char charIn);
        void insertChar(string txtIn);
        void showAll();
        int countChar();
};
node::node(char charIn){
    ch=charIn;
    next=NULL;
}
linkList::linkList(char headChar){
    head=new node(headChar);
    nullNode=new node('-');
}
void linkList::addFirst(char charIn){
    node *newNode=new node(charIn);
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
        cout<<currNode->ch<<" ";
        showList(currNode->next);
    }
}
hashTable::hashTable(){
    size=26;
    for(int i=0;i<size;i++){
        arrayChar[i]=new linkList('-');
    }
}
int hashTable::findKey(char charIn){
    return (charIn-96)%size;
}
void hashTable::insertChar(string txtIn){
    for(int i=0;i<txtIn.length();i++){
        key=findKey(txtIn[i]);
        arrayChar[key]->addFirst(txtIn[i]);
    }
}
void hashTable::showAll(){
    for(int i=0;i<size;i++){
        cout<<"Index "<<i<<" ";
        cout<<"Char "<<arrayChar[i]->head->ch<<" : ";
        arrayChar[i]->showList(arrayChar[i]->head);
        cout<<endl;
    }
}
int hashTable::countChar(){
    
}
int main(){
    hashTable *table1=new hashTable();
    table1->insertChar("hellooohuman");
    table1->showAll();
}