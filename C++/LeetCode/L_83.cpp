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
//************** functions **************
void addFirst(node **headRef, int newNum);
void show(node *currNode);
void removeDup(node **headRef);
//************** main **************
int main(){
    node *head=NULL;
    node **headRef=&head;
    addFirst(headRef, 7);
    addFirst(headRef, 6);
    addFirst(headRef, 5);
    addFirst(headRef, 4);
    addFirst(headRef, 4);
    addFirst(headRef, 3);
    addFirst(headRef, 2);
    addFirst(headRef, 2);
    addFirst(headRef, 2);
    addFirst(headRef, 2);
    addFirst(headRef, 1);
    addFirst(headRef, 1);
    addFirst(headRef, 1);
    removeDup(headRef);
    show(head);
}
//************** functions **************
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
void removeDup(node **headRef){
    node *currNode1=*headRef;
    if(currNode1->next!=NULL){
        node *currNode2=currNode1->next;
        while(currNode2->next!=NULL){
            if(currNode1->num==currNode2->num){
                if(currNode2->next->num==currNode1->num){
                    currNode2=currNode2->next;
                }
                else if(currNode2->next->num!=currNode1->num){
                    currNode1->next=currNode2->next;
                    currNode1=currNode2->next;
                    currNode2->next=NULL;
                    currNode2=currNode1->next;
                }
            }
            else if(currNode1->num!=currNode2->num){
                currNode1=currNode2;
                currNode2=currNode2->next;
            }
        }
        if(currNode2->next==NULL){
            if(currNode1->num==currNode2->num){
                currNode1->next=NULL;
            }
        }
    }
    else{
        cout<<"Can't remove."<<endl;
    }
}