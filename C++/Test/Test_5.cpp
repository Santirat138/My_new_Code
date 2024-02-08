// Plus linkList
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
        linkList();
        void connectNode(node *n1, node *n2);
        void addLast(int numIn);
        void addFirst(int numIn);
        void showH(node *currNode);
        void showT(node *currNode);
        void showList();
        int countNode(node *currNode, int amount);
};
class plusBox{
    public:
        linkList *list1;
        linkList *list2;
        linkList *listAns;
        plusBox();
        void addNumList1(int numIn);
        void addNumList2(int numIn);
        void showAll();
        void checkList();
        void plusList();
        void showAns();
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
void linkList::addLast(int numIn){
    node *newNode=new node(numIn);
    if(head==NULL){
        head=newNode;
    }
    else{
        connectNode(tail, newNode);
    }
    tail=newNode;
}
void linkList::addFirst(int numIn){
    node *newNode=new node(numIn);
    if(head==NULL){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
}
void linkList::showH(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showH(currNode->next);
    }
}
void linkList::showT(node *currNode){
    if(currNode==NULL){
        cout<<"End."<<endl;
    }
    else{
        cout<<currNode->num<<" ";
        showT(currNode->prev);
    }
}
void linkList::showList(){
    showH(head);
    showT(tail);
    cout<<endl;
}
int linkList::countNode(node *currNode, int amount){
    if(currNode==NULL){
        return amount;
    }
    else{
        return countNode(currNode->next, amount+1);
    }
}
plusBox::plusBox(){
    list1=new linkList();
    list2=new linkList();
    listAns=new linkList();
}
void plusBox::addNumList1(int numIn){
    list1->addLast(numIn);
}
void plusBox::addNumList2(int numIn){
    list2->addLast(numIn);
}
void plusBox::showAll(){
    list1->showList();
    list2->showList();
}
void plusBox::checkList(){
    int amount1;
    int amount2;
    int addAmount;
    do{
        amount1=list1->countNode(list1->head, 0);
        amount2=list2->countNode(list2->head, 0);
        addAmount=amount1-amount2;
        if(addAmount<0){
            list1->addFirst(0);
        }
        else if(addAmount>0){
            list2->addFirst(0);
        }
        else if(addAmount==0){
            break;
        }

    }
    while(addAmount!=0);
}
void plusBox::plusList(){
    checkList();
    node *curr1=list1->tail;
    node *curr2=list2->tail;
    while((curr1!=NULL)&&(curr2!=NULL)){
        listAns->addFirst(curr1->num+curr2->num);
        curr1=curr1->prev;
        curr2=curr2->prev;
    }
}
void plusBox::showAns(){
    listAns->showList();
}
int main(){
    plusBox *box1=new plusBox();
    box1->addNumList1(2);
    box1->addNumList1(4);
    box1->addNumList1(6);
    box1->addNumList2(1);
    box1->addNumList2(3);
    box1->addNumList2(5);
    box1->addNumList2(7);
    box1->addNumList2(9);
    box1->checkList();
    box1->showAll();
    box1->plusList();
    box1->showAns();
}