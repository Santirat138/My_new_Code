#include<iostream>
using namespace std;
//---------------- class
class node{
    public:
        int num;
        node *right;
        node(int numIn);
};
node::node(int numIn){
    num=numIn;
    right=NULL;
}
//---------------- functions
void addLast(node **headRef, node **tailRef, int newNum);
void showLL(node *head);
void insertBefore(node **headRef, node **tailRef, int targId, int newNum);
//---------------- main
int main(){
    node *head=NULL;
    node *tail=NULL;
    node **headRef=&head;
    node **tailRef=&tail;
    insertBefore(headRef, tailRef, -1, 1);
    insertBefore(headRef, tailRef, 1, 10);
    insertBefore(headRef, tailRef, 10, 100);
    insertBefore(headRef, tailRef, 5, 10000);
    showLL(head);
}
//---------------- functions
void addLast(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if(*tailRef!=NULL){
        (*tailRef)->right=newNode;
    }
    else{
        *headRef=newNode;
    }
    *tailRef=newNode;
}
void showLL(node *head){
    for(node *currNode=head;currNode!=NULL;currNode=currNode->right){
        cout<<currNode->num<<" ";
    }
    cout<<endl;
}
void insertBefore(node **headRef, node **tailRef, int targId, int newNum){
    node *newNode=new node(newNum);
    if(*headRef==NULL){
        *headRef=newNode;
        *tailRef=newNode;
    }
    else if(targId==(*headRef)->num){
        newNode->right=*headRef;
        *headRef=newNode;
    }
    else{
        bool found=false;
        node *currNode;
        for(currNode=*headRef;currNode->right!=NULL;currNode=currNode->right){
            if(currNode->right->num==targId){
                found=true;
                break;
            }
        }
        if(found){
            newNode->right=currNode->right;
            currNode->right=newNode;
        }
        else if(!found){
            addLast(headRef, tailRef, newNum);
        }
    }
}