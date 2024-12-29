#include<iostream>
using namespace std;
//------------------ class node
class node{
    public:
        int num;
        node *next;
        node(int numIn){
            num=numIn;
            next=NULL;
        }
};
//------------------ functions
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->next=*headRef;
    }
    *headRef=newNode;
}
void showLL(node *headIn){
    for(node *curr=headIn;curr!=NULL;curr=curr->next){
        cout<<curr->num<<" ";
    }
}
node *deleteNum(node *headRef, int targetNum){
    for(node *curr=headRef;curr!=NULL;curr=curr->next){
        if(curr->next->num==targetNum){
            node *delNode=curr->next;
            curr->next=delNode->next;
            delNode->next=NULL;
            break;
        }
    }
    return headRef;
}
//------------------ main
int main(){
    node *head=NULL;
    addFirst(&head, 10);
    addFirst(&head, 20);
    showLL(head);
}