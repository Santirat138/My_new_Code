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
class mainNode{
    public:
        node *head=NULL;
        node *tail=NULL;
};
//**************** functions ****************
void addFirst(mainNode *nodes, int newNum);
void show(mainNode *nodes);
void addLast(mainNode *nodes, int newNum);
void deleteNode(mainNode *nodes, node *delNode);
node *findPrevNode(node *currNode, node *targNode);
node *findNum(node *currNode, int targNum);
void deleteNum(mainNode *nodes, int delNum);
void makeRef(mainNode *nodes);
//**************** main ****************
int main(){
    mainNode *mNode=new mainNode();
    addFirst(mNode, 1);
    addFirst(mNode, 2);
    addFirst(mNode, 3);
    addFirst(mNode, 4);
    makeRef(mNode);
    show(mNode);
}
//**************** functions ****************
void addFirst(mainNode *nodes, int newNum){
    node *newNode=new node(newNum);
    if(nodes->head==NULL){
        nodes->tail=newNode;
    }
    else{
        newNode->right=nodes->head;
    }
    nodes->head=newNode;
}
void show(mainNode *nodes){
    node *currNode=nodes->head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<"End."<<endl;
}
void addLast(mainNode *nodes, int newNum){
    node *newNode=new node(newNum);
    if(nodes->tail==NULL){
        nodes->head=newNode;
    }
    else{
        nodes->tail->right=newNode;
    }
    nodes->tail=newNode;
}
void deleteNode(mainNode *nodes, node *delNode){
    if((delNode==nodes->head)&&(delNode==nodes->tail)){
        delNode==NULL;
    }
    else if(delNode==nodes->head){
        nodes->head=delNode->right;
        delNode->right=NULL;
    }
    else if(delNode==nodes->tail){
        node *newTail=findPrevNode(nodes->head, delNode);
        nodes->tail=newTail;
        newTail->right=NULL;
    }
    else{
        node *leftNode=findPrevNode(nodes->head, delNode);
        leftNode->right=delNode->right;
        delNode->right=NULL;
    }
}
node *findPrevNode(node *currNode, node *targNode){
    if(currNode->right==targNode){
        return currNode;
    }
    else{
        return findPrevNode(currNode->right, targNode);
    }
}
node *findNum(node *currNode, int targNum){
    if(currNode->num==targNum){
        return currNode;
    }
    else{
        return findNum(currNode->right, targNum);
    }
}
void deleteNum(mainNode *nodes, int delNum){
    deleteNode(nodes, findNum(nodes->head, delNum));
}
void makeRef(mainNode *nodes){
    node *leftNode=NULL;
    node *currNode=nodes->head;
    node *rightNode=nodes->head->right;
    while(currNode!=NULL){
        currNode->right=leftNode;
        leftNode=currNode;
        currNode=rightNode;
        if(rightNode->right!=NULL){
            rightNode=rightNode->right;
        }
        else{
            currNode->right=leftNode;
            break;
        }
    }
    nodes->tail=nodes->head;
    nodes->head=currNode;
}