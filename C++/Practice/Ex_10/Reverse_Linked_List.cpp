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
};
class mainTools{
    public:
        linkList *list1;
        linkList *revList;
        mainTools();
        void inputList(int numIn);
        void show();
        void makeRev();
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
mainTools::mainTools(){
    list1=new linkList();
    revList=new linkList();
}
void mainTools::inputList(int numIn){
    list1->addFirst(numIn);
}
void mainTools::show(){
    list1->showList(list1->head);
    revList->showList(revList->head);
    cout<<endl;
}
void mainTools::makeRev(){
    node *currNode=list1->head;
    while(currNode!=NULL){
        revList->addFirst(currNode->num);
        currNode=currNode->next;
    }
}
int main(){
    mainTools *box1=new mainTools();
    box1->inputList(1);
    box1->inputList(2);
    box1->inputList(3);
    box1->inputList(4);
    box1->makeRev();
    box1->show();
}