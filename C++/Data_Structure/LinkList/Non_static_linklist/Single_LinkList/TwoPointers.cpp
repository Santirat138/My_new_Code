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
//************ functions ************
void addFirst(node **headRef, int newNum);
void show(node *currNode);
//************ main ************
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(&head, 1);
    addFirst(headRef, 2);
    show(head);
}
//************ functions ************
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
}
void show(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        show(currNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}