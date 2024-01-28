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
        linkList();
        void addFirst(int newNum);
        void showList(node *currNode);
        node *findNum(int numIn, node *currNode);
        void removeNum(int numIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
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
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
}
node *linkList::findNum(int numIn, node *currNode){
    if(currNode==NULL){
        return NULL;
    }
    else if(currNode->num==numIn){
        return currNode;
    }
    else{
        return findNum(numIn, currNode->next);
    }
}
void linkList::removeNum(int numIn){
    node *delNode=findNum(numIn, head);
    while(delNode!=NULL){
        
    }
}
int main(){

}