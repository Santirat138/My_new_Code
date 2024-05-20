// Make newDataStruct to single link list and use **headRef.
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
node *nullNode=new node(-1);
//***************** functions *****************
void addFirst(node **headRef, node **tailRef, int newNum);
void showLL(node *showNode);
void addLast(node **headRef, node **tailRef, int newNum);
node *findNum(node *currNode, int numIn);
void deleteNum(node *beginNode, int numIn);
//***************** main *****************
int main(){
    node *head=NULL;
    node **headRef=&head;
    node *tail=NULL;
    node **tailRef=&tail;
}
//***************** functions *****************
void addFirst(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if((*headRef!=NULL)&&(*tailRef!=NULL)){
        newNode->next=*headRef;
    }
    else{
        *tailRef=newNode;
    }
    *headRef=newNode;
}
void showLL(node *showNode){
    if(showNode!=NULL){
        cout<<showNode->next<<" ";
        showLL(showNode->next);
    }
    else{
        cout<<"End."<<endl;
    }
}
void addLast(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if((*headRef!=NULL)&&(*tailRef!=NULL)){
        (*tailRef)->next=newNode;
    }
    else{
        *headRef=newNode;
    }
    *tailRef=newNode;
}
node *findNum(node *currNode, int numIn){
    if(currNode!=NULL){
        if(currNode->num==numIn){
            return currNode;
        }
        else{
            return findNum(currNode->next, numIn);
        }
    }
    else{
        return nullNode;
    }
}
void deleteNum(node *beginNode, int numIn){
    node *delNode=findNum(beginNode, numIn);

}