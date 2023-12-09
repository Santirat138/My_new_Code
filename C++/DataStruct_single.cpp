#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;

        node(int numIn){
            num=numIn;
            next=NULL;
        }
};
class linkList{
    public:
        node *head;
        node *nullNode=new node(-1);
        int amount;

        linkList(){
            head=NULL;
            amount=0;
        }
        void addFirst(int newNum);
        void addLast(int newNum);
        void show();
        node *findNode(node *currNode, int walk, int pos);
        node *findNum(node *currNode, int numIn);
        void deleteFirst();
        void deleteLast();
        void insertAt(int newNum, int pos);
        void deleteAt(int pos);
        void swapNum(int num1, int num2);
};
class stack{
    public:
        int amount=0;
        node *top=NULL;
        
        void push(int newNum);
        int pop();
};
void linkList::addFirst(int newNum){
    node *newNode=new node(newNum);
    if(head!=NULL){
        newNode->next=head;
    }
    head=newNode;
    amount++;
}
void linkList::addLast(int newNum){
    node *newNode=new node(newNum);
    if(head==NULL){
        head=newNode;
    }
    else{
        node *lastNode=findNode(head, 0, amount);
        lastNode->next=newNode;
    }
    amount++;
}
void linkList::show(){
    node *startNode=head;
    cout<<"Head --> End."<<endl;
    while(startNode!=NULL){
        cout<<startNode->num<<" ";
        startNode=startNode->next;
    }
    cout<<endl<<endl;
}
node *linkList::findNode(node *currNode, int walk, int pos){
    if((walk>=amount)||(pos>amount)){
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
node *linkList::findNum(node *currNode, int numIn){
    if(currNode==NULL){
        return nullNode;
    }
    else{
        if(currNode->num==numIn){
            return currNode;
        }
        else{
            return findNum(currNode->next, numIn);
        }
    }
}
void linkList::deleteFirst(){
    node *hTemp=head;
    head=head->next;
    hTemp->next=NULL;
    amount--;
}
void linkList::deleteLast(){
    node *lastNode=findNode(head, 0, amount);
    node *prevLast=findNode(head, 0, amount-1);
    prevLast->next=NULL;
}
void linkList::insertAt(int newNum, int pos){
    if(pos<=1){
        addFirst(newNum);
    }
    else if(pos>amount){
        addLast(newNum);
    }
    else{
        node *newNode=new node(newNum);
        node *currNode=findNode(head, 0, pos);
        node *prevNode=findNode(head, 0, pos-1);
        newNode->next=currNode;
        prevNode->next=newNode;
    }
    amount++;
}
void linkList::deleteAt(int pos){
    if(pos<=1){
        deleteFirst();
    }
    else if(pos>=amount){
        deleteLast();
    }
    else{
        node *targetNode=findNode(head, 0, pos);
        node *prevNode=findNode(head, 0, pos-1);
        prevNode->next=targetNode->next;
        targetNode->next=NULL;
    }
    amount--;
}
void linkList::swapNum(int num1, int num2){
    node *node1=findNum(head, num1);
    node *node2=findNum(head, num2);
    node *temp=new node(-1);
    temp->num=node1->num;
    node1->num=node2->num;
    node2->num=temp->num;
}
void stack::push(int newNum){
    node *newNode=new node(newNum);
    if(top!=NULL){
        newNode->next=top;
    }
    top=newNode;
    amount++;
}
int stack::pop(){
    node *temp;
    if(top==NULL){
        temp->num=-1;
    }
    else{
        temp=top;
        top=top->next;
    }
    return temp->num;
}
int main(){
    stack stack1;
    for(int i=0;i<=5;i++){
        stack1.push(i);
    }
    while(stack1.top!=NULL){
        cout<<stack1.pop()<<endl;
    }
}