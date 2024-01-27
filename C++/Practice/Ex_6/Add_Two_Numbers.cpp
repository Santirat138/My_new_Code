
#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *prev;
        node *next;
        node(int numIn);
};
class linkList{
    public:
        node *head;
        node *tail;
        int num;
        linkList();
        void connectNode(node *n1, node *n2);
        void setNum(int numIn);
        int countDigi(int numRem, int digi);
        void extNum();
        void addLast(int numIn);
        void showList(node *currNode);
};
class listBox{
    public:
        linkList *lList1;
        linkList *lList2;
        linkList *lListAns;
        listBox(linkList *list1, linkList *list2);
        void plusList();
};
node::node(int numIn){
    num=numIn;
    prev=NULL;
    next=NULL;
}
linkList::linkList(){
    head=NULL;
    tail=NULL;
}
void linkList::connectNode(node *n1, node *n2){
    n1->next=n2;
    n2->prev=n1;
}
void linkList::setNum(int numIn){
    num=numIn;
}
int linkList::countDigi(int numRem, int digi){
    if(numRem==0){
        return digi;
    }
    else{
        return countDigi(numRem/10, digi+1);
    }
}
void linkList::extNum(){
    int digi=countDigi(num, 0);
    int newNum;
    int numRem=num;
    while(digi!=0){
        newNum=numRem%10;
        numRem=numRem/10;
        addLast(newNum);
        digi--;
    }
}
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        connectNode(tail, newNode);
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
listBox::listBox(linkList *list1, linkList *list2){
    lList1=list1;
    lList2=list2;
}
void listBox::plusList(){
    
}
int main(){
    linkList *list1=new linkList();
    list1->setNum(12345);
    list1->extNum();
    list1->showList(list1->head);
}