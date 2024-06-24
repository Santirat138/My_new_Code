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
//****************** functions ******************
void addFirst(node **headRef, int newNum);
void show(node *startNode);
void deleteNode(node **headRef, node *targNode);
node *findPrev(node **headRef, node *targNode);
void deleteAllTarg(node **headRef, int targNum);
//****************** main ******************
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(headRef, 1);
    addFirst(headRef, 2);
    addFirst(headRef, 3);
    addFirst(headRef, 1);
    addFirst(headRef, 2);
    addFirst(headRef, 6);
    addFirst(headRef, 1);
    addFirst(headRef, 2);
    addFirst(headRef, 2);
    addFirst(headRef, 1);
    deleteAllTarg(headRef, 2);
    show(*headRef);
}
//****************** functions ******************
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void show(node *startNode){
    node *currNode=startNode;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<"End."<<endl;
}
void deleteNode(node **headRef, node *targNode){
    if((targNode==*headRef)&&(targNode->right==NULL)){
        *headRef=NULL;
    }
    else if((targNode==*headRef)&&(targNode->right!=NULL)){
        *headRef=targNode->right;
        targNode->right=NULL;
    }
    else if((targNode!=*headRef)&&(targNode->right!=NULL)){
        node *leftNode=findPrev(headRef, targNode);
        if(leftNode!=nullNode){
            leftNode->right=targNode->right;
        }
    }
    else if((targNode!=*headRef)&&(targNode->right==NULL)){
        node *leftNode=findPrev(headRef, targNode);
        if(leftNode!=nullNode){
            leftNode->right=NULL;
        }
    }
}
node *findPrev(node **headRef, node *targNode){
    node *prevNode=*headRef;
    if((*headRef!=NULL)||(targNode!=*headRef)){
        while(prevNode->right!=targNode){
            prevNode=prevNode->right;
        }
    }
    else{
        prevNode=nullNode;
    }
    return prevNode;
}
void deleteAllTarg(node **headRef, int targNum){
    node *delNode=*headRef;
    while(delNode!=NULL){
        if(delNode->num==targNum){
            deleteNode(headRef, delNode);
            delNode=*headRef;
        }
        else{
            delNode=delNode->right;
        }
    }
}