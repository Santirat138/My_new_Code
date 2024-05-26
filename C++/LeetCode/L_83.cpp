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
//*********** functions ***********
void addFirst(node **headRef, int newNum);
void show(node *currNode);
void removeDup(node *currNode, node *temp);
//*********** main ***********
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(headRef, 5);
    addFirst(headRef, 5);
    addFirst(headRef, 5);
    addFirst(headRef, 5);
    addFirst(headRef, 5);
    addFirst(headRef, 4);
    addFirst(headRef, 2);
    removeDup(head, head->next);
    show(head);
}
//*********** functions ***********
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
void removeDup(node *currNode, node *temp){
    if(temp->next!=NULL){
        if(currNode->num==temp->num){
            temp=temp->next;
        }
        else{
            currNode->next=temp;
            currNode=temp;
        }
        removeDup(currNode, temp);
    }
    else{
        if(currNode->num==temp->num){
            currNode->next=NULL;
        }
    }
}