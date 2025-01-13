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
void showLL(node *head){
    for(node *curr=head;curr!=NULL;curr=curr->next){
        cout<<curr->num<<" ";
    }
}
void deleteNum(node *head, int targetNum){
    node *currNode=head;
    node *delNode=currNode->next;
    while(true){
        if(delNode->num==currNode->num){
            
        }
    }
}
//------------------ main
int main(){
    node *head=NULL;
    addFirst(&head, 5);
    addFirst(&head, 5);
    addFirst(&head, 5);
    addFirst(&head, 4);
    addFirst(&head, 3);
    addFirst(&head, 2);
    addFirst(&head, 1);
    addFirst(&head, 1);
    addFirst(&head, 1);
    // function delete()
    showLL(head);
}