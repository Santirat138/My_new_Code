#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn);
};
class doubleLinkList{
    public:
        node *head;
        node *tail;
        node *nullNode;
        doubleLinkList();
        void linkNode(node *n1, node *n2);
        void addFirst(int newNum);
        void addLast(int newNum);
        void addSort(int newNum, node *comp1, node *comp2);
        void showHT(node *currNode, int ticket);
        void doAddSort(int newNum);
        void doShow();
        
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
doubleLinkList::doubleLinkList(){
    head=NULL;
    tail=NULL;
    nullNode=new node(-1);
}
void doubleLinkList::linkNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void doubleLinkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        linkNode(newNode, head);
    }
    else{
        tail=newNode;
    }
    head=newNode;
}
void doubleLinkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        linkNode(tail, newNode);
    }
    else{
        head=newNode;
    }
    tail=newNode;
}
void doubleLinkList::addSort(int newNum, node *comp1, node *comp2){
    if(comp2!=tail){
        if((newNum<comp1->num)&&(newNum<comp2->num)){
            addFirst(newNum);
        }
        else if((newNum>comp1->num)&&(newNum<comp2->num)){
            node *newNode=new node(newNum);
            linkNode(comp1, newNode);
            linkNode(newNode, comp2);
        }
        else if((newNum>comp1->num)&&(newNum>comp2->num)){
            addSort(newNum, comp1->next, comp2->next);
        }
    }
    else if(comp2==tail){
        if((newNum<comp1->num)&&(newNum<comp2->num)){
            node *newNode=new node(newNum);
            linkNode(comp1->prev, newNode);
            linkNode(newNode, comp1);
        }
        else if((newNum>comp1->num)&&(newNum<comp2->num)){
            node *newNode=new node(newNum);
            linkNode(comp1, newNode);
            linkNode(newNode, comp2);
        }
        else if((newNum>comp1->num)&&(newNum>comp2->num)){
            addLast(newNum);
        }
    }
}
void doubleLinkList::showHT(node *currNode, int ticket){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        if(currNode==tail){
            cout<<endl<<tail->num<<" ";
            ticket=0;
        }
        if(ticket==1){
            showHT(currNode->next, ticket);
        }
        else if(ticket==0){
            showHT(currNode->prev, ticket);
        }
    }
    else{
        cout<<"End."<<endl;
    }
}
void doubleLinkList::doAddSort(int newNum){
    if((head!=NULL)&&(head->next!=NULL)&&(head!=tail)){
        addSort(newNum, head, head->next);
    }
    else if((head==tail)&&(head!=NULL)){
        if(newNum<head->num){
            addFirst(newNum);
        }
        else if(newNum>head->num){
            addLast(newNum);
        }
    }
    else if((head==NULL)&&(tail==NULL)){
        addFirst(newNum);
    }
}
void doubleLinkList::doShow(){
    showHT(head, 1);
}
int main(){
    doubleLinkList *list=new doubleLinkList();
    list->doAddSort(2);
    list->doAddSort(1);
    list->doAddSort(5);
    list->doAddSort(7);
    list->doAddSort(0);
    list->doShow();
}