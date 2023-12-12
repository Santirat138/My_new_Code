#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;

        node(int newNum){
            num=newNum;
            next=NULL;
        }
};
class cirLinkList{
    public:
        int amount;
        node *nullNode=new node(-1);
        node *head;
        node *tail;

        cirLinkList(){
            amount=0;
            head=NULL;
            tail=NULL;
        }
        void addFirst(int newNum);
        void addLast(int newNum);
        void show();
        node *findNode(node *currNode, int walk, int pos);
        node *findNum(node *currNode, int target);
        void deleteFirst();
        void deleteLast();
        void insertAt(int pos, int newNum);
        void deleteAt(int pos);
};
void cirLinkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        newNode->next=head;
        tail->next=newNode;
    }
    head=newNode;
    amount++;
}
void cirLinkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        newNode->next=head;
        tail->next=newNode;
    }
    tail=newNode;
    tail->next=head;
    amount++;
}
void cirLinkList::show(){
    node *currNode=head;
    while(currNode!=tail){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    cout<<tail->num<<endl<<endl;
}
node *cirLinkList::findNode(node *currNode, int walk, int pos){
    if(walk==amount){
        return nullNode;
    }
    else{
        if(walk==pos-1){
            return currNode;
        }
        else{
            return findNode(currNode->next, walk+1, pos);
        }
    }
}
node *cirLinkList::findNum(node *currNode, int target){
    if((currNode==tail)&&(currNode->num!=target)){
        return nullNode;
    }
    else{
        if(currNode->num==target){
            return currNode;
        }
        else{
            return findNum(currNode->next, target);
        }
    }
}
void cirLinkList::deleteFirst(){
    node *temp=head;
    head=temp->next;
    tail->next=head;
    temp->next=NULL;
    amount--;
}
void cirLinkList::deleteLast(){
    node *temp=tail;
    tail=findNode(head, 0, amount-1);
    tail->next=head;
    temp->next=NULL;
    amount--;
}
void cirLinkList::insertAt(int pos, int newNum){
    node *currNode=findNode(head, 0, pos);
    if(currNode==head){
        addFirst(newNum);
    }
    else if(currNode==tail){
        addLast(newNum);
    }
    else{
        node *newNode=new node(newNum);
        node *prevNode=findNode(head, 0, pos-1);
        newNode->next=currNode;
        prevNode->next=newNode;
    }
    amount++;
}
void cirLinkList::deleteAt(int pos){
    node *targetNode=findNode(head, 0, pos);
    if(targetNode==head){
        deleteFirst();
    }
    else if(targetNode==tail){
        deleteLast();
    }
}
int main(){
    cirLinkList cirLL;
    for(int i=0;i<=5;i++){
        cirLL.addFirst(i);
    }
    cirLL.show();
    cout<<cirLL.findNum(cirLL.head, 3)->num;
}