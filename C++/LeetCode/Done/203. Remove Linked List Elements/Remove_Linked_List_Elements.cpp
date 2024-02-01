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
        void showList(node *currNode);
        node *findNum(int numIn);
        node *findPrevNum(int numIn);
        void deleteNum(int numIn);
        void removeNum(int numIn);
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
    else if(tail==NULL){
        head=newNode;
    }
    tail=newNode;
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
node *linkList::findNum(int numIn){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->num==numIn){
            return currNode;
        }
        else{
            currNode=currNode->next;
        }
    }
    return NULL;
}
node *linkList::findPrevNum(int numIn){
    node *currNode=head;
    node *targetNode=findNum(numIn);
    while(currNode!=NULL){
        if(currNode->next==targetNode){
            return currNode;
        }
        else{
            currNode=currNode->next;
        }
    }
    return NULL;
}
void linkList::deleteNum(int numIn){
    node *delNode=findNum(numIn);
    if(delNode==head){
        node *temp=head;
        head=temp->next;
        temp->next=NULL;
    }
    else if(delNode==tail){
        node *prev=findPrevNum(numIn);
        prev->next=NULL;
    }
    else if((delNode==head)&&(delNode==tail)){
        head=NULL;
        tail=NULL;
    }
    else{
        node *prev=findPrevNum(numIn);
        prev->next=delNode->next;
        delNode->next=NULL;
    }
}
void linkList::removeNum(int numIn){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->num==numIn){
            deleteNum(numIn);
            currNode=head;
        }
        currNode=currNode->next;
    }
}
int main(){
    linkList *list1=new linkList();
    list1->addLast(1);
    list1->addLast(1);
    list1->addLast(1);
    list1->addLast(4);
    list1->addLast(1);
    list1->removeNum(1);
    list1->showList(list1->head);
}