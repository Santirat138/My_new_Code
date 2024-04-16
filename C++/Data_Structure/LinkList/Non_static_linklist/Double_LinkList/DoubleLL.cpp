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
        int amount;
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
        node *findNode(int numIn, node *currNode);
        void deleteNode(int numIn);
        node *findByPos(int posIn, int currPos, node *currNode);
        node *doFindByPos(int posIn);
        void deleteByPos(int posIn);
        void deleteAllNode(int numIn, node *currNode);
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
doubleLinkList::doubleLinkList(){
    amount=0;
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
        amount++;
    }
    else{
        tail=newNode;
        amount=1;
    }
    head=newNode;
}
void doubleLinkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(tail!=NULL){
        linkNode(tail, newNode);
        amount++;
    }
    else{
        head=newNode;
        amount=1;
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
            amount++;
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
            amount++;
        }
        else if((newNum>comp1->num)&&(newNum<comp2->num)){
            node *newNode=new node(newNum);
            linkNode(comp1, newNode);
            linkNode(newNode, comp2);
            amount++;
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
node *doubleLinkList::findNode(int numIn, node *currNode){
    if(currNode!=NULL){
        if(currNode->num==numIn){
            return currNode;
        }
        else{
            return findNode(numIn, currNode->next);
        }
    }
    else{
        return nullNode;
    }
}
void doubleLinkList::deleteNode(int numIn){
    node *delNode=findNode(numIn, head);
    if(delNode->num==numIn){
        if(delNode==head){
            head=head->next;
            head->prev=NULL;
            delNode->next=NULL;
        }
        else if(delNode==tail){
            tail=tail->prev;
            tail->next=NULL;
            delNode->prev=NULL;
        }
        else{
            linkNode(delNode->prev, delNode->next);
            delNode->prev=NULL;
            delNode->next=NULL;
        }
        amount--;
    }
    else{
        cout<<"Can't delete."<<endl;
    }
}
node *doubleLinkList::findByPos(int posIn, int currPos, node *currNode){
    if(currPos==posIn){
        return currNode;
    }
    else{
        return findByPos(posIn, currPos+1, currNode->next);
    }
}
node *doubleLinkList::doFindByPos(int posIn){
    if(posIn<=0){
        posIn=1;
    }
    else if(posIn>amount){
        posIn=amount;
    }
    return findByPos(posIn, 1, head);
}
void doubleLinkList::deleteByPos(int posIn){
    node *delNode=findByPos(posIn, 1, head);
    deleteNode(delNode->num);
}
void doubleLinkList::deleteAllNode(int numIn, node *currNode){
    node *delNode=findNode(numIn, currNode);
    if(currNode!=NULL){
        
    }
}
int main(){
    doubleLinkList *list=new doubleLinkList();
    list->doAddSort(2);
    list->doAddSort(1);
    list->doAddSort(5);
    list->doAddSort(7);
    list->doAddSort(0);
    list->doShow();
    cout<<list->doFindByPos(2)->num;
}