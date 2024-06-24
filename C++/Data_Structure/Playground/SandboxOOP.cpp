#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
}
node *nullNode=new node(-1);
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
        void addFirst(int newNum);
        void show();
        void addLast(int newNum);
        void deleteNode(node *targNode);
        node *findPrevNode(node *targNode);
    
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
void linkList::show(){
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<endl;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        tail->right=newNode;
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void linkList::deleteNode(node *targNode){
    if(targNode!=nullNode){
        if((targNode==head)&&(targNode==tail)){
            head=NULL;
            tail=NULL;
        }
        else if(targNode==head){
            head=head->right;
            targNode->right=NULL;
        }
        else if(targNode==tail){
            node *leftNode=findPrevNode(targNode);
            tail=leftNode;
            leftNode->right=NULL;
        }
        else{
            node *leftNode=findPrevNode(targNode);
            leftNode->right=targNode->right;
            targNode->right=NULL;
        }
    }
    else{
        cout<<"Can't delete node."<<endl;
    }
}
node *linkList::findPrevNode(node *targNode){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->right=targNode){
            return currNode;
        }
        else{
            currNode=currNode->right;
        }
    }
    return nullNode;
}
//*************** functions ***************

//*************** main ***************
int main(){
    linkList *list=new linkList();
    list->addFirst(1);
    list->addFirst(2);
    list->addFirst(3);
    list->show();
}
//*************** functions ***************