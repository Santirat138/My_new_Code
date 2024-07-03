#include<iostream>
using namespace std;
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
//-------------------- functions --------------------
void addFirst(node **headRef, int newNum);
void show(node *currNode);
void deleteNode(node **headRef, node *targNode);
node *findLeftNode(node *head, node *targNode);
//-------------------- main --------------------
int main(){
    node *head=NULL;
    node **headRef=&head;

}
//-------------------- functions --------------------
void addFirst(node **headRef, int newNum){
    node *newNode=new node(newNum);
    if(*headRef!=NULL){
        newNode->right=*headRef;
    }
    *headRef=newNode;
}
void show(node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        show(currNode->right);
    }
    else{
        cout<<"End."<<endl;
    }
}
void deleteNode(node **headRef, node *targNode){
    if((targNode==*headRef)&&(targNode->right==NULL)){
        *headRef=NULL;
    }
    else if((targNode==*headRef)&&(targNode->right!=NULL)){
        *headRef=(*headRef)->right;
        targNode->right=NULL;
    }
    else if((targNode!=*headRef)&&(targNode->right==NULL)){
        
    }
    else if((targNode!=*headRef)&&(targNode->right!=NULL)){

    }
}
node *findLeftNode(node *head, node *targNode){
    node *currNode;
    if(targNode==head){
        currNode=NULL;
    }
    else{
        currNode=head;
        while(currNode->right!=targNode){
            currNode=currNode->right;
        }
    }
    return currNode;
}