#include<iostream>
using namespace std;
int amount=0;
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    left=nullptr;
    right=nullptr;
}
node *nullNode=new node(-1);
class linkList{
    public:
        node *head;
        node *tail;
        linkList();
};
linkList::linkList(){
    head=nullptr;
    tail=nullptr;
}
/* ###################### functions ###################### */
void linkNode(node *node1, node *node2){
    node1->right=node2;
    node2->left=node1;
}
void addFirst(linkList *list, int newNum){
    node *newNode=new node(newNum);
    if(list->head!=nullptr){
        linkNode(newNode, list->head);
    }
    else{
        list->tail=newNode;
    }
    list->head=newNode;
}
void addLast(linkList *list, int newNum){
    node *newNode=new node(newNum);
    if(list->tail!=nullptr){
        linkNode(list->tail, newNode);
    }
    else{
        list->head=newNode;
    }
    list->tail=newNode;
}
void showLL(linkList *list){
    node *currNode=list->head;
    while(currNode!=nullptr){
        cout<<currNode->num<<" ";
        currNode=currNode->right;
    }
    cout<<endl;
    currNode=list->tail;
    while(currNode!=nullptr){
        cout<<currNode->num<<" ";
        currNode=currNode->left;
    }
    cout<<endl;
}
node *findNode(linkList *list, int targNum){
    node *currNode=list->head;
    while(currNode!=nullptr){
        if(currNode->num==targNum){
            return currNode;
        }
        else{
            currNode=currNode->right;
        }
    }
    return nullNode;
}
void deleteNode(linkList *list, int targNum){
    node *delNode=findNode(list, targNum);
    if(delNode!=nullNode){
        if((delNode==list->head)&&(delNode==list->tail)){
            list->head=nullptr;
            list->tail=nullptr;
        }
        else if((delNode==list->head)&&(delNode!=list->tail)){
            linkNode(list->head, list->head->right);
            delNode->right=nullptr;
        }
        else if((delNode!=list->head)&&(delNode!=list->tail)){
            linkNode(delNode->left, delNode->right);
            delNode->left=nullptr;
            delNode->right=nullptr;
        }
        else if((delNode!=list->head)&&(delNode==list->tail)){
            list->tail=list->tail->left;
            list->tail->right=nullptr;
            delNode->left=nullptr;
        }
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
void countNode(linkList *list){
    node *currNode=list->head;
    while(currNode!=nullptr){
        amount++;
        currNode=currNode->right;
    }
}
node *findNodeAtPos(linkList *list, int targPos){
    countNode(list);
    node *currNode=list->head;
    if((currNode!=nullptr)&&(targPos<=amount)){
        int currPos=1;
        while(currNode!=nullptr){
            if(currPos==targPos){
                return currNode;
            }
            else{
                currNode=currNode->right;
                currPos++;
            }
        }
        return nullNode;
    }
    else{
        return nullNode;
    }
}
void addBefNode(linkList *list, int targNum, int newNum){
    node *newNode=new node(newNum);
    node *targNode=findNode(list, targNum);
    
}