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
//-------------------- functions -------------------- 
void addFirst(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->right=*headRef;
    }
    else{
        *tailRef=newNode;
    }
    *headRef=newNode;
}
void addLast(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if(*tailRef!=NULL){
        (*tailRef)->right=newNode;
    }
    else{
        *headRef=newNode;
    }
    *tailRef=newNode;
}
void deleteFirst(node **headRef, node *tailRef){
    node *currNode=*headRef;
    if((currNode!=NULL)&&(currNode->right!=NULL)){
        *headRef=(*headRef)->right;
        currNode->right=NULL;        
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
void deleteLast(node *head, node **tailRef){
    node *currNode=head;
    if(currNode!=NULL){
        while(currNode->right!=*tailRef){
            currNode=currNode->right;
        }
        *tailRef=currNode;
        currNode->right=NULL;
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
void showLL(node *head){
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<endl;
}