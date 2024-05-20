#include<iostream>
using namespace std;
class node{
    public:
        int num;
        node *next;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    next=NULL;
}
//******** functions ********
void addFirst(node **headRef, int newNum);
void makeRev(node **headRef);
void show(node **headRef);
//******** main ********
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(headRef, 1);
    addFirst(headRef, 2);
    addFirst(headRef, 3);
    addFirst(headRef, 4);
    show(headRef);
    makeRev(headRef);
    show(headRef);
}
//******** functions ********
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
}
void makeRev(node **headRef){
    node *prevNode=NULL;
    node *currNode=*headRef;
    node *nextNode=currNode->next;
    while(currNode!=NULL){
        *headRef=nextNode;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
        if(nextNode!=NULL){
            nextNode=nextNode->next;
        }
    }
    *headRef=prevNode;
}
void show(node **headRef){
    node *currNode=*headRef;
    while(currNode!=NULL){
        cout<<currNode->num<<" ";
        currNode=currNode->next;
    }
    cout<<endl;
}