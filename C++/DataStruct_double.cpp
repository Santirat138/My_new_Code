#include<iostream>
using namespace std;
// Function manage with error pos1 and pos2.
class node{
    public:
        int num;
        node *prev;
        node *next;

        node(int numIn){
            num=numIn;
            prev=NULL;
            next=NULL;
        }
};
class linkList{
    public:
        int amount;
        node *nullNode=new node(-1);
        node *head;
        node *tail;

        linkList(){
            amount=0;
            head=NULL;
            tail=NULL;
        }
        void connectNode(node *node1, node *node2);
        void addFirst(int newNum);
        void addLast(int newNum);
        void show();
        node *findNode(node *currNode, int walk, int pos);
        node *findNum(node *currNode, int target);
        void deleteAt(int pos);
        void insertAt(int pos, int newNum);
        void swapNum(int num1, int num2);
        void swapNode(int pos1, int pos2);
};
void linkList::connectNode(node *node1, node *node2){
    node1->next=node2;
    node2->prev=node1;
}
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        tail=newNode;
    }
    else{
        connectNode(newNode, head);
    }
    head=newNode;
    amount++;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if((head==NULL)&&(tail==NULL)){
        head=newNode;
    }
    else{
        connectNode(tail, newNode);
    }
    tail=newNode;
    amount++;
}
void linkList::show(){
    cout<<"Head --> Tail."<<endl;
    node *currNode=head;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    cout<<endl<<"Tail --> Head."<<endl;
    currNode=tail;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->prev;
    }
    cout<<endl<<endl;
}
node *linkList::findNode(node *currNode, int walk, int pos){
    if(currNode==NULL){
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
node *linkList::findNum(node *currNode, int target){
    if(currNode==NULL){
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
void linkList::deleteAt(int pos){
    node *delNode=findNode(head, 0, pos);
    if(delNode!=nullNode){
        if(delNode==head){
            head=delNode->next;
            head->prev=NULL;
            delNode->next=NULL;
        }
        else if(delNode==tail){
            tail=delNode->prev;
            tail->next=NULL;
            delNode->prev=NULL;
        }
        else if((delNode!=head)&&(delNode!=tail)){
            connectNode(delNode->prev, delNode->next);
            delNode->prev=NULL;
            delNode->next=NULL;
        }
        amount--;
    }
    else if(delNode==nullNode){
        cout<<"Can't delete."<<endl;
    }
}
void linkList::insertAt(int pos, int newNum){
    if(pos<=1){
        addFirst(newNum);
    }
    else if(pos>amount){
        addLast(newNum);
    }
    else{
        node *newNode=new node(newNum);
        node *currNode=findNode(head, 0, pos);
        node *prevNode=currNode->prev;
        connectNode(newNode, currNode);
        connectNode(prevNode, newNode);
    }
    amount++;
}
void linkList::swapNum(int num1, int num2){
    node *node1=findNum(head, num1);
    node *node2=findNum(head, num2);
    node *temp=new node(-1);
    temp->num=node1->num;
    node1->num=node2->num;
    node2->num=temp->num;
}
void linkList::swapNode(int pos1, int pos2){

}
int main(){
    linkList list1;
    for(int i=0;i<=5;i++){
        list1.addFirst(i);
    }
    list1.insertAt(2, 50);
    list1.show();
}