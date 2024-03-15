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
        void addLast(int newNum);
        void show(node *currNode);
        void removeDupNum(node currNode, node checkNode);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        tail->next=newNode;
    }
    tail=newNode;
}
void linkList::show(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        show(currNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}
void linkList::removeDupNum(node currNode, node checkNode){
    
}
int main(){
    
}