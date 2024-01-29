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
        node *findPrev(node *currNode, node *targetNode);
        void deleteNode(node *nodeIn);
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
node *linkList::findPrev(node *currNode ,node *targetNode){
    if(currNode==NULL){
        return NULL;
    }
    else if(currNode->next==targetNode){
        return currNode;
    }
    else{
        return findPrev(currNode->next, targetNode);
    }
}
void linkList::deleteNode(node *nodeIn){
    if(nodeIn==head){
        head=nodeIn->next;
        nodeIn->next=NULL;
    }
    else if(nodeIn->next==NULL){
        node *prevTail=findPrev(head, nodeIn);
        prevTail->next=NULL;
    }
    else{
        node *prevNode=findPrev(head, nodeIn);
        prevNode->next=nodeIn->next;
    }

}
void linkList::removeNum(int numIn){
    node *delNode=head;
    while(delNode!=NULL){
        if(delNode->num==numIn){
            deleteNode(delNode);
        }
        delNode=delNode->next;
    }
}
int main(){
    linkList *list1=new linkList();
    list1->addFirst(0);
    list1->addFirst(1);
    list1->addFirst(1);
    list1->addFirst(1);
    list1->addFirst(2);
    list1->addFirst(3);
    list1->addFirst(1);
    
    list1->showList(list1->head);
    list1->removeNum(1);
    list1->showList(list1->head);
}