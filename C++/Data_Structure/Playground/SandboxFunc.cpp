#include<iostream>
using namespace std;
//**************** node ****************
class node{
    public:
        int num;
        node *left;
        node *right;
        node(int num);
};
node::node(int numIn){
    num=numIn;
    left=NULL;
    right=NULL;
};
node *nullNode=new node(-1);
//**************** functions link list ****************
void addFirst(node **headRef, node **tailRef, int newNum);
void addLast(node **headRef, node **tailRef, int newNum);
void showLL(node *currNode);
node *findPrevNode(node *currNode, node *targNode);
node *findNode(node *currNode, int targNum);
//**************** tree ****************
//**************** main ****************
int main(){
    node *head=NULL;
    node **headRef=&head;
    node *tail=NULL;
    node **tailRef=&tail;

}
//**************** functions link list ****************
void addFirst(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if((*headRef==NULL)&&(*tailRef==NULL)){
        *tailRef=newNode;
    }
    else{
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void addLast(node **headRef, node **tailRef, int newNum){
    node *newNode=new node(newNum);
    if((*headRef==NULL)&&(*tailRef==NULL)){
        *headRef=newNode;
    }
    else{
        (*tailRef)->right=newNode;
    }
    *tailRef=newNode;
}
void showLL(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showLL(currNode->right);
    }
    else{
        cout<<"End. "<<endl;
    }
}
node *findPrevNode(node *currNode, node *targNode){
    if((currNode==NULL)||(currNode->right==NULL)||(targNode==NULL)){
        return nullNode;
    }
    else{
        if(currNode->right==targNode){
            return currNode;
        }
        else{
            return findPrevNode(currNode->right, targNode);
        }
    }
}
node *findNode(node *currNode, int targNum){
    if((currNode==NULL)||(currNode->right==NULL)){
        return nullNode;
    }
    else{
        if(currNode->num==targNum){
            return currNode;
        }
        else{
            return findNode(currNode->right, targNum);
        }
    }
}