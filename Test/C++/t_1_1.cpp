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
//-------------- functions --------------
void addFirst(node **headRef, node **tailRef, int newNum);
void showLL(node **headRef);
void deleteNode(node **headRef, node **tailRef, int targNum);
void insertAfter(node *head, node **tailRef, int aftNum, int newNum);
/* void deleteNode(node **headRef, node **tailRef, int targNum); */
//-------------- main --------------
int main(){
    node *head=NULL;
    node **headRef=&head;
    node *tail=NULL;
    node **tailRef=&tail;
    for(int i=0;i<=5;i++){
        addFirst(headRef, tailRef, i);
    }
    deleteNode(headRef, tailRef, 2);
    showLL(headRef);
}
//-------------- functions --------------
void addFirst(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if((*headRef==NULL)&&(*tailRef==NULL)){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else{
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void showLL(node **headRef){
    node *currNode=*headRef;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<endl;
}
void deleteNode(node **headRef, node **tailRef, int targNum){
    node *delNode=*headRef;
    while(delNode->right!=NULL){
        if(delNode->right->num==targNum){
            delNode->right=delNode->right->right;
        }
        else{
            delNode=delNode->right;
        }
    }
}
