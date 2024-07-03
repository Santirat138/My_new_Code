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
        node *tail;
        linkList();
        void addFirst(int newNum);
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
class hashTable{
    public:
        linkList *list;
        int size;
        int mainArray[];
        hashTable(int sizeIn);
};
//--------------- functions ---------------
void showList(linkList *list);
//--------------- main ---------------
int main(){
    linkList *list=new linkList();
    for(int i=0;i<=5;i++){
        list->addFirst(i);
    }
    showList(list);
}
//--------------- functions ---------------
void showList(linkList *list){
    node *currNode=list->head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<"End."<<endl;
}