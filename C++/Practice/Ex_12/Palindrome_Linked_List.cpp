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
        node *goPrev(node *nodeIn);
        void checkPalin();
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
    if(head==NULL){
        head=newNode;
    }
    else{
        tail->next=newNode;
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
node *linkList::goPrev(node *nodeIn){
    node *currNode=head;
    while(currNode!=NULL){
        if(currNode->next==nodeIn){
            return currNode;
        }
        else{
            currNode=currNode->next;
        }
    }
    return NULL;
}
void linkList::checkPalin(){
    node *currNode=head;
    node *checked=tail;
    while(currNode!=NULL){
        if(currNode->num==checked->num){
            currNode=currNode->next;
            checked=goPrev(checked);
            if(currNode==checked){
                cout<<"True"<<endl;
                break;
            }
        }
        else{
            cout<<"False"<<endl;
            break;
        }
    }
}
int main(){
    linkList *list1=new linkList();
    list1->addLast(1);
    list1->addLast(2);
    list1->addLast(1);
    list1->addLast(1);
    list1->addLast(2);
    list1->addLast(5);
    list1->addLast(1);
    list1->showList(list1->head);
    list1->checkPalin();
}