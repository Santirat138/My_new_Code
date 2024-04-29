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
        node *nCurr;
        node *nPrev;
        node *nNext;
        node *nullNode;
        linkList();
        void addFirst(int newNum);
        void showList(node *currNode);
        void makeRev();
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    nCurr=NULL;
    nPrev=NULL;
    nNext=NULL;
    nullNode=NULL;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
}
void linkList::showList(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showList(currNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}
void linkList::makeRev(){
    nCurr=head;
    nNext=head->next;
    while(nNext!=NULL){
        nCurr->next=nPrev;
        nPrev=nCurr;
        nCurr=nNext;
        if(nNext->next!=NULL){
            nNext=nNext->next;
        }
        else{
            nCurr->next=nPrev;
            head=nCurr;
            break;
        }
    }
}
//**************************************
int main(){
    linkList *list=new linkList();
    for(int i=0;i<=5;i++){
        list->addFirst(i);
    }
    list->showList(list->head);
    list->makeRev();
    list->showList(list->head);
}
//**************************************
