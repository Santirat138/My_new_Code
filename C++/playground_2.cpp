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
node *nullNode=new node(-1);
//------------------ functions ------------------
void addFirst(node **headRef, int newNum);
void showList(node *currNode);
node *popLast(node **headRef);
node *findLastNode(node *head);
node *findPrevNode(node *head, node *nodeIn);
node *popFirst(node **headRef);
//------------------ main ------------------
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(headRef, 1);
    addFirst(headRef, 2);
    addFirst(headRef, 3);
    showList(head);
    cout<<popFirst(headRef)->num<<" ";
    cout<<popFirst(headRef)->num<<" ";
    cout<<popFirst(headRef)->num<<" ";
}
//------------------ functions ------------------
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void showList(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showList(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
node *popLast(node **headRef){
    node *currNode=findLastNode(*headRef);
    node *prevNode=findPrevNode(*headRef, currNode);
    prevNode->right=NULL;
    return currNode;
}
node *findLastNode(node *head){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->right==NULL){
            return currNode;
        }
        else{
            currNode=currNode->right;
        }
    }
    return nullNode;
}
node *findPrevNode(node *head, node *nodeIn){
    node *sentNode=head;
    while(sentNode!=NULL){
        if(sentNode->right==nodeIn){
            return sentNode;
        }
        else{
            sentNode=sentNode->right;
        }
    }
    return nullNode;
}
node *popFirst(node **headRef){
    node *temp=*headRef;
    *headRef=(*headRef)->right;
    temp->right=NULL;
    return temp;
}