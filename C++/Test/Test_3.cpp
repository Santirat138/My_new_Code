// Method_1 Use open hash table.
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
        
        linkList();
        void addFirst(char chIn);
        int countNode(node *currNode, int amount);
        void showList(node *currNode);
};
class hashTable{
    public:
        int key;
        int size;
        linkList *arrayChar[];

        hashTable(string txtIn);
        void showAll();
};
node::node(char charIn){
    ch=charIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    nullNode=new node('-');
}
void linkList::addFirst(char chIn){
    node *newNode=new node(chIn);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
}
int linkList::countNode(node *currNode, int amount){
    if(currNode==NULL){
        return amount;
    }
    else{
        return countNode(currNode->next, amount++);
    }
}
void linkList::showList(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->ch<<" ";
        showList(currNode->next);
    }
}
hashTable::hashTable(string txtIn){
    size=txtIn.length();
    arrayChar[size]=new linkList[size];
}
int main(){
    hashTable *table1=new hashTable("kkk");

}