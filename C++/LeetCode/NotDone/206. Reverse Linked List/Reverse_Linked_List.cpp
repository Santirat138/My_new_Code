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
        node *tail;
        linkList();
        void addLast(int numIn);
        void showList(node *currNode);
        node *findPrev(node *nodeIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if(tail==NULL){
        head=newNode;
    }
    else{
        tail->next=newNode;
    }
    tail=newNode;
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
node *linkList::findPrev(node *nodeIn){
    
}
int main(){
    
}